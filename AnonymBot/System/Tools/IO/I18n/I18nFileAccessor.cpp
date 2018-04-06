#include "I18nFileAccessor.h"

I18nFileAccessor::I18nFileAccessor(const QString &path):
    m_path(path)
{
    m_reader = new Reader(m_path);

    int pos = m_reader->readInt();
    m_reader->setPosition(pos);
    int plus = 0;

    int indexesCount = m_reader->readInt();
    for (int i = 0; i < indexesCount; i += 9+plus)
    {
        int index = m_reader->readInt();
        bool readMore = m_reader->readBool();
        int offset = m_reader->readInt();

        if (readMore)
            plus = 4;

        else
            plus = 0;

        m_reader->setPosition(m_reader->getPosition()+plus);

        m_indexes[index] = offset;
    }

    int i = m_reader->readInt();
    while(i > 0)
    {
        int oldPos = m_reader->getPosition();
        QString index = m_reader->readUTF();
        int offset = m_reader->readInt();
        m_textIndexes[index] = offset;
        i -= m_reader->getPosition() - oldPos;
    }
}

I18nFileAccessor::~I18nFileAccessor()
{
    delete m_reader;
}

bool I18nFileAccessor::indexExist(const QString &index)
{
    return m_textIndexes.find(index) != m_textIndexes.end();
}

bool I18nFileAccessor::indexExist(int index)
{
    return m_indexes.contains(index);
}

QString I18nFileAccessor::getText(int index)
{
    int pos = m_indexes[index];
    m_reader->setPosition(pos);
    return m_reader->readUTF();
}

QString I18nFileAccessor::getText(const QString &index)
{
    int pos = m_textIndexes[index];
    m_reader->setPosition(pos);
    return m_reader->readUTF();
}
