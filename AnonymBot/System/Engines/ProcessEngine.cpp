#include "ProcessEngine.h"
#include <unistd.h>
#include "System/Tools/IO/D2O/D2OManager.h"

ProcessEngine::ProcessEngine()
{
    connect(m_modules[ModuleType::CONNECTION], SIGNAL(connectionAdded(SocketIO*)), this, SLOT(connectToSocket(SocketIO*)));
    connect(m_modules[ModuleType::CONNECTION], SIGNAL(botDisconnected(SocketIO*)), this, SLOT(resetModules(SocketIO*)));


    QMapIterator<ModuleType, AbstractModule*> module(m_modules);
    while (module.hasNext())
    {
        module.next();
        connect(module.value(), SIGNAL(requestUpdate(SocketIO*)), this, SLOT(processUpdateRequest(SocketIO*)));
    }
}

void ProcessEngine::resetModules(SocketIO *sender)
{
    foreach(AbstractModule *module, m_modules.values())
        module->reset(sender);

    processUpdateRequest(sender);
}

void ProcessEngine::processUpdateRequest(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if(m_botData[sender].generalData.logMessages.size() <= 250)
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessages.size();

        while(m_botData[sender].generalData.logMessages.size() > 250)
        {
            m_botData[sender].generalData.logMessages.removeFirst();
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessageCount + 1;
        }

        emit informationsUpdated(sender);
    }
}

void ProcessEngine::connectToSocket(SocketIO* sender)
{
    connect(sender, SIGNAL(dataReceived(QList<MessageInfos>)), this, SLOT(processData(QList<MessageInfos>)));
}

void ProcessEngine::processData(QList<MessageInfos> messages)
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());

    foreach (const MessageInfos &data, messages)
        processMessage(data, sender);

    processUpdateRequest(sender);
}

bool ProcessEngine::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = false;
    QMapIterator<ModuleType, AbstractModule*> module(m_modules);
    while (module.hasNext())
    {
        module.next();
        if(module.value()->processMessage(data, sender))
            messageFound = true;
    }

    Reader reader(data.messageData);

    switch (data.messageType)
    {
    case MessageEnum::TEXTINFORMATIONMESSAGE:
    {
        TextInformationMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, message.msgType*10000 + message.msgId));

        QString output = infoData->getText();

        output = ParamsDecoder::decodeParams(output, message.parameters);

        qDebug()<<"TextInformationMessage -"<<output<<" Params -"<<message.parameters;

        switch((TextInformationTypeEnum)infoData->getTypeId())
        {
        case TextInformationTypeEnum::TEXT_ENTITY_TALK:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_ERROR:
            alert(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT:
            action(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT_LOG:
            info(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_MESSAGE:
            info(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_POPUP:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_PVP:
            break;

        case TextInformationTypeEnum::TEXT_LIVING_OBJECT:
            break;
        }
    }
        break;

    case MessageEnum::BASICTIMEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVERSETTINGSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVEROPTIONALFEATURESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::BASICNOOPERATIONMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::BASICACKMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::PRISMSLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVERSESSIONCONSTANTSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ACCOUNTCAPABILITIESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ENABLEDCHANNELSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SPELLLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SHORTCUTBARCONTENTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SPOUSESTATUSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ACHIEVEMENTLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::CHARACTERCAPABILITIESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ALMANACHCALENDARDATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::MAILSTATUSMESSAGE:
        messageFound = true;
        break;
    }

    if (!messageFound)
        qDebug()<<"MESSAGE PROCESS - Aucun support du message -"<<MessageUtils::getName(data.messageType)<<"- ID :"<<(int)data.messageType<<"\n";

    return messageFound;
}
