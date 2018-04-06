#ifndef FARMMODULE_H
#define FARMMODULE_H

#include "Public.h"
#include "MapModule.h"
#include "System/Tools/Pathfinding/Pathfinding.h"

class FarmModule : public AbstractModule
{
    Q_OBJECT

public:
    FarmModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);

    virtual void reset(SocketIO *sender);

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
    static bool canFarmResource(InteractiveElementInfos element);
    bool processFarm(SocketIO *sender);

    void clearAutoDeleteList(SocketIO *sender);
    bool resourcesListIsEmpty(SocketIO *sender);
    void addResourceToDelete(SocketIO *sender, QString name);
    bool editResourcesList(SocketIO *sender, uint id, bool add);
    void removeResourceToDelete(SocketIO *sender, QString name);

    //Miscellaneous
    uint getItemId(QString name);
    QString getJobName(uint jobId);
    bool isItemUsable(QString name);
    QStringList getResourcesName(Jobs job);

private slots:
    void activateSkill(SocketIO *sender);

private:
    void farmAction(SocketIO *sender);

    MapModule *m_mapModule;
    QMap<QString, UsableItem> m_items;
};

#endif // FARMMODULE_H
