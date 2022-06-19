#include "codehighlighter.h"
#include <QPlainTextEdit>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>

class CodeEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEdit(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;



private:
    QWidget *lineNumberArea;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrLine();
    void updateLineNumberArea(const QRect &rect, int dy);
};



class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEdit *editor) : QWidget(editor), codeEdit(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEdit->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEdit->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEdit *codeEdit;
};
