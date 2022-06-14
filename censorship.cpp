#include "censorship.h"

Censorship::Censorship(QTextBrowser *textb) {
    this->textb = textb;
    this->textb->setReadOnly(true);
    words = new QList<QString>();
}
void Censorship::append(const QString &text) {
    for(int i = 0; i < words->size(); i++) {
        if(text.contains(words->at(i), Qt::CaseInsensitive)) {
            emit error("Слово \"" + words->at(i) + "\" использовать нельзя");
            return;
        }
    }
    textb->append(text);
}
void Censorship::setWords(const QStringList &listWords) {
    for(int i = 0; i < listWords.size(); i++) {
        words->push_back(listWords.at(i));
    }
}
Censorship::~Censorship() {
    delete words;
}
