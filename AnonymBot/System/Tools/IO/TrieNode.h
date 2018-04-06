#pragma once

#include<vector>
#include <QString>

using namespace std;

class TrieNode
{
public:
    TrieNode();
    ~TrieNode();
    QChar content();
    void setContent(const QChar &c);
    int data();
    void setData(const int &data);
    TrieNode* findChild(const QChar &c) const;
    void appendChild(TrieNode* child);
    vector<TrieNode*> children();

private:
    QChar removeAccents(const QChar &c) const;

    QChar m_content;
    int m_marker;
    vector<TrieNode*> m_children;
};
