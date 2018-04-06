#pragma once

#include "GeneralInformation/D2PFolder.h"
#include "MapInformation/Map.h"
#include "GeneralInformation/CompressedMap.h"
#include "GeneralInformation/D2PFile.h"
#include "System/Tools/Singleton.h"


class D2PManager
{
    friend class Singleton<D2PManager>;

public:
    D2PManager(const QString &D2PFolder);
    ~D2PManager();

    void init(const QString &D2PFolder);
    bool isInit() const;

    Map getMap(uint mapId);
    QMap<uint, Map> parseAllMap();

private:
    D2PManager();
    CompressedMap* getCompressedMap(uint mapId);

    bool m_isInit;
    D2PFolder *m_folder;

    QMutex m_mutex;
};

class D2PManagerSingleton : public Singleton<D2PManager>
{
};
