#ifndef ONEXIT_H
#define ONEXIT_H

#include "notepad.h"
#include <QDialog>
#include <QFileInfo>

namespace Ui {
class ExitApp;
}

class ExitApp : public QDialog
{
    Q_OBJECT

public:
    explicit ExitApp(QStringList* nameFiles, QWidget* parent=nullptr);
    ~ExitApp();

private slots:
    void on_pushButtons();

private:
    Ui::ExitApp *ui;
};

#endif // ONEXIT_H
