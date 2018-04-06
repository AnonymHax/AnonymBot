#ifndef FIGHTMODULE_H
#define FIGHTMODULE_H

#include "Public.h"
#include "MapModule.h"
#include "GroupModule.h"

enum class SpellInabilityReason
{
    /// <summary>Les points d'action sont insuffisants</summary>
         ACTION_POINTS = -1,
         /// <summary>Le temps de recharge du sort est actif</summary>
         COOL_DOWN = -2,
         /// <summary>L'état n'est pas autorisé</summary>
         FORBIDDEN_STATE = -3,
         /// <summary>La ligne de vue n'est pas dégagée</summary>
         LINE_OF_SIGHT = -4,
         /// <summary>La distance maximum du sort a été dépassée</summary>
         MAX_RANGE = -5,
         /// <summary>La distance minimum du sort a été dépassée</summary>
         MIN_RANGE = -6,
         /// <summary>La cellule doit être vide</summary>
         NEED_FREE_CELL = -7,
         /// <summary>La cellule doit être prise</summary>
         NEED_TAKEN_CELL = -8,
         /// <summary>Le sort peut être lancé</summary>
         OK = 1,
         /// <summary>Le sort n'est pas lancé en ligne alors qu'il le devrait</summary>
         NOT_IN_LINE= -9,
         /// <summary>L'état requis est manquant</summary>
         REQUIRED_STATE = -10,
         /// <summary>Le nombre d'invoquation est dépassé</summary>
         TOO_MANY_INVOCATIONS = -11,
         /// <summary>Le sort a été lancé trop de fois ce tour</summary>
         TOO_MANY_LAUNCH= -12,
         /// <summary>Le sort a été lancé trop de fois sur cette cellule</summary>
         TOO_MANY_LAUNCH_ON_CELL = -13,
         /// <summary>Le sort ne peut pas être lancé pour une raison inconnue</summary>
         UNKNOWN = -16,
         /// <summary>Le personnage ne possède pas le sort indiqué</summary>
         UNKNOWN_SPELL = -14,
         /// <summary>Le sort n'est pas lancé en diagonale alors qu'il le devrait</summary>
         NOT_IN_DIAGONAL = -15
};

enum class SpellType
{
    SUMMON,
    HEAL,
    ATTACK,
    UNKOWN,
    BOOST
};

class FightModule : public AbstractModule
{

    Q_OBJECT

public:
    FightModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule, GroupModule *groupModule);

    virtual void reset(SocketIO *sender);

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    void setRequestedMonsters(SocketIO *sender, RequestedMonsters requestedMonster);
    void setFightIA(SocketIO *sender, FightIA fightIA);
    void setPartyOnly(SocketIO *sender, bool isPartyOnly);
    void setSecret(SocketIO *sender, bool isSecret);

    void setRequestedSpells(SocketIO *sender, QList<RequestedSpell> requestedSpells);
    QList<RequestedSpell> getRequestedSpells(SocketIO *sender) const;

    Point2D getCoordsbyCellID(int cellID);
    int getCellIDFromCoords(Point2D coords);

    int getDistance(Point2D source, Point2D destination);
    int getDistance(int sourceCellID, int destinationCellID);

    SpellType getSpellType(SocketIO *sender, int spellID);

    QList<MonsterGroup> getMonstersToFight(SocketIO *sender);
    bool isMonstersToFight(SocketIO *sender);

public slots:
    bool processMonsters(SocketIO *sender);

private slots:
    void processEndFight(SocketIO *sender);

    void moveSuccess(SocketIO *sender);
    void moveFailure(SocketIO *sender);

private:
    void updateFightDisposition(SocketIO *sender);

    QList<uint> getFighters(SocketIO *sender);
    QList<uint> getAllies(SocketIO *sender);
    QList<uint> getEnemies(SocketIO *sender);

    int getStrongestEnemy(SocketIO *sender);
    int getWeakestEnemy(SocketIO *sender);

    void processTurn(SocketIO *sender);
    void processEndTurn(SocketIO *sender);

    QList<uint> getFartherCells(uint cellID, QList<uint> cibles);
    uint getFartherCell(uint cellID, QList<uint> cibles);
    QList<uint> getClosestCells(uint cellID, QList<uint> cibles);
    uint getClosestCell(uint cellID, QList<uint> cibles);
    uint getMiddleCell(QList<uint> cibles);

    QList<uint> getSurroundingCells(int cellID, int minRadius, int radius);

    SpellInabilityReason canCastSpellNextTurn(SocketIO *sender, int spellID);
    SpellInabilityReason canCastSpell(SocketIO *sender, int spellID);
    SpellInabilityReason canCastSpellOnCell(SocketIO *sender, int spellID, int cellID);

    bool isFreeCell(SocketIO *sender, int cellID);

    QList<Point2D> getLine(int x1, int y1, int x2, int y2);

    void castSpell(SocketIO *sender, int spellID, int cellID);
    void moveToCell(SocketIO *sender, QList<uint> path);

    void addFighter(SocketIO *sender, const QSharedPointer<GameFightFighterInformations> &fighter);

    bool castNear(SocketIO *sender, int spellID, int cibleID);
    bool castAway(SocketIO *sender, int spellID, int cibleID);

    bool moveNear(SocketIO *sender, int cibleID, int distanceWanted = -1, bool moveOnlyIfDistancePossible = false);
    bool moveAway(SocketIO *sender, int cibleID, int distanceWanted = -1, bool moveOnlyIfDistancePossible = false);
    bool moveToRange(SocketIO *sender, int spellID, int cellID, bool moveOnlyIfDistancePossible = true);


    MapModule *m_mapModule;
    GroupModule *m_groupModule;
    static QMap<int, Point2D> m_cellsPos;
    static QMap<Point2D, int> m_cellsId;
};

#endif // FIGHTMODULE_H
