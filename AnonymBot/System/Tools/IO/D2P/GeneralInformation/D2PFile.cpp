#include "D2PFile.h"

D2PFile::D2PFile(const QString &path):
    m_path(path)
{
    if (!path.contains(".d2p"))
        qDebug()<<"ERREUR - D2PFile - Extension incorrect"<<path;

    getFileContent();
}

D2PFile::~D2PFile()
{
    foreach(CompressedMap *map, m_content.values())
        delete map;
}

const QMap<uint, CompressedMap*> &D2PFile::getContent() const
{
    return m_content;
}

const QString &D2PFile::getPath() const
{
    return m_path;
}

void D2PFile::getFileContent()
{
    Reader reader(m_path);
    uchar param1 = reader.readByte();
    uchar param2 = reader.readByte();

    if ((param1 != 2) || (param2 != 1))
        qDebug()<<"ERREUR - D2PFile - Impossible de lire le fichier"<<m_path;

    reader.setPosition(reader.getSize()-16);
    uint position = reader.readUInt();
    int contentcount = reader.readUInt();
    reader.setPosition(position);

    for (int i = 0; i <= contentcount; i++)
    {
        CompressedMap *compressedMap = new CompressedMap(&reader, m_path);
        if (compressedMap->isInvalidMap())
        {
            delete compressedMap;
            continue;
        }

        m_content[compressedMap->getMapId()] = compressedMap;
    }
}
