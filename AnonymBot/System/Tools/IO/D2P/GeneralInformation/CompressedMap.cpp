#include "CompressedMap.h"

CompressedMap::CompressedMap(Reader *reader, const QString &path) :
    m_path(path),
    m_isInvalidMap(false),
    m_mapId(0)
{
    m_indexName = reader->readUTF();
    if (m_indexName == "link" || m_indexName == "")
    {
        m_isInvalidMap = true;
        return;
    }

    m_offset = reader->readUInt() + 2;
    m_byteCount = reader->readUInt();

    int i = 0;
    for (i = 0; i < m_indexName.size(); i++)
    {
        if (m_indexName[i] == '/')
            break;
    }

    m_mapId = toUInt(m_indexName.mid(i+1, m_indexName.size()-i+1+4));
}

QString CompressedMap::getPath() const
{
    return m_path;
}

QString CompressedMap::getIndexName() const
{
    return m_indexName;
}

bool CompressedMap::isInvalidMap() const
{
    return m_isInvalidMap;
}

uint CompressedMap::getOffset() const
{
    return m_offset;
}

uint CompressedMap::getByteCount() const
{
    return m_byteCount;
}

uint CompressedMap::getMapId() const
{
    return m_mapId;
}
