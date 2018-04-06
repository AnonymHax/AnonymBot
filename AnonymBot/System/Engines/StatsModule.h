#ifndef STATSMODULE_H
#define STATSMODULE_H

/*!
 * \class StatsModule
 * \brief Module to handle characters stats
 * \author AnonymHax & G0hu
 * \version Beta
 *
 * This module handle the characterisics, the inventory, pets and mount of the bot. Used to feed pets, use, equip and delete
 * items from the bot's inventory. It can also be used to increase the bot's spell's level.
 */

#include "Public.h"
#include "AbstractModule.h"
#include "System/Tools/IO/D2O/GameDataDeclarator.h"

struct LifeRegenQueue
{
    QTime time;
    int interval;
    QTimer *timer;
    SocketIO* sender;
};

class StatsModule : public AbstractModule
{
    Q_OBJECT

public:
    /*!
     * \brief StatsModule
     * \param connectionsData
     */
    StatsModule(QMap<SocketIO*, BotData> *connectionsData);

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
     * \brief deleteItem
     * \param sender Pointer to the bot instance
     * \param id Item id to delete
     * \param all If true, delete the all the quantity of the item, else delete only one item
     *
     * Delete the item with the specified ID. If all variable is set to true, all the quantity of the item that the bot has
     * in it's inventory. Else, only one quantity of the item will be deleted.
     */
    void destroyItem(SocketIO *sender, uint uid, uint quantity);

    /*!
     * \brief useItem
     * \param sender Pointer to the bot instance
     * \param id Item id to use
     *
     * The bot will attempt to use the item with the specified ID.
     */
    void useItem(SocketIO *sender, uint uid);

    /*!
     * \brief increaseStat
     * \param sender Pointer to the bot instance
     * \param stat Informations on the stats to increase depending on the bot's breed
     *
     * The bot will attempt to inscrease the bot's specfied characteristc according to it's breed's constraints.
     */
    void increaseStat(SocketIO *sender, PlayerFields stat);

    /*!
     * \brief updateMountXpRatio
     * \param sender Pointer to the bot instance
     * \param ratio Ratio of xp to give to the mount after each fight
     *
     * The bot will change the xp ratio that is given to the mount at the end of each fight.
     */
    void updateMountXpRatio(SocketIO *sender, uint ratio);

    /*!
     * \brief increaseSpell
     * \param sender Pointer to the bot instance
     * \param spellID Spell id of the spell to boost
     *
     * The bot will increase the spell with the specified ID of one level.
     */
    void increaseSpell(SocketIO *sender, int spellID);

    /*!
     * \brief getMountEffects
     * \param sender
     * \return QString The string of the mount's boosts
     *
     * Function that returns a human readable version of the bot's mount's boosts.
     */
    QString getMountEffects(SocketIO *sender);

    /*!
     * \brief healSit
     * \param sender
     * \return bool
     *
     * Heals the character by sitting until his life is at the percentage specified
     */
    bool healSit(SocketIO* sender);

    /*!
     * \brief healEat
     * \param sender
     * \return bool
     *
     * Heals the character by eating resources until his life is at the percentage specified
     */
    bool healEat(SocketIO* sender);

    bool canEquipItem(uint gid);
    void equipItem(SocketIO* sender, uint uid);
    void unequipItem(SocketIO *sender, uint uid);

    void freeSoul(SocketIO *sender);
    bool needsHeal(SocketIO *sender);
    bool needsToGoToBank(SocketIO *sender);
    bool needsToGoToPhoenix(SocketIO *sender);

    void setRegenUseObjectsEnabled(SocketIO *sender, bool enabled);
    void setRegenerationRatio(SocketIO *sender, uint min, uint max);

private slots:
    void healFinished();
    void passiveHealing();
    void preventRegenBlocked();

signals:
    void healed(SocketIO* sender);

private:
    QMap<uint, QString> m_pets;
    QList<LifeRegenQueue> m_regenQueue;
    QList<LifeRegenQueue> m_passiveRegen;
    QList<LifeRegenQueue> m_preventRegenBlocked;
    QList<CharacterInventoryPositionEnum> m_inventoryPositions;

    void regenOptimizer(SocketIO *sender);
    void updateRequiredStats(SocketIO *sender);
};

#endif // STATSMODULE_H
