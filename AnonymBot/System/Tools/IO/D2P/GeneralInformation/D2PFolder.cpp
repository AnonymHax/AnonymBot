#include "D2PFolder.h"

D2PFolder::D2PFolder(const QString &folderName) :
    m_D2PFileCount(0),
    m_folderName(folderName)
{
    if (!QDir(m_folderName).exists())
        qDebug()<<"ERREUR - D2PFolder - Le dossier n'existe pas"<<m_folderName;

    QDirIterator dirIt(m_folderName, QDirIterator::Subdirectories);
    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
            if (QFileInfo(dirIt.filePath()).suffix() == "d2p")
            {
                m_folderContent.push_back(new D2PFile(dirIt.filePath()));
                m_D2PFileCount++;
            }
    }

    if (m_D2PFileCount == 0)
        qDebug()<<"ERREUR - D2PFile - Mauvais dossier, aucun fichier D2P n'a été trouvé"<<m_folderName;
}

D2PFolder::~D2PFolder()
{
    foreach(D2PFile *file, m_folderContent)
        delete file;
}


const QList<D2PFile*> &D2PFolder::getFolderContent() const
{
    return m_folderContent;
}

const uint &D2PFolder::getD2PFileCount() const
{
    return m_D2PFileCount;
}

const QString &D2PFolder::getFolderName() const
{
    return m_folderName;
}
