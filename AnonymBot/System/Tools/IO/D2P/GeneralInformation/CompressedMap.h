#pragma once

#include "System/Tools/IO/Reader.h"


class CompressedMap
{
public:
    CompressedMap(Reader *reader, const QString &path);

    QString getPath() const;
    QString getIndexName() const;
    bool isInvalidMap() const;
    uint getOffset() const;
    uint getByteCount() const;
    uint getMapId() const;

private:
    QString m_path;
    QString m_indexName;
    uint m_offset;
    uint m_byteCount;
    bool m_isInvalidMap;
    uint m_mapId;
};

