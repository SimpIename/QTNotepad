#include "notepad.h"
#include "ui_notepad.h"
#include "onexit.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Text edit"));
    ui->newFileAction->setIcon(QPixmap(":/images/new.jpg"));
    ui->openFileAction->setIcon(QPixmap(":/images/open.png"));
    ui->saveFileAction->setIcon(QPixmap(":/images/save.png"));
    ui->saveAllAction->setIcon(QPixmap(":/images/saveAll.png"));

    ui->menubar->setStyleSheet("color: rgb(255, 255, 255);");



    ui->newFileAction->setShortcut(QKeySequence("CTRL+N"));
    ui->openFileAction->setShortcut(QKeySequence("CTRL+O"));
    ui->saveFileAction->setShortcut(QKeySequence("CTRL+S"));
    ui->saveAllAction->setShortcut(QKeySequence("CTRL+SHIFT+S"));
    ui->saveFileAsAction->setShortcut(QKeySequence("CTRL+ALT+S"));
    ui->closeFileAction->setShortcut(QKeySequence("CTRL+W"));
    ui->closeAllAction->setShortcut(QKeySequence("CTRL+SHIFT+W"));
    ui->exitAction->setShortcut(QKeySequence("CTRL+Q"));

    ui->selectAllAction->setShortcut(QKeySequence("CTRL+A"));
    ui->copyAction->setShortcut(QKeySequence("CTRL+C"));
    ui->pasteAction->setShortcut(QKeySequence("CTRL+V"));
    ui->cutAction->setShortcut(QKeySequence("CTRL+X"));
    bar = new QToolBar(this);
    bar->addAction(ui->newFileAction);
    bar->addAction(ui->openFileAction);
    bar->addAction(ui->saveFileAction);
    bar->addAction(ui->saveAllAction);
    addToolBar(Qt::TopToolBarArea, bar);


    createDockWidgets();

}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::createDockWidgets()
{
    listViewer=new QListView(this);
    listViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listViewer->setModel(stringList);
    listViewer->setMinimumWidth(80);






    listViewer->setStyleSheet("QListView {color:white; background: #B0C4DE;} ");
    connect(listViewer,SIGNAL(clicked(QModelIndex)),this,SLOT(currentTab(QModelIndex)));
    openDocs=new QDockWidget(tr("Открытые файлы"),this);
    addDockWidget(Qt::RightDockWidgetArea,openDocs);
    openDocs->setWidget(listViewer);
    openDocs->setStyleSheet("QDockWidget {color:white; background: #191970;}");







    fileSys = new QFileSystemModel(this);
    fileSys->setRootPath(QDir::currentPath());

    fileExplorer=new QDockWidget(tr("Проводник"),this);
    addDockWidget(Qt::LeftDockWidgetArea,fileExplorer);
    QTreeView *treeView = new QTreeView(this);
    treeView->setModel(fileSys);
    treeView->setMinimumWidth(80);
    fileExplorer->setWidget(treeView);


    fileExplorer->setStyleSheet("background-color: #B0C4DE ; color: black;");

    treeView->setStyleSheet("QHeaderView::section { color: white; background-color: #191970; gridline-color: #191970; }");

    connect(treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(loadCurrentFile(QModelIndex)));


}


void Notepad::changeDoc(){
    if (!(ui->mainWidget->tabText(ui->mainWidget->currentIndex())).contains("*")){
        ui->mainWidget->setTabWhatsThis(ui->mainWidget->currentIndex(), "Изменения внесены");
        ui->mainWidget->setTabText(ui->mainWidget->currentIndex(), ui->mainWidget->tabText(ui->mainWidget->currentIndex()) + "*");
    }
    updateOpenDocs();
}

void Notepad::updateOpenDocs()
{

        stringList=new QStringListModel(this);
        QStringList list;
        for(int i = 0;i < ui->mainWidget->count(); ++i){
            list.push_back(ui->mainWidget->tabText(i));
        }
        stringList->setStringList(list);
        listViewer->setModel(stringList);
        listViewer->reset();

}

void Notepad::closeEvent(QCloseEvent *closeEvent)
{
    QStringList listNoSaveFiles;
    for(int i=0;i<ui->mainWidget->count();++i){
        ui->mainWidget->setCurrentIndex(i);
        if (ui->mainWidget->tabWhatsThis(i) != "Изменений нет") {
            if(ui->mainWidget->currentWidget()->property("path")==QVariant())
                listNoSaveFiles.push_back(ui->mainWidget->tabText(ui->mainWidget->currentIndex()));
            else{
                QFile file(ui->mainWidget->currentWidget()->property("path").toString());
                if(file.open(QIODevice::ReadOnly)){
                    QString text=file.readAll();
                    CodeEdit* page=static_cast<CodeEdit*>(ui->mainWidget->currentWidget());
                    if(page->toPlainText()!=text) listNoSaveFiles.push_back(ui->mainWidget->currentWidget()->property("path").toString());
                }
                else QMessageBox::critical(this, tr("Ошибка"), tr("Не получается открыть файл: ")
                                                                        + ui->mainWidget->tabText(ui->mainWidget->currentIndex()) + "\n" + file.errorString());
            }
        }
    }
    if (listNoSaveFiles.count()!=0) {
        ExitApp* exitApp_window=new ExitApp(&listNoSaveFiles);
        int resultExitWindow=exitApp_window->exec();
        if(resultExitWindow==1){
            QWidget* widget=ui->mainWidget->currentWidget();
            for(int a=0;a<ui->mainWidget->count();++a){
                ui->mainWidget->setCurrentIndex(a);
                on_saveFileAction_triggered();
            }
            ui->mainWidget->setCurrentWidget(widget);
        }
        if (resultExitWindow==1 || resultExitWindow==2) closeEvent->accept();
        else closeEvent->ignore();
    }
}


bool Notepad::dialogWindow()
{
    QMessageBox message;
    QPushButton *save = message.addButton(tr("Сохранить"), QMessageBox::ActionRole);
    QPushButton *cancel = message.addButton(tr("Отмена"), QMessageBox::ActionRole);
    QPushButton *notSave = message.addButton(tr("Не сохранять"), QMessageBox::ActionRole);
    save->setStyleSheet("QPushButton{ color: black; background-color:  #4169E1; }");
    notSave->setStyleSheet("QPushButton{ color: black; background-color:  #4169E1; }");
    cancel->setStyleSheet("QPushButton{ color: black; background-color:  #4169E1; }");
    Q_UNUSED(notSave);
    message.setWindowTitle(tr("Сохранение изменений"));
    message.setIcon(QMessageBox::Warning);
    message.setStyleSheet("background-color: #1E90FF; color: black;");
    message.setText(tr("Файл ") + ui->mainWidget->tabText(ui->mainWidget->currentIndex()) + tr(" не сохранён."));
    message.setInformativeText(tr("Хотите сохранить его?"));
    message.exec();
    if ((QPushButton*)(message.clickedButton())==save) {
        on_saveFileAction_triggered();
    }
    if ((QPushButton*)(message.clickedButton())==cancel) {
        return false;
    }
    return true;
}

void Notepad::loadCurrentFile(QModelIndex index)
{
    if (!fileSys->isDir(index)) {
        QFile file(fileSys->filePath(index));
        if (file.open(QIODevice::ReadOnly)) {
            bool openingFile=false;

            for(int i = 0; i < ui->mainWidget->count(); ++i) {
                if(ui->mainWidget->tabText(i)==fileSys->fileName(index)) openingFile=true;
            }
            if(!openingFile){
               QString textFile=file.readAll();
               CodeEdit* editor = new CodeEdit(this);
               QString extension = QFileInfo(fileSys->fileName(index)).suffix();
               if (!extension.isEmpty()){
                   highlighter = new CodeHighlighter(extension, editor->document());
                   if (!highlighter->isSupported())
                       delete highlighter;
               }

               editor->setProperty("path",fileSys->filePath(index));
               editor->appendPlainText(textFile);

               QFileInfo fileInfo(fileSys->filePath(index));
               int ind = ui->mainWidget->addTab(editor,fileInfo.fileName());
               ui->mainWidget->setTabWhatsThis(ind, "Изменений нет");

               connect(editor,SIGNAL(textChanged()),this,SLOT(changeDoc()));
            }
            else QMessageBox::critical(this, tr("Ошибка"), tr("Файл с таким именем уже открыт"));
        }
        else QMessageBox::critical(this, tr("Ошибка"), tr("Не получается открыть файл: ") +
                                   fileSys->fileName(index) + "\n" + file.errorString());
    }
    updateOpenDocs();
}

void Notepad::on_newFileAction_triggered()
{
    ++numberOfFiles;
    CodeEdit* editor = new CodeEdit(this);
    QString newDoc = "Новый документ " + QString::number(numberOfFiles);
    int ind = ui->mainWidget->addTab(editor, newDoc);
    ui->mainWidget->setTabWhatsThis(ind, "Изменений нет");

    updateOpenDocs();
    connect(editor,SIGNAL(textChanged()),this,SLOT(changeDoc()));
}

void Notepad::on_openFileAction_triggered()
{
    QStringList nameFiles=QFileDialog::getOpenFileNames(this,tr("Открыть файл(-ы)"),"","");
    for(auto nameFile: nameFiles){
        QFile file(nameFile);
        if(file.open(QIODevice::ReadOnly)){
            bool openingFile=false;
            for (int i = 0; i < ui->mainWidget->count(); ++i){
                if (ui->mainWidget->tabText(i)==QFileInfo(nameFile).fileName()) openingFile=true;
            }
            if(!openingFile){
               QString textFile=file.readAll();
               CodeEdit* editor = new CodeEdit(this);

               QString extension = QFileInfo(nameFile).suffix();
               if (!extension.isEmpty()){
                   highlighter = new CodeHighlighter(extension, editor->document());
                   if (!(highlighter->isSupported()))
                       delete highlighter;
               }
               editor->setProperty("path",nameFile);
               editor->appendPlainText(textFile);

               QFileInfo fileInfo(nameFile);
               int ind = ui->mainWidget->addTab(editor,fileInfo.fileName());
               ui->mainWidget->setTabWhatsThis(ind, "Изменений нет");


               connect(editor,SIGNAL(textChanged()),this,SLOT(changeDoc()));
            }
            else QMessageBox::critical(this, tr("Ошибка"), tr("Файл с таким именем уже открыт"));
        }
        else QMessageBox::critical(this, tr("Ошибка"), tr("Не получается открыть файл: ") + nameFile + "\n" + file.errorString());
    }
    updateOpenDocs();

}


void Notepad::on_saveFileAsAction_triggered()
{
    QFileDialog fileDialog(this);
    fileDialog.setWindowTitle(tr("Сохранить ")+ui->mainWidget->tabText(ui->mainWidget->currentIndex()).remove("*")+ tr(" как..."));
    fileDialog.setFileMode(QFileDialog::AnyFile);
    QString fileName=QFileDialog::getSaveFileName(this,tr("Сохранить ") + ui->mainWidget->tabText(ui->mainWidget->currentIndex()).remove("*")
                                                  + tr(" как..."), ui->mainWidget->tabText(ui->mainWidget->currentIndex()),tr("Все файлы"));
    QFile file(fileName);
    CodeEdit* page=static_cast<CodeEdit*>(ui->mainWidget->currentWidget());

    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream << page->toPlainText();
        QFileInfo fileInfo(fileName);
        ui->mainWidget->setTabText(ui->mainWidget->currentIndex(),fileInfo.fileName());
    } else {
        QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно сохранить файл: ") + fileName + "  \n" + file.errorString());
    }
    ui->mainWidget->setTabWhatsThis(ui->mainWidget->currentIndex(), "Изменений нет");
    updateOpenDocs();
}

void Notepad::on_saveAllAction_triggered()
{
    QWidget* curWidget = ui->mainWidget->currentWidget();
    for(int i = 0; i < ui->mainWidget->count(); ++i){
        ui->mainWidget->setCurrentIndex(i);
        if (ui->mainWidget->tabWhatsThis(ui->mainWidget->currentIndex()) != "Изменений нет") {
            on_saveFileAction_triggered();
        }
    }
    ui->mainWidget->setCurrentWidget(curWidget);
}


void Notepad::on_saveFileAction_triggered()
{
    if(ui->mainWidget->currentWidget()->property("path")!=QVariant()){
        CodeEdit* page = static_cast<CodeEdit*>(ui->mainWidget->currentWidget());
        QFile file(ui->mainWidget->currentWidget()->property("path").toString());
        if(file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            stream << page->toPlainText();
            ui->mainWidget->setTabText(ui->mainWidget->currentIndex(), ui->mainWidget->tabText(ui->mainWidget->currentIndex()).remove("*"));
            ui->mainWidget->setTabWhatsThis(ui->mainWidget->currentIndex(), "Изменений нет");
        } else {
            QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно сохранить файл: ") +
                                                          ui->mainWidget->tabText(ui->mainWidget->currentIndex()) + "  \n" + file.errorString());
        }
    } else {
        on_saveFileAsAction_triggered();
    }
}



void Notepad::on_closeAllAction_triggered()
{
    int count = ui->mainWidget->count();
    int index = 0;
    for (int i = 0 ; i < count ; i++) {
          ui->mainWidget->setCurrentIndex(index);
          if (!on_closeFileAction_triggered())
            ++index;
    }
}

void Notepad::on_exitAction_triggered()
{
    close();
}

void Notepad::on_cutAction_triggered()
{
    CodeEdit* textEdit =  qobject_cast<CodeEdit*> (ui->mainWidget->currentWidget());
    textEdit->cut();
}

void Notepad::on_copyAction_triggered()
{
    CodeEdit* textEdit =  qobject_cast<CodeEdit*> (ui->mainWidget->currentWidget());
    textEdit->copy();
}

bool Notepad::on_closeFileAction_triggered()
{
    bool close = true;
    if (ui->mainWidget->tabWhatsThis(ui->mainWidget->currentIndex()) != "Изменений нет") {
        if (ui->mainWidget->currentWidget()->property("path")==QVariant()) {
            close = dialogWindow();
        }
        else {
            QFile file(ui->mainWidget->currentWidget()->property("path").toString());
            if (file.open(QIODevice::ReadOnly)){
                QString text = file.readAll();
                CodeEdit* page=static_cast<CodeEdit*>(ui->mainWidget->currentWidget());
                if (page->toPlainText()!=text) close = dialogWindow();
            } else {
                QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно сохранить файл: ") +
                                                                    ui->mainWidget->tabText(ui->mainWidget->currentIndex()).remove("*") +" \n" + file.errorString());
            }
        }
    }
    if (close) {
        ui->mainWidget->currentWidget()->close();
        ui->mainWidget->removeTab(ui->mainWidget->currentIndex());
    }

    updateOpenDocs();
    return close;
}




void Notepad::on_fileExplorer_visibilityChanged(bool visible) {
    ui->showFileExplorer->setChecked(visible);
}

void Notepad::on_openDocs_visibilityChanged(bool visible) {
    ui->showOpenDocs->setChecked(visible);
}

void Notepad::on_showFileExplorer_triggered(bool visible)
{
    connect(fileExplorer, SIGNAL(visibilityChanged(bool)), this, SLOT(on_fileExplorer_visibilityChanged(bool)));
    if (visible) {
       fileExplorer->show();
    } else {
       fileExplorer->close();
    }
}



void Notepad::currentTab(QModelIndex index){
    ui->mainWidget->setCurrentIndex(index.row());
}

void Notepad::on_pasteAction_triggered()
{
    CodeEdit* textEdit =  qobject_cast<CodeEdit*> (ui->mainWidget->currentWidget());
    textEdit->paste();
}

void Notepad::on_deleteAction_triggered()
{
    CodeEdit* textEdit =  qobject_cast<CodeEdit*> (ui->mainWidget->currentWidget());
    textEdit->clear();
}

void Notepad::on_selectAllAction_triggered()
{
    CodeEdit* textEdit =  qobject_cast<CodeEdit*> (ui->mainWidget->currentWidget());
    textEdit->selectAll();
}

void Notepad::on_mainWidget_tabCloseRequested(int index)
{
    QWidget* curWidget = ui->mainWidget->currentWidget();
    ui->mainWidget->setCurrentIndex(index);
    on_closeFileAction_triggered();
    ui->mainWidget->setCurrentWidget(curWidget);
}

void Notepad::on_showOpenDocs_triggered(bool visible)
{
    connect(openDocs, SIGNAL(visibilityChanged(bool)), this, SLOT(on_openDocs_visibilityChanged(bool)));
    if (visible) {
        stringList = new QStringListModel(this);
        QStringList list;
        for(int i = 0; i < ui->mainWidget->count(); ++i){
            list.push_back(ui->mainWidget->tabText(i));
        }
        stringList->setStringList(list);
        updateOpenDocs();
        openDocs->show();
    } else {
        openDocs->close();
    }
}
