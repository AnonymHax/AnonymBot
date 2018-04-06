#include "D2PManager.h"

D2PManager::D2PManager():
    m_folder(NULL),
    m_isInit(false)
{
}

D2PManager::D2PManager(const QString &D2PFolder)
{
    init(D2PFolder);
}

D2PManager::~D2PManager()
{
    delete m_folder;
}

void D2PManager::init(const QString &D2PFolder)
{
    QTime t;
    t.start();

    m_isInit = true;
    m_folder = new class D2PFolder(D2PFolder);

    qDebug()<<"D2PManager - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
}

bool D2PManager::isInit() const
{
    return m_isInit;
}

Map D2PManager::getMap(uint mapId)
{
    m_mutex.lock();

    if(!m_isInit)
        qDebug()<<"ERREUR - D2PManager n'est pas initialisé";

    Map map = getCompressedMap(mapId);

    m_mutex.unlock();

    return map;
}

QMap<uint, Map> D2PManager::parseAllMap()
{
    if(!m_isInit)
        qDebug()<<"ERREUR - D2PManager n'est pas initialisé";

    QMap<uint, Map> allMap;

    foreach (D2PFile *D2Pfile, m_folder->getFolderContent())
    {
        foreach (CompressedMap *compressedMap, D2Pfile->getContent())
            allMap[compressedMap->getMapId()] = Map(compressedMap);
    }

    return allMap;
}

CompressedMap* D2PManager::getCompressedMap(uint mapId)
{
    if(!m_isInit)
        qDebug()<<"ERREUR - D2PManager n'est pas initialisé";

    for (QList<D2PFile*>::const_iterator D2PFile = m_folder->getFolderContent().begin(); D2PFile != m_folder->getFolderContent().end(); ++D2PFile)
    {
        if ((*D2PFile)->getContent().contains(mapId) )
            return (*D2PFile)->getContent()[mapId];
    }

    qDebug()<<"ERREUR - D2PManager la carte d'id"<<mapId<<"n'existe pas";

    return NULL;
}
