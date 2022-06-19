#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDomDocument>
#include <QFile>
#include <QFileInfo>

struct HighlightingRule
{
    QRegularExpression pattern;
    QTextCharFormat format;
};

class CodeHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    bool isSupported();
    CodeHighlighter(const QString &suffix,
                QTextDocument *parent=0,
                const QString &style_filename=":/settings.xml");


private:
    QTextCharFormat CommentsMulti;
    QRegularExpression commentStart;
    QRegularExpression commentEnd;
    QVector<HighlightingRule> Rul;
    bool supported;

protected:
    void highlightBlock(const QString &text) override;

};

#endif

