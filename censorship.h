#ifndef CENSORSHIP_H
#define CENSORSHIP_H

#include <QTextEdit>
#include <QTextBrowser>

class Censorship : public QTextEdit
{
    Q_OBJECT
private:
    QList<QString> *words;
    QTextBrowser *textb;
public:
    Censorship(QTextBrowser *);
    ~Censorship();
    void setWords(const QStringList&);

public slots:
    void append(const QString&);
signals:
    void error(QString);
};


#endif // CENSORSHIP_H
