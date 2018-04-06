#include "TrieNode.h"

TrieNode::TrieNode(): m_content(' '), m_marker(-1)
{}

TrieNode::~TrieNode()
{}

QChar TrieNode::content()
{
    return m_content;
}

void TrieNode::setContent(const QChar &c)
{
    m_content = c;
}

int TrieNode::data()
{
    return m_marker;
}

void TrieNode::setData(const int &data)
{
    m_marker = data;
}

TrieNode* TrieNode::findChild(const QChar &c) const
{
    for ( int i = 0; i < m_children.size(); i++ )
    {
        TrieNode* tmp = m_children.at(i);
        if (removeAccents(tmp->content().toLower()).toLatin1() == removeAccents(c.toLower()).toLatin1())
        {
            return tmp;
        }
    }

    return NULL;
}

void TrieNode::appendChild(TrieNode* child)
{
    m_children.push_back(child);
}

vector<TrieNode*> TrieNode::children()
{
    return m_children;
}


QChar TrieNode::removeAccents(const QChar &c) const
{
    static QString tr = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";

    if((uchar)c.toLatin1() >= 192)
        return tr[(uchar)c.toLatin1() - 192];

    else
        return c;
}
