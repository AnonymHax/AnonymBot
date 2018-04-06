#ifndef INTERACTIONMODULE_H
#define INTERACTIONMODULE_H

/*!
 * \class InteractionModule
 * \brief Module to handle all interactions between the bot and external elements, meaning NPC dialogs, Zaaps,
 * Zaapis, and actions with interactive elements (except the gathering and the crafting that have their own module
 * dedicated)
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "Public.h"
#include "MapModule.h"
#include "AbstractModule.h"

class InteractionModule : public AbstractModule
{
    Q_OBJECT

public:
    /*!
     * \brief InteractionModule
     * \param connectionsData
     */
    InteractionModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);

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
     * \brief processZaap
     * \param sender
     * \param mapId
     * \return bool
     */
    bool processZaap(SocketIO *sender, int mapId);

    /*!
     * \brief processZaapi
     * \param sender
     * \param mapID
     * \return bool
     */
    bool processZaapi(SocketIO *sender, int mapId);

    /*!
     * \brief processNpcInteraction
     * \param sender
     * \param cellId
     * \return bool
     */
    bool processNpcInteraction(SocketIO *sender, int cellId);

    /*!
     * \brief processNpcDialog
     * \param sender
     * \param dialog
     * \return bool
     */
    bool processNpcDialog(SocketIO *sender, QString dialog);

    /*!
     * \brief leaveNpcDialog
     * \param sender
     */
    bool leaveNpcDialog(SocketIO* sender);

    /*!
     * \brief processUse
     * \param sender
     * \param id
     * \param action
     * \return bool
     */
    bool processUse(SocketIO *sender, int id, QString action);

    /*!
     * \brief clearBankData
     * \param sender Pointer to the bot instance
     *
     * Clears the bank settings of the specified bot.
     */
    void clearBankData(SocketIO *sender);

    /*!
     * \brief getBankData
     * \param sender Pointer to the bot instance
     * \return BankData
     *
     * Returns the BankData of the specified bot.
     */
    BankData getBankData(SocketIO *sender);

    /*!
     * \brief addTakeBankItem
     * \param sender Pointer to the bot instance
     * \param item BankItem to add
     *
     * Adds the specified item in the list of items to retreive from the bank while the bot will be talking to the bank NPC.
     */
    void addTakeBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief addDepositBankItem
     * \param sender Pointer to the bot instance
     * \param item BankItem to add
     *
     * Adds the specified item in the list of items to deposit to the bank while the bot will be talking to the bank NPC.
     */
    void addDepositBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief removeTakeBankItem
     * \param sender Pointer to the bot instance
     * \param item BankItem to remove
     *
     * Removes the specified item in the list of items to retreive from the bank while the bot will be talking
     * to the bank NPC.
     */
    void removeTakeBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief removeDepositBankItem
     * \param sender Pointer to the bot instance
     * \param item BankItem to remove
     *
     * Removes the specified item in the list of items to deposit to the bank while the bot will be talking to the
     * bank NPC.
     */
    void removeDepositBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief updateTakeBankItem
     * \param sender Pointer to the bot instance
     * \param itemId Item ID to update
     * \param pods Pods to update for the item with the specified ID
     *
     * Updates the quantity of item with the corresponding ID that the bot should retreive from the bank. The quantity
     * of this item to take in the inventory is the specified percentage (parameter "pods") of the pods left in the bot
     * inventory. e.g: if the bot has 100 pods left and the paramter pods has a value of 50, the bot will take a quantity
     * 50% of 100 (= 50) items with the corresponding id.
     */
    void updateTakeBankItem(SocketIO *sender, uint itemId, uint pods);

    /*!
     * \brief updateDepositBankItem
     * \param sender Pointer to the bot instance
     * \param itemId Item ID to update
     * \param pods  Pods to update for the item with the specified ID
     *
     * Updates the quantity of item with the corresponding ID that the bot should dropped to the bank. The quantity
     * of this item to deposit in the bank is the specified percentage (parameter "pods") of the quantity of this itme
     * that the bot has in it's inventoy. e.g: if the bot has 100 items and the paramter "pods" has a value of 50, the
     * bot will deposit a quantity 50% of 100 (= 50) items with the corresponding id.
     */
    void updateDepositBankItem(SocketIO *sender, uint itemId, uint pods);

    /*!
     * \brief setTakeCondition
     * \param sender
     * \param condition
     *
     * Sets the take condition for the sender
     */
    void setTakeCondition(SocketIO *sender, BankInclusion condition);

    /*!
     * \brief setDepositCondition
     * \param sender
     * \param condition
     *
     * Sets the deposit condition for the sender
     */
    void setDepositCondition(SocketIO *sender, BankInclusion condition);

    /*!
     * \brief toggleFeed
     * \param sender Pointer to the bot instance
     * \param toggle bool to (dis)activate pet feed
     *
     * Allows the user to activate or disactivate the pet feeding process.
     */
    void toggleFeed(SocketIO *sender, bool toggle);

    /*!
     * \brief setPetFood
     * \param sender Pointer to the bot instance
     * \param id Pet global ID (GID)
     * \param food Food global ID (GID)
     *
     * Sets the meal of the pets with the corresponding GID (global ID) to the food GID specified.
     */
    void setPetFood(SocketIO *sender, uint id, int food);

    /*!
     * \brief setFeedTimer
     * \param sender Pointer to the bot instance
     * \param id Pet global ID
     * \param timer timer to feed pet
     *
     * Sets the interval of time that the bot should wait before feeding all the pets with the corresponding GIDs.
     */
    void setFeedTimer(SocketIO *sender, uint id, int timer);

private slots:
    void feed();
    void finishAction();
    void confirmAction();
    void moved(SocketIO *sender);
    void noMovement(SocketIO *sender);

private:
    QString nameFromUid(SocketIO *sender, int uid);
    bool concernedByBankTake(SocketIO *sender, int id);
    int getFoodUID(SocketIO *sender, int uid, int food);
    bool concernedByBankDeposit(SocketIO *sender, int id);

    MapModule *m_mapModule;
    QList<SocketIO*> m_confirmAction;
    QList<SocketIO*> m_finishedAction;
    QList<SocketIO*> m_waitingReplies;
    QMap<PetFeedInfos, SocketIO*> m_feed;
    QList< QPair<SocketIO*, PetFeedInfos> > m_connection;
};

#endif // INTERACTIONMODULE_H
