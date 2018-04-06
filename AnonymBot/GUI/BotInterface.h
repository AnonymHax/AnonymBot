#ifndef BOTINTERFACE_H
#define BOTINTERFACE_H

#include <QMenu>
#include <QAction>
#include <QModelIndex>
#include <QFileDialog>
#include <QStandardItemModel>

#include "Public.h"
#include "qcustomplot.h"
#include "System/Engines/ProcessEngine.h"
#include "System/Tools/IO/D2O/D2OManager.h"
#include "System/Tools/PropertyHelper.h"
#include "System/Tools/EntityLook/EntityLookParser.h"
#include "System/Tools/IO/Trie.h"
#include "CustomTypes.h"

#define FASTBOOT_EXCHANGE true
#define FASTBOOT_MONSTER true
#define FASTBOOT_FOOD true

#define UPDATE_INTERVAL 500

#define DEBUG_COLOR "#01b1da"
#define GLOBAL_COLOR "#312D24"
#define TEAM_COLOR "#006699"
#define GUILD_COLOR "#663399"
#define ALLIANCE_COLOR "#BB6200"
#define PARTY_COLOR "#006699"
#define SALES_COLOR "#663300"
#define SEEK_COLOR "#737373"
#define NOOB_COLOR "#0000cc"
#define ADMIN_COLOR "#ff00ff"
#define ADS_COLOR "#24a394"
#define ARENA_COLOR "#f16392"
#define PRIVATE_COLOR "#0066ff"
#define INFO_COLOR "#009900"
#define FIGHT_COLOR "#009900"
#define ALERT_COLOR "#c10000"
#define ACTION_COLOR "orange"

struct floodCheckBoxState
{
    bool sales;
    bool seek;
    bool global;
    bool priv;
};

class BotInterface : public QObject
{
    Q_OBJECT

    Q_ENUMS(BotStateEnum)
    Q_ENUMS(MapViewerCellEnum)

    // PROPRIETES PASSIVES
    AUTO_PROPERTY(int, connectionState)
    AUTO_PROPERTY(QString, characterName)
    AUTO_PROPERTY(bool, isInGroup)
    AUTO_PROPERTY(int, lifePoints)
    AUTO_PROPERTY(int, maxLifePoints)
    AUTO_PROPERTY(int, pods)
    AUTO_PROPERTY(int, maxPods)
    AUTO_PROPERTY(QPoint, mapPosition)
    AUTO_PROPERTY(int, kamas)
    AUTO_PROPERTY(int, energyPoints)
    AUTO_PROPERTY(int, maxEnergyPoints)
    AUTO_PROPERTY(int, botState)
    AUTO_PROPERTY(QString, characterHeadUrl)
    AUTO_PROPERTY(QString, characterFullUrl)
    AUTO_PROPERTY(int, level)
    AUTO_PROPERTY(int, maxExperience)
    AUTO_PROPERTY(int, experience)
    AUTO_PROPERTY(QPoint, position)
    AUTO_PROPERTY(int, mapId)
    AUTO_PROPERTY(QString, area)
    AUTO_PROPERTY(QString, subArea)
    AUTO_PROPERTY(int, statsPoints)
    AUTO_PROPERTY(int, spellsPoints)
    AUTO_PROPERTY(QList<int>, entityTypes)
    AUTO_PROPERTY(QList<int>, interactiveTypes)
    AUTO_PROPERTY(QList<int>, collisionTypes)

    READONLY_PROPERTY(InteractiveModel*, interactiveModel)
    READONLY_PROPERTY(InventoryModel*, inventoryModel)
    READONLY_PROPERTY(BasicStatsModel*, basicStatsModel)
    READONLY_PROPERTY(PrimaryStatsModel*, primaryStatsModel)
    READONLY_PROPERTY(SpellsModel*, spellsModel)
    READONLY_PROPERTY(JobsModel*, jobsModel)
    READONLY_PROPERTY(FightSpellsModel*, fightSpellsModel)

    READONLY_PROPERTY(SpellsCompleterModel*, spellsCompleterModel)
    READONLY_PROPERTY(CompleterModel*, exchangesCompleterModel)
    READONLY_PROPERTY(CompleterModel*, foodsCompleterModel)
    READONLY_PROPERTY(CompleterModel*, monstersCompleterModel)


public:

    enum BotStateEnum
    {
        MOVING_STATE,
        MAP_TRANSITION_STATE,
        FARMING_STATE,
        BANKING_STATE,
        INVALID_STATE,
        CRAFTING_STATE,
        FIGHTING_STATE,
        INACTIVE_STATE,
        EXCHANGING_STATE,
        CALCULATING_STATE,
        REGENERATING_STATE
    };

    enum MapViewerCellEnum
    {
        NOTHING,
        PLAYER,
        BOT,
        PLAYER_BOT,
        NPC,
        USABLE,
        MONSTER,
        INTERACTIVE,
        COLLISION_NO_SIGHT,
        COLLISION_WITH_SIGHT
    };

    BotInterface();
    BotInterface(ProcessEngine *engine, const ConnectionInfos &infos);
    ~BotInterface();

    static void initialize();

    void updateMap();

    int loadPath(QString path, bool unload);
    //  void savePresentConfig(QString name);

    SocketIO *getSocket();
    QString getTime(uint timeStamp);
    ConnectionInfos getConnectionInfos() const;

    // BotInterface
    Q_INVOKABLE void connect();
    Q_INVOKABLE void disconnect();

    // Console
    Q_INVOKABLE void sendChatMessage(QVariant channel, QVariant message);

    // Map
    Q_INVOKABLE void changeMapTop();
    Q_INVOKABLE void changeMapRight();
    Q_INVOKABLE void changeMapLeft();
    Q_INVOKABLE void changeMapBottom();

    // Character
    Q_INVOKABLE void increaseStat(int index);
    Q_INVOKABLE void increaseSpell(int index);

    // Inventory
    Q_INVOKABLE void destroyItem(int index, uint quantity);
    Q_INVOKABLE void equipItem(int index);
    Q_INVOKABLE void unequipItem(int index);
    Q_INVOKABLE void useItem(int index);

    // Fight
    Q_INVOKABLE void addMonster(QString s);
    Q_INVOKABLE void addSpell(QString s);

public slots:
    void updateInterface(bool directCall = false);

signals:
    void addConsoleLineRequest(QString content);

private:

    const BotData &getData() const;

    uint m_logMessageCount;

    int m_mapId;
    QList<uint> m_playersOnMap;
    QList<uint> m_monstersOnMap;

    bool m_hasBeenDisconnected;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    QList<RequestTradeObject> m_requestList;

    static bool m_init;

    Trie m_spellsCompleter;
    static Trie m_exchangesCompleter;
    static Trie m_monstersCompleter;
    static Trie m_foodsCompleter;

    floodCheckBoxState m_checkBoxState;

    QMenu *m_inventoryMenu;
    QMap<QCheckBox*, int> m_jobs;

    QTimer m_updateTimer;
    QTime m_updateChecker;
};

#endif // BOTINTERFACE_H
