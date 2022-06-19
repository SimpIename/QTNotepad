/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *newFileAction;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *saveFileAsAction;
    QAction *saveAllAction;
    QAction *closeFileAction;
    QAction *closeAllAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectAllAction;
    QAction *showFileExplorer;
    QAction *showOpenDocs;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *mainWidget;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QString::fromUtf8("Notepad"));
        Notepad->resize(1069, 630);
        Notepad->setStyleSheet(QString::fromUtf8("Notepad{\n"
"background-color:#B0C4DE ;\n"
"}\n"
"\n"
"QMenuBar {\n"
"background-color: #4169E1;\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background:#191970;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"background: #191970;\n"
"}\n"
"\n"
"QMenu {\n"
"background-color: #191970;\n"
"}"));
        newFileAction = new QAction(Notepad);
        newFileAction->setObjectName(QString::fromUtf8("newFileAction"));
        openFileAction = new QAction(Notepad);
        openFileAction->setObjectName(QString::fromUtf8("openFileAction"));
        saveFileAction = new QAction(Notepad);
        saveFileAction->setObjectName(QString::fromUtf8("saveFileAction"));
        saveFileAsAction = new QAction(Notepad);
        saveFileAsAction->setObjectName(QString::fromUtf8("saveFileAsAction"));
        saveAllAction = new QAction(Notepad);
        saveAllAction->setObjectName(QString::fromUtf8("saveAllAction"));
        closeFileAction = new QAction(Notepad);
        closeFileAction->setObjectName(QString::fromUtf8("closeFileAction"));
        closeAllAction = new QAction(Notepad);
        closeAllAction->setObjectName(QString::fromUtf8("closeAllAction"));
        exitAction = new QAction(Notepad);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        cutAction = new QAction(Notepad);
        cutAction->setObjectName(QString::fromUtf8("cutAction"));
        copyAction = new QAction(Notepad);
        copyAction->setObjectName(QString::fromUtf8("copyAction"));
        pasteAction = new QAction(Notepad);
        pasteAction->setObjectName(QString::fromUtf8("pasteAction"));
        deleteAction = new QAction(Notepad);
        deleteAction->setObjectName(QString::fromUtf8("deleteAction"));
        selectAllAction = new QAction(Notepad);
        selectAllAction->setObjectName(QString::fromUtf8("selectAllAction"));
        showFileExplorer = new QAction(Notepad);
        showFileExplorer->setObjectName(QString::fromUtf8("showFileExplorer"));
        showFileExplorer->setCheckable(true);
        showFileExplorer->setChecked(true);
        showFileExplorer->setEnabled(true);
        showOpenDocs = new QAction(Notepad);
        showOpenDocs->setObjectName(QString::fromUtf8("showOpenDocs"));
        showOpenDocs->setCheckable(true);
        showOpenDocs->setChecked(true);
        showOpenDocs->setEnabled(true);
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainWidget = new QTabWidget(centralwidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"border: 1px;\n"
"background-color:#FFFFFF;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"background-color: rgb(255,255,255);\n"
"min-width: 20ex;\n"
"min-height: 6ex;\n"
"margin-left: 1px;\n"
"left: -1px\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"background-color: rgb(255,255,255);\n"
"}\n"
"\n"
""));
        mainWidget->setTabsClosable(true);

        gridLayout->addWidget(mainWidget, 0, 0, 1, 1);

        Notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1069, 20));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        editMenu = new QMenu(menubar);
        editMenu->setObjectName(QString::fromUtf8("editMenu"));
        viewMenu = new QMenu(menubar);
        viewMenu->setObjectName(QString::fromUtf8("viewMenu"));
        Notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Notepad->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(editMenu->menuAction());
        menubar->addAction(viewMenu->menuAction());
        fileMenu->addAction(newFileAction);
        fileMenu->addAction(openFileAction);
        fileMenu->addAction(saveFileAction);
        fileMenu->addAction(saveFileAsAction);
        fileMenu->addAction(saveAllAction);
        fileMenu->addAction(closeFileAction);
        fileMenu->addAction(closeAllAction);
        fileMenu->addAction(exitAction);
        editMenu->addAction(cutAction);
        editMenu->addAction(copyAction);
        editMenu->addAction(pasteAction);
        editMenu->addAction(deleteAction);
        editMenu->addAction(selectAllAction);
        viewMenu->addAction(showFileExplorer);
        viewMenu->addAction(showOpenDocs);

        retranslateUi(Notepad);

        mainWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "Notepad", nullptr));
        newFileAction->setText(QCoreApplication::translate("Notepad", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        openFileAction->setText(QCoreApplication::translate("Notepad", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveFileAction->setText(QCoreApplication::translate("Notepad", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        saveFileAsAction->setText(QCoreApplication::translate("Notepad", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        saveAllAction->setText(QCoreApplication::translate("Notepad", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        closeFileAction->setText(QCoreApplication::translate("Notepad", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        closeAllAction->setText(QCoreApplication::translate("Notepad", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\262\321\201\321\221", nullptr));
        exitAction->setText(QCoreApplication::translate("Notepad", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        cutAction->setText(QCoreApplication::translate("Notepad", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", nullptr));
        copyAction->setText(QCoreApplication::translate("Notepad", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pasteAction->setText(QCoreApplication::translate("Notepad", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteAction->setText(QCoreApplication::translate("Notepad", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        selectAllAction->setText(QCoreApplication::translate("Notepad", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        showFileExplorer->setText(QCoreApplication::translate("Notepad", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272", nullptr));
        showOpenDocs->setText(QCoreApplication::translate("Notepad", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\276\320\261\320\276\320\267\321\200\320\265\320\262\320\260\321\202\320\265\320\273\321\214 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\321\205 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262 ", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("Notepad", "\320\244\320\260\320\271\320\273", nullptr));
        editMenu->setTitle(QCoreApplication::translate("Notepad", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        viewMenu->setTitle(QCoreApplication::translate("Notepad", "\320\222\320\270\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
