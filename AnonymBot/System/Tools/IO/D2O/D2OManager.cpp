#include "D2OManager.h"

D2OManager::D2OManager() :
    m_isInit(false)
{
}


D2OManager::~D2OManager()
{
    foreach(D2OFile *D2Ofile, m_D2Os)
        delete D2Ofile;

    delete m_I18n;
}

void D2OManager::init(const QString &D2OFolderPath, const QString &I18nFilePath)
{
    QTime t;
    t.start();

    m_isInit = true;

    if (!QDir(D2OFolderPath).exists())
        qDebug()<<"ERREUR - D2OManager - N'arrive pas a ouvrir le dossier des D2Os :"<<D2OFolderPath;

    if (!QFile(I18nFilePath).exists())
        qDebug()<<"ERREUR - D2OManager - N'arrive pas a ouvrir le fichier I18n :"<<I18nFilePath;

    m_D2OFolderPath = D2OFolderPath;
    m_I18nFilePath = I18nFilePath;

    m_I18n = new I18nFile(m_I18nFilePath);

    qDebug()<<"D2OManager - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
}

bool D2OManager::isInit() const
{
    return m_isInit;
}

I18nFile *D2OManager::getI18N()
{
    return m_I18n;
}

QSharedPointer<AbstractGameData> D2OManager::getObject(GameDataTypeEnum type, int index)
{
    m_mutex.lock();

    if (!m_isInit)
        qDebug()<<"ERREUR - D2OManager - N'est pas initialisé";

    if (!m_D2Os.contains(type))
        loadFile(type);

    QSharedPointer<AbstractGameData> i = m_D2Os[type]->readIndex(index);

    m_mutex.unlock();

    return i;
}

QList<GameDataTypeEnum> D2OManager::getLoadedFiles() const
{
    if (!m_isInit)
        qDebug()<<"ERREUR - D2OManager - N'est pas initialisé";

    return m_D2Os.keys();
}

QList<int> D2OManager::getIndexes(GameDataTypeEnum type)
{
    QList<int> indexes;

    if (!m_isInit)
        qDebug()<<"ERREUR - D2OManager - N'est pas initialisé";

    if(!m_D2Os.contains(type))
        loadFile(type);

    foreach(const int &index, m_D2Os[type]->getIndexes())
        indexes << index;

    return indexes;
}

QSharedPointer<ItemData> D2OManager::getItem(int objectGID)
{
    if (!m_isInit)
        qDebug()<<"ERREUR - D2OManager - N'est pas initialisé";

    if(!m_D2Os.contains(GameDataTypeEnum::ITEMS))
        loadFile(GameDataTypeEnum::ITEMS);

    return qSharedPointerCast<ItemData>(m_D2Os[GameDataTypeEnum::ITEMS]->readIndex(objectGID));
}

void D2OManager::loadFile(GameDataTypeEnum searchedType)
{
    bool foundFile = false;

    QDirIterator dirIt(m_D2OFolderPath, QDirIterator::Subdirectories);
    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
            if (QFileInfo(dirIt.filePath()).suffix() == "d2o")
            {
                GameDataTypeEnum fileType = GameDataConverter::getEnum(dirIt.fileInfo().baseName());

                if(fileType == searchedType)
                {
                    m_D2Os[fileType] = new D2OFile(dirIt.filePath(), m_I18n, fileType);
                    foundFile = true;
                    break;
                }
            }
    }

    if(!foundFile)
        qDebug()<<"ERREUR - D2OManager - Ne connait pas l'enum"<<(int)searchedType;
}

