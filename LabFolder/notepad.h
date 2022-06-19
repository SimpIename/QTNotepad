#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "codehighlighter.h"
#include "codeedit.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QTabWidget>
#include <QDir>
#include <QString>
#include <QVector>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>
#include <QDir>
#include <QDialog>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QWidgetItem>
#include <QToolBar>
#include <QIcon>
#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent * closeEvent) override;

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();
    
private slots:



    void on_mainWidget_tabCloseRequested(int index);
    void changeDoc();
    void updateOpenDocs();
    bool dialogWindow();
    void loadCurrentFile(QModelIndex index);
    void currentTab(QModelIndex index);

    void createDockWidgets();

    void on_fileExplorer_visibilityChanged(bool visible);
    void on_openDocs_visibilityChanged(bool visible);

    void on_openFileAction_triggered();
    void on_saveFileAction_triggered();
    void on_saveFileAsAction_triggered();
    void on_newFileAction_triggered();
    void on_saveAllAction_triggered();
    void on_pasteAction_triggered();
    void on_deleteAction_triggered();
    void on_selectAllAction_triggered();
    bool on_closeFileAction_triggered();
    void on_closeAllAction_triggered();
    void on_copyAction_triggered();
    void on_showFileExplorer_triggered(bool visible);
    void on_showOpenDocs_triggered(bool visible);
    void on_exitAction_triggered();
    void on_cutAction_triggered();
private:
    Ui::Notepad *ui;
    QDockWidget* openDocs;
    QDockWidget* fileExplorer;

    int numberOfFiles=0;
    QToolBar* bar;
    QListView* listViewer;
    CodeHighlighter* highlighter;
    QFileSystemModel *fileSys = Q_NULLPTR;
    QStringListModel* stringList = Q_NULLPTR;

};
#endif // NOTEPAD_H
