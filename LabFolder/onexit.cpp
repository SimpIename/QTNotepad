#include "onexit.h"
#include "ui_onexit.h"
#include <QPushButton>

ExitApp::ExitApp(QStringList* nameFiles, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::ExitApp)
{
    ui->setupUi(this);
    setModal(true);
    this->setWindowTitle(tr("Сохранение изменений"));
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(nameFiles->count());
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Имя") << tr("Путь") );

    for (int i = 0; i < nameFiles->count(); ++i) {
        QFileInfo file(nameFiles->at(i));
        QTableWidgetItem* column1 = new QTableWidgetItem(file.fileName());
        QTableWidgetItem* column2 = new QTableWidgetItem(file.absolutePath());
        ui->tableWidget->setItem(i,0,column1);
        ui->tableWidget->setItem(i,1,column2);
    }


    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setStyleSheet("color: black;");

    setStyleSheet("background-color:  #B0C4DE;");

    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(on_pushButtons()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(on_pushButtons()));
}

ExitApp::~ExitApp()
{
    delete ui;
}

void ExitApp::on_pushButtons()
{
    QPushButton* button=qobject_cast<QPushButton*>(sender());
    if(button==nullptr) {
        done(0);
        close();
        return;
    }
    if(button->text()==tr("Сохранить")){
        done(1);
        close();
        return;
    }
    if(button->text()==tr("Не сохранять")){
        done(2);
        close();
        return;
    }
    done(0);
    close();
    return;
}


