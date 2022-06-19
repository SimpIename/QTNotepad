/********************************************************************************
** Form generated from reading UI file 'onexit.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEXIT_H
#define UI_ONEXIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ExitApp
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ExitApp)
    {
        if (ExitApp->objectName().isEmpty())
            ExitApp->setObjectName(QString::fromUtf8("ExitApp"));
        ExitApp->resize(576, 276);
        ExitApp->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(ExitApp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ExitApp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableWidget = new QTableWidget(ExitApp);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget{\n"
"color: black;\n"
"background-color:#FFFFFF;\n"
"selection-background-color: #191970;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"border: none;\n"
"color: black;\n"
"background-color: #B0C4DE;\n"
"gridline-color:#4169E1;\n"
"}"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setShowGrid(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(270);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(ExitApp);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"        background-color: #191970;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(ExitApp);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"        background-color: #191970;\n"
"}"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(ExitApp);

        QMetaObject::connectSlotsByName(ExitApp);
    } // setupUi

    void retranslateUi(QDialog *ExitApp)
    {
        ExitApp->setWindowTitle(QCoreApplication::translate("ExitApp", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ExitApp", " \320\235\320\265\321\201\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213", nullptr));
        okButton->setText(QCoreApplication::translate("ExitApp", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("ExitApp", "\320\235\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExitApp: public Ui_ExitApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEXIT_H
