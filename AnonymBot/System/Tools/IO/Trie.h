#pragma once
#include <QString>
#include <QStringList>
#include <QDebug>
#include "TrieNode.h"
#include <QThread>
#include <QTime>

class Trie: public QObject
{

    Q_OBJECT

public:
    Trie();
    ~Trie();

    void parseTree(TrieNode *current, QString &s, QStringList&, bool &loop);
    void clear();

public slots:
    void addWord(const QString &s, const uint &data);
    int searchWord(const QString &s);
    QStringList autoComplete(const QString &s);

signals:
    void autoCompleteResults(QStringList);

private:
    TrieNode* root;
};
