#include "censorship.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

void configTextBrowser(Censorship *Censorship, QStringList list) {
    Censorship->setWords(list);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Цензура");

    QStringList list;
    list << "сессия" << "комиссия" << "пересдача" << "дедлайн" << "ИУП";

    QVBoxLayout *box = new QVBoxLayout;
    QTextBrowser *textb = new QTextBrowser;
    Censorship *censor = new Censorship(textb);
    configTextBrowser(censor, list);

    QLineEdit *line = new QLineEdit;
    QPushButton *btn = new QPushButton("Отправить сообщение");
    QLabel *log = new QLabel;

    QObject::connect(btn, &QPushButton::clicked, censor, [=]() {
        log->clear();
        censor->append(line->text());
        line->clear();
    });


    QObject::connect(censor, SIGNAL(error(QString)), log, SLOT(setText(QString)));

    box->addWidget(log);
    box->addWidget(textb);
    box->addWidget(line);
    box->addWidget(btn);

    window.setLayout(box);
    window.show();
    return a.exec();
}
