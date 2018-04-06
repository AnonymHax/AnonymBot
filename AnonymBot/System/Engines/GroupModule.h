#ifndef GROUPMODULE_H
#define GROUPMODULE_H

/*!
 * \class GroupModule
 * \brief Module that handles all the teams. Used to manage team fight paths and going to bank as a group for example
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "Public.h"
#include "MapModule.h"

class GroupModule : public AbstractModule
{
    Q_OBJECT

public:
    /*!
     * \brief GroupModule
     * \param connectionsData
     * \param mapModule
     */
    GroupModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);

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
     * \brief setFollowUpEnabled
     * \param sender Pointer to the bot instance
     * \param followUp (dis)actives auto-follow of the bot's master
     *
     * Toggles the auto-follow of the specified bot's master.
     */
    void setFollowUpEnabled(SocketIO *sender, bool followUp);

    /*!
     * \brief setMaster
     * \param sender Pointer to ther bot instance
     * \param master Name of the master
     *
     * Defines the name of the specified bot's master. Set to "" to define no master.
     */
    void setMaster(SocketIO *sender, const QString &master);

    SocketIO *getMaster(SocketIO *sender);
    QList<SocketIO*> getSlaves(SocketIO *sender);
    bool isGroupOnMapAndInactive(SocketIO *master);
    void updateTeams();

private slots:
    void followUpUpdate(SocketIO *sender);
    void followUpFailure(SocketIO *sender);

private:    
    MapModule *m_mapModule;
};

#endif // GROUPMODULE_H
