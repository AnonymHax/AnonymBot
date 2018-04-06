#ifndef SCRIPTMODULE_H
#define SCRIPTMODULE_H

/*!
  * \class ScriptModule
  * \brief Module to regulate paths
  * \author AnonymHax & G0hu
  * \version Beta
  *
  * This module is used to handle paths that are loaded to the bot. The file will be parsed here and then saved to
  * what the bot should do when he enters a new map.
  */

#include "Public.h"
#include "MapModule.h"
#include "FarmModule.h"
#include "FightModule.h"
#include "CraftModule.h"
#include "StatsModule.h"
#include "InteractionModule.h"
#include "GroupModule.h"
#include "ConnectionModule.h"
#include "System/Tools/Pathfinding/PathfindingMap.h"

#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#define MOVE_MAXTIME 60000
#define FARM_MAXTIME 60000
#define CRAFT_MAXTIME 60000
#define INTERACTION_MAXTIME 60000

class ScriptModule : public AbstractModule
{    
    Q_OBJECT

public:
    /*!
     * \brief ScriptModule
     * \param connectionsData
     * \param mapModule
     * \param fightModule
     * \param farmModule
     * \param craftModule
     * \param interactionModule
     * \param groupModule
     */
    ScriptModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule,
                 FightModule *fightModule,
                 FarmModule *farmModule, CraftModule *craftModule,
                 InteractionModule *interactionModule,
                 GroupModule *groupModule,
                 StatsModule *statsModule,
                 ConnectionModule *connectionModule);


    virtual void reset(SocketIO *sender);
    /*!
     * \brief processMessage
     * \param data Content of the packet
     * \param sender Pointer to the bot instance
     * \return bool Returns true if the message was detected and false if not
     *
     * Base function of each module that is made of a switch to process each packets that will be useful for this module.
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    /*!
     * \brief parse
     * \param sender Pointer to the bot instance
     * \return int Returns 0 if no error and the line number if there is a syntax error
     *
     * Function used to parse the file loaded through the GUI by the user
     */
    int parse(SocketIO *sender);

    /*!
     * \brief unloadFile
     * \param sender Pointer to the bot instance
     *
     * Function used to clear bot informations of the path and unload script.
     */
    void unloadFile(SocketIO *sender);

    /*!
     * \brief loadFile
     * \param sender Pointer to the bot instance
     * \param p Path to the file to load
     * \return bool Returns true if the file was opened successfully.
     *
     * Function used to parse file with the path provided.
     */
    bool loadFile(SocketIO *sender, QString p);

    /*!
     * \brief setActivePath
     * \param sender Pointer to the bot instance
     * \param active Toggle activity of path
     */
    void setActivePath(SocketIO *sender, bool active);

    void setPodsLimit(SocketIO *sender, ushort ratio);

    /*!
     * \brief getLost
     * \param sender Pointer to the bot instance
     * \return ScriptPathMapData Returns informations of what the bot has to do to go back to the default lost map
     */
    ScriptPathMapData getLost(SocketIO *sender);

    /*!
     * \brief getMap
     * \param sender Pointer to the bot instance
     * \param id This is an overloaded parameter for the map id. If default value, id will be set to current mapId
     * \return ScriptPathMapData Returns informations of the bot actionList for the requested map
     */
    ScriptPathMapData getMap(SocketIO *sender, uint id = 0);

    /*!
     * \brief getBank
     * \param sender Pointer to the bot instance
     * \param id This is an overloaded parameter for the map id. If default value, id will be set to current mapId
     * \return ScriptPathMapData Returns informations of the bot actionList for the requested map to go to the bank
     */
    ScriptPathMapData getBank(SocketIO *sender, uint id = 0);

    /*!
     * \brief getGhost
     * \param sender Pointer to the bot instance
     * \param id This is an overloaded parameter for the map id. If default value, id will be set to current mapId
     * \return ScriptPathMapData Returns informations of the bot actionList for the requested map to go to the phoenix
     */
    ScriptPathMapData getGhost(SocketIO *sender, uint id = 0);

private slots:
    void cancelProcessingAction(SocketIO *sender);
    void processRepeatAction(SocketIO *sender);
    void processNextAction(SocketIO *sender);
    void processControl(SocketIO *sender);
    void waitForInactivity();

private:
    bool groupNeedsHeal(SocketIO *sender);
    bool groupNeedsToGoToBank(SocketIO *sender);
    bool isGroupReadyForNextSequence(SocketIO *master);
    ScriptPathMapData arrangeScriptForSlave(ScriptPathMapData s);

    void convertToFunction(ScriptPathMapData &s);
    static bool checkConditionalSyntax(QString d);
    bool conditionalParser(SocketIO *sender, QString d);

    QList<MapSide> getSides(QString side);
    ScriptFunction getFunction(QString f);
    QList<MapSide> getSideFromMove(ScriptFunction f);

    QVariantList parseInt(QString d);
    QVariantList parseString(QString d);
    QVariantList parseIntArray(QString d);
    QVariantList parseStringArray(QString d);

    bool check(SocketIO *sender, QString d);
    bool isMap(SocketIO *sender, QString d);
    bool isHeader(SocketIO *sender, QString d);
    bool isOpenTag(SocketIO *sender,QString d);
    bool isCloseTag(SocketIO *sender, QString d);
    bool isCondition(SocketIO *sender, QString d);

    MapModule *m_mapModule;
    FarmModule *m_farmModule;
    CraftModule *m_craftModule;
    FightModule *m_fightModule;
    QList<SocketIO*> m_waitingList;
    InteractionModule *m_interactionModule;
    GroupModule *m_groupModule;
    StatsModule *m_statsModule;
    ConnectionModule *m_connectionModule;
};

#endif // SCRIPTMODULE_H
