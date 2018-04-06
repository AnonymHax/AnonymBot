#pragma once

#include "System/Tools/IO/D2O/D2OFile.h"
#include "System/Tools/IO/D2O/GameDataTypeDeclarator.h"
#include "System/Tools/IO/I18n/I18nFile.h"
#include "System/Tools/IO/D2O/GameDataConverter.h"
#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/ItemData.h"
#include "System/Tools/Singleton.h"

class D2OManagerSingleton;

class D2OManager
{
    friend class ParamsDecoder;
    friend class Singleton<D2OManager>;

public: 
    ~D2OManager();

    void init(const QString &D2OFolderPath, const QString &I18nFilePath);
    bool isInit() const;

    I18nFile *getI18N();

    QSharedPointer<AbstractGameData> getObject(GameDataTypeEnum type, int index);

    QList<GameDataTypeEnum> getLoadedFiles() const;
    QSharedPointer<ItemData> getItem(int objectGID);
    QList<int> getIndexes(GameDataTypeEnum type);

private:
    D2OManager();

    void loadFile(GameDataTypeEnum searchedType);

    bool m_isInit;
    QString m_D2OFolderPath;
    QString m_I18nFilePath;
    QMap<GameDataTypeEnum, D2OFile*> m_D2Os;
    I18nFile *m_I18n;
    QMutex m_mutex;
};


class D2OManagerSingleton : public Singleton<D2OManager>
{
};
