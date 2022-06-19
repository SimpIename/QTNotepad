#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad myNotepad;
    myNotepad.show();
    return a.exec();
}
