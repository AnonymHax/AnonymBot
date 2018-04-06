#ifndef FLOODMODULE_H
#define FLOODMODULE_H

/*!
 * \class FloodModule
 * \brief Module that handles flood on different channels in the same time. Also used to manage intelligent PM
 * and flood through a mini script file.
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "Public.h"
#include "AbstractModule.h"
#include <QPropertyAnimation>
#include "Network/CleverBot.h"

/*!
 * \struct FloodRequest
 * \brief The FloodRequest struct
 *
 * Holds all the informations that are required for a bot to flood properly: pointer to bot instance, Channel, timer
 * and time cooldown between two messages.
 */
struct FloodRequest
{
    SocketIO* sender;   /*!< Pointer to the bot instance */
    Channel channel;    /*!< Channel to flood on */
    QTime elapsedTime;  /*!< Timer of elapsed time since the last message sent */
    int estimatedTime;  /*!< Cooldown between two messages */
};

/*!
 * \brief operator <
 * \param left
 * \param right
 * \return bool
 */
bool operator<(const FloodRequest &left, const FloodRequest &right);

/*!
 * \brief operator !=
 * \param left
 * \param right
 * \return bool
 */
bool operator!=(const FloodRequest &left, const FloodRequest &right);

/*!
 * \brief operator ==
 * \param left
 * \param right
 * \return bool
 */
bool operator==(const FloodRequest &left, const FloodRequest &right);

class FloodModule : public AbstractModule
{

    Q_OBJECT

public:
    /*!
     * \brief FloodModule
     * \param connectionsData
     */
    FloodModule(QMap<SocketIO*, BotData> *connectionsData);
    ~FloodModule();

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
     * \brief setCleverBotResponseTime
     * \param sender Pointer to the bot instance
     * \param min Minimum delay of answer
     * \param max Maximum delay of answer
     *
     * Sets the minimum and maximum delay of the specified bot to answer a PM.
     */
    void setCleverBotResponseTime(SocketIO *sender, int min, int max);

    /*!
     * \brief setCleverBotState
     * \param sender Pointer to the bot instance
     * \param state (dis)activates smart annswers
     *
     * Toggles smart PM answer. If state is true, activates the system, if not disables it.
     */
    void setCleverBotState(SocketIO *sender, bool state);

    /*!
     * \brief setFloodLevels
     * \param sender Pointer to the bot instance
     * \param min Minimum receiver level to flood in PM
     * \param max Maximum receiver level to flood in PM
     *
     * Defines the range of player levels to flood in PM for the specified bot.
     */
    void setFloodLevels(SocketIO *sender, int min, int max);

    /*!
     * \brief sendChatMessage
     * \param sender Pointer to the bot instance
     * \param messageContent Message to send
     * \param channel Channel in which to send the message
     *
     * Sends the message in the specified channel with the specified bot.
     */
    void sendChatMessage(SocketIO *sender, const QString &messageContent, const Channel &channel);

    /*!
     * \brief sendChatMessage
     * \param sender Pointer to the bot instance
     * \param messageContent Message to send
     * \param receiver Name of the PM receiver
     *
     * Attemps to send a PM to the corresponding receiver with the specified message from the specified bot.
     */
    void sendChatMessage(SocketIO *sender, const QString &messageContent, const QString &receiver);

    /*!
     * \brief endFlood
     * \param sender Pointer to the bot instance
     *
     * Toggles of the flood.
     */
    void endFlood(SocketIO *sender);

    /*!
     * \brief initFlood
     * \param sender Pointer to the bot instance
     * \param channels List of channels in which to flood
     *
     * Sets the channels in which the specified bot has to flood.
     */
    void initFlood(SocketIO *sender, const QList<Channel> &channels);

    /*!
     * \brief addFloodChannel
     * \param sender Pointer to the bot instance
     * \param channel Channel to add
     *
     * Adds a channel in the channel list to flood of the specified bot.
     */
    void addFloodChannel(SocketIO* sender, const Channel &channel);

    /*!
     * \brief removeFloodChannel
     * \param sender Pointer to the bot instance
     * \param channel Channel to remove
     *
     * Removes a channel from the channel list to flood of the specified bot.
     */
    void removeFloodChannel(SocketIO* sender, const Channel &channel);

    /*!
     * \brief modifyFloodMessage
     * \param sender Pointer to the bot instance
     * \param message New message to FloodData
     *
     * Updates the message flooded by the specified bot.
     */
    void modifyFloodMessage(SocketIO* sender, const QString &message);

    /*!
     * \brief loadMessagesFromFile
     * \param sender Pointer to the bot instance
     * \param messages List of message to flood
     * \return bool Returns true if the message where successfully loaded, false if not
     *
     * Attemps to load a list of message to flood for the specified bot. Returns true if the message where
     * successfully loaded, false if not. The message to flood will automatically go to the next one
     * when the timer is elapsed.
     */
    bool loadMessagesFromFile(SocketIO* sender, const QStringList messages);

    /*!
     * \brief setIsUsingFile
     * \param sender Pointer to the bot instance
     * \param isUsingFile Set to true to activate and false to disable
     *
     * Toggles flood from file.
     */
    void setIsUsingFile(SocketIO* sender, const bool isUsingFile);

    /*!
     * \brief loadTimerFromFile
     * \param sender Pointer to the bot instance
     * \param timer Cooldown to change flood message
     * \return bool Returns true if the timer was set correctly, false if NotificationByServerMessage
     *
     * Attemps to define the message rotation cooldown when using a list of predefined message loaded through
     * a flood file.
     */
    bool loadTimerFromFile(SocketIO* sender, const uint timer);

    /*!
     * \brief setFileContent
     * \param sender Pointer to the bot instance
     * \param content Content of the file
     *
     * Sets the content of the flood file when user loads a file to define a set of predefined messages to flood with
     * a rotation timer.
     */
    void setFileContent(SocketIO *sender, QByteArray content);

    /*!
     * \brief getFileContent
     * \param sender Pointer to the bot instance
     * \return QByteArray File content
     *
     * Gets the loaded flood file content that was previously loaded by the user.
     */
    QByteArray getFileContent(SocketIO *sender);

    /*!
     * \brief getIsUsingFile
     * \param sender Pointer to the bot instance
     * \return bool Returns true if user is using flood file, false if not
     *
     * Checks if the specified bot uses a flood file. Returns true if the bot is using it, false if not.
     */
    bool getIsUsingFile(SocketIO *sender);

private slots:
    void sendCleverBotMp(SocketIO *sender, QString messageContent, QString receiver);
    void changeFloodMessage();
    void processFloodWaiting();

private:
    QString randomizeFloodMessage();
    QList<FloodRequest> m_floodRequests;
};

#endif // FLOODMODULE_H
