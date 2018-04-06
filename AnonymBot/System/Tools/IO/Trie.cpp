#include "Trie.h"
#include <iostream>
Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    delete root;
}

void Trie::addWord(const QString &s, const uint &data)
{
    TrieNode* current = root;

    if ( s.length() == 0 )
    {
        current->setData(-1);
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {
        TrieNode* child = current->findChild(s[i]);
        if ( child != NULL )
            current = child;

        else
        {
            TrieNode* tmp = new TrieNode();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setData(data);
    }
}


int Trie::searchWord(const QString &s)
{
    TrieNode* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            TrieNode* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return -1;
            current = tmp;
        }

        return current->data();
    }

    return -1;
}


QStringList Trie::autoComplete(const QString &s)
{
    QTime a;
    a.start();
    TrieNode *current=root;
    QStringList res;
    QString c;

    if(s.isEmpty())
    {
        emit autoCompleteResults(QStringList());
        return QStringList();
    }

    for ( int i = 0; i < s.length(); i++ )
    {
        TrieNode* tmp = current->findChild(s[i]);
        if ( tmp == NULL )
        {
            emit autoCompleteResults(res);
            return res;
        }

        current = tmp;
        c += tmp->content();
    }

    bool loop=true;
    parseTree(current,c,res,loop);
    emit autoCompleteResults(res);
    return res;
}

void Trie::parseTree(TrieNode *current, QString &s, QStringList &res, bool& loop)
{
    QString k;
    if(loop)
    {
        if(current!=NULL)
        {
            if(current->data() != -1){
                res.push_back(s);
                if(res.size()>15)
                    loop=false;
            }
            vector<TrieNode *> child=current->children();
            for(int i=0;i<child.size() && loop;i++){
                k = s;
                k.append(child[i]->content());
                if(loop)
                    parseTree(child[i],k,res,loop);
            }

        }
    }
}

void Trie::clear()
{
    delete root;
    root = new TrieNode();
}
