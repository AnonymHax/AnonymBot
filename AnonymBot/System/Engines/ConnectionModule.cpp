#include "ConnectionModule.h"

ConnectionModule::ConnectionModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractModule(ModuleType::CONNECTION, connectionsData)
{
    QObject::connect(&m_rawDataModule, SIGNAL(translateSucess(SocketIO*,int,QList<int>)), this, SLOT(processAntiBotReply(SocketIO*,int,QList<int>)));
    QObject::connect(&m_rawDataModule, SIGNAL(translateFailure(SocketIO*,int,FailureReasonsEnum)), this, SLOT(processAntiBotFailure(SocketIO*,int,FailureReasonsEnum)));
    QObject::connect(&m_rawDataModule, SIGNAL(serverConnectionFailed(SocketIO*)), this, SLOT(processBotServerConnectionFailure(SocketIO*)));
}

void ConnectionModule::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
    m_botData[sender].connectionData.greetingMessageIsInitialized = 0;
    m_botData[sender].connectionData.sequenceNumber = 0;
}

bool ConnectionModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);
    
    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;
        
    case MessageEnum::PROTOCOLREQUIRED:
        break;

    case MessageEnum::HELLOCONNECTMESSAGE:
    {
        HelloConnectMessage message;
        message.deserialize(&reader);
        
        QByteArray keyRaw;
        foreach (int number, message.key)
            keyRaw.append(number);
        
        RsaManager keyDecoder;
        QByteArray decodedPublicKey = keyDecoder.publicKeyDecrypt(keyRaw);
        keyDecoder.setLoginPublicKey(decodedPublicKey);

        IdentificationMessage answer;
        answer.autoconnect = false;
        answer.useCertificate = false;
        answer.useLoginToken = false;
        
        answer.lang = "fr";
        answer.version.major = (int)DofusVersion::MAJOR;
        answer.version.minor = (int)DofusVersion::MINOR;
        answer.version.patch = (int)DofusVersion::PATCH;
        answer.version.release = (int)DofusVersion::RELEASE;
        answer.version.revision = (int)DofusVersion::REVISION;
        answer.version.buildType = (int)BuildTypeEnum::RELEASE;
        answer.version.install = (int)ClientInstallTypeEnum::CLIENT_BUNDLE;
        answer.version.technology = (int)ClientTechnologyEnum::CLIENT_AIR;
        m_botData[sender].connectionData.aesKey = AesManager::generateRandomAESKey();

        answer.credentials = keyDecoder.generateCredentials(message.salt,
                                                            m_botData[sender].connectionData.aesKey,
                                                            m_botData[sender].connectionData.connectionInfos.login,
                                                            m_botData[sender].connectionData.connectionInfos.password);
        sender->send(answer);
    }
        break;
        
        
    case MessageEnum::SERVERSLISTMESSAGE:
    {
        ServersListMessage message;
        message.deserialize(&reader);

        foreach (const GameServerInformations &infos, message.servers)
        {
            if (infos.id == m_botData[sender].connectionData.connectionInfos.serverId)
            {
                QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId));

                switch ((ServerStatusEnum)infos.status)
                {
                case ServerStatusEnum::OFFLINE:
                {
                    alert(sender)<<"Serveur"<<server->getName()<<"hors-ligne";
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                    
                case ServerStatusEnum::STARTING:
                {
                    alert(sender)<<"Serveur"<<server->getName()<<"en cours de démarrage";
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                    
                case ServerStatusEnum::ONLINE:
                {
                    ServerSelectionMessage answer;
                    answer.serverId = m_botData[sender].connectionData.connectionInfos.serverId;
                    sender->send(answer);
                }
                    break;
                    
                case ServerStatusEnum::NOJOIN:
                {
                    alert(sender)<<"Impossible de se joindre au serveur"<<server->getName();
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                    
                case ServerStatusEnum::SAVING:
                {
                    alert(sender)<<"Serveur"<<server->getName()<<"en cours de sauvegarde";
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                    
                case ServerStatusEnum::STOPING:
                {
                    alert(sender)<<"Serveur"<<server->getName()<<"en cours d'extinction";
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                    
                case ServerStatusEnum::FULL:
                {
                    alert(sender)<<"Serveur"<<server->getName()<<"complet";
                    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                    sender->disconnect();
                }
                    break;
                }
            }
        }
    }
        break;
        
    case MessageEnum::LOGINQUEUESTATUSMESSAGE:
    {
        LoginQueueStatusMessage message;
        message.deserialize(&reader);
        
        if (message.position != 0)
            info(sender)<<message.position<<"/"<<message.total<<"dans la file d'attente du serveur principal";
    }
        break;
        
    case MessageEnum::IDENTIFICATIONSUCCESSMESSAGE:
    {
        IdentificationSuccessMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.accountId = message.accountId;
        m_botData[sender].playerData.subscriptionEndDate = message.subscriptionEndDate;
    }
        break;

    case MessageEnum::IDENTIFICATIONFAILEDMESSAGE:
    {
        IdentificationFailedMessage message;
        message.deserialize(&reader);
        
        QString failReason;
        switch ((IdentificationFailureReasonEnum)message.reason)
        {
        case IdentificationFailureReasonEnum::WRONG_CREDENTIALS:
            failReason = "Mauvais identifiants";
            break;
            
        case IdentificationFailureReasonEnum::BANNED:
            failReason = "Le compte est banni définitivement - N'hesitez pas à le reporter sur le forum";
            break;
            
        case IdentificationFailureReasonEnum::KICKED:
            failReason = "Expulsé";
            break;
            
        case IdentificationFailureReasonEnum::IN_MAINTENANCE:
            failReason = "En maintenance";
            break;
            
        case IdentificationFailureReasonEnum::TOO_MANY_ON_IP:
            failReason = "Trop d'adresses ip sur le compte";
            break;
            
        case IdentificationFailureReasonEnum::TIME_OUT:
            failReason = "Temps de connexion écoulé";
            break;
            
        case IdentificationFailureReasonEnum::BAD_IPRANGE:
            failReason = "Adresse ip incorrecte";
            break;
            
        case IdentificationFailureReasonEnum::CREDENTIALS_RESET:
            failReason = "Reset des identifiants";
            break;
            
        case IdentificationFailureReasonEnum::EMAIL_UNVALIDATED:
            failReason = "Email du compte non-verifié";
            break;
            
        case IdentificationFailureReasonEnum::OTP_TIMEOUT:
            failReason = "Temps de connexion écoulé";
            break;
            
        case IdentificationFailureReasonEnum::SERVICE_UNAVAILABLE:
            failReason = "Service non disponible";
            break;
            
        case IdentificationFailureReasonEnum::UNKNOWN_AUTH_ERROR:
            failReason = "Erreur de connexion inconnue";
            break;
            
        case IdentificationFailureReasonEnum::SPARE:
            failReason = "Erreur de connexion inconnue : Spare";
            break;
        }
        
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        
        alert(sender)<<"L'identification a échouée - RAISON :"<<failReason;
        sender->disconnect();
    }
        break;
        
    case MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE:
    {
        IdentificationFailedForBadVersionMessage message;
        message.deserialize(&reader);
        
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        
        alert(sender)<<"Mauvaise version du jeu enregistrée - mettre à jour le bot";
        alert(sender)<<"Requis - MAJOR"<<message.requiredVersion.major
                    <<"MINOR"<<message.requiredVersion.minor
                   <<"PATCH"<<message.requiredVersion.patch
                  <<"RELEASE"<<message.requiredVersion.release
                 <<"REVISION"<<message.requiredVersion.revision;

        qDebug()<<"Mauvaise version du jeu enregistrée - mettre à jour le bot";
        qDebug()<<"Requis - MAJOR"<<message.requiredVersion.major
                    <<"MINOR"<<message.requiredVersion.minor
                   <<"PATCH"<<message.requiredVersion.patch
                  <<"RELEASE"<<message.requiredVersion.release
                 <<"REVISION"<<message.requiredVersion.revision;
        
        sender->disconnect();
    }
        break;
        
    case MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE:
    {
        IdentificationFailedBannedMessage message;
        message.deserialize(&reader);
        
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        
        alert(sender)<<"Ce compte a été banni jusqu'au"<<
                       dateToString(message.banEndDate)<<
                       "- N'hesitez pas à le reporter sur le forum";
    }
        break;
        
    case MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE:
    {
        AccountLoggingKickedMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        
        QString alertMessage = "Ce compte a été banni pendant ";
        
        if(message.days == 1)
            alertMessage += "1 jour ";
        
        else if(message.days > 1)
            alertMessage += QString::number(message.days)+" jours ";
        
        if(message.days > 0 && message.hours > 0 && message.minutes == 0)
            alertMessage += "et ";
        
        if(message.hours == 1)
            alertMessage += "1 heure ";
        
        else if(message.hours > 1)
            alertMessage += QString::number(message.hours)+" heures ";
        
        if(message.days > 0 || message.hours > 0 && message.minutes > 0)
            alertMessage += "et ";
        
        if(message.minutes == 1)
            alertMessage += "1 minute";
        
        else if(message.minutes > 1)
            alertMessage += QString::number(message.days)+" minutes";
        
        
        alert(sender)<<alertMessage<<"- N'hesitez pas à le reporter sur le forum";
    }
        break;
        
    case MessageEnum::CREDENTIALSACKNOWLEDGEMENTMESSAGE:
        break;
        
    case MessageEnum::SELECTEDSERVERREFUSEDMESSAGE:
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        alert(sender)<<"Connexion au serveur refusée";
    }
        break;
        
    case MessageEnum::SELECTEDSERVERDATAMESSAGE:
    {
        SelectedServerDataMessage message;
        message.deserialize(&reader);
        
        QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId));
        info(sender)<<"Connexion au serveur de jeu <b>"<<server->getName()<<"</b>";
        qDebug()<<"Server IP: "<<message.address;
        qDebug()<<"Ticket: "<<message.ticket;

        Writer w;
        Reader tmp;
        QByteArray data;
        for (int i = 0; i < message.ticket.size(); i++)
            w.writeByte(message.ticket[i]);

        data = w.getBuffer();

        QByteArray _IV;
        tmp.setBuffer(m_botData[sender].connectionData.aesKey);
        _IV = tmp.readBytes(0, 16);
        std::vector<byte> IV(_IV.begin(), _IV.end());

        AesManager aes;
        std::string t(aes.AESDecrypt(data.data(), data.size(), m_botData[sender].connectionData.aesKey.data(), m_botData[sender].connectionData.aesKey.size(), IV));

        m_botData[sender].connectionData.ticket = QString::fromStdString(t);
        sender->switchServer(message.address);
    }
        break;
        
    case MessageEnum::HELLOGAMEMESSAGE:
    {
        AuthenticationTicketMessage answer;
        answer.lang = "fr";
        answer.ticket = m_botData[sender].connectionData.ticket;
        sender->send(answer);
    }
        break;
        
    case MessageEnum::AUTHENTICATIONTICKETACCEPTEDMESSAGE:
    {
        qDebug()<<"CONNEXION - Communication avec le serveur"<<
                  qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId))->getName()
               <<"etablie";
    }
        break;
        
    case MessageEnum::TRUSTSTATUSMESSAGE:
    {
        CharactersListRequestMessage answer;
        sender->send(answer);
    }
        break;
        
    case MessageEnum::QUEUESTATUSMESSAGE:
    {
        QueueStatusMessage message;
        message.deserialize(&reader);
        
        if (message.position != 0)
            info(sender)<<message.position<<"/"<<message.total<<"dans la file d'attente du serveur de jeu";
    }
        break;
        
    case MessageEnum::BASICCHARACTERSLISTMESSAGE:
    {
        BasicCharactersListMessage message;
        message.deserialize(&reader);

        foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
        {
            debug(sender)<<"\t->"<<infos->name<<"niveau"<<infos->level;

            if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
            {
                m_botData[sender].mapData.botId = infos->id;
                m_botData[sender].playerData.breed = (BreedEnum)infos->breed;
            }
        }

    }
        break;

    case MessageEnum::CHARACTERSLISTMESSAGE:
    case MessageEnum::CHARACTERSLISTWITHMODIFICATIONSMESSAGE:
    {
        BasicCharactersListMessage message;
        message.deserialize(&reader);
        
        debug(sender)<<"Liste des personnages sur le serveur:";
        foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
        {
            debug(sender)<<"\t->"<<infos->name<<"niveau"<<infos->level;
            
            if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
            {
                m_botData[sender].mapData.botId = infos->id;
                m_botData[sender].playerData.breed = (BreedEnum)infos->breed;

                qDebug() << "PENIS" << EntityLookParser::getUrl(infos->entityLook, EntityRendererType::FULL,
                                                                EntityRendererOrientation::PROFILE);
            }
        }
        
        if (m_botData[sender].mapData.botId != INVALID)
        {
            CharacterSelectionMessage answer;
            answer.id = m_botData[sender].mapData.botId;
            sender->send(answer);
        }
        
        else
            alert(sender)<<"Le personnage"<<m_botData[sender].connectionData.connectionInfos.character<<"n'existe pas ou n'est pas sur ce serveur";
    }
        break;
        
    case MessageEnum::CHARACTERSELECTEDFORCEMESSAGE:
    {
        CharacterSelectedForceMessage message;
        message.deserialize(&reader);

        CharacterSelectedForceReadyMessage answer;
        sender->send(answer);

        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;
        
        FriendsGetListMessage answer1;
        sender->send(answer1);
        
        IgnoredGetListMessage answer2;
        sender->send(answer2);
        
        QString randomChars;
        for (int i = 0; i < 20; i++)
        {
            int random =  qCeil(rand()%101);
            
            if (random <= 40)
                randomChars += char(qFloor(rand() % 27) + 65);
            
            else if (random <= 80)
                randomChars +=char(qFloor(rand() % 27) + 97);
            
            else
                randomChars += char(qFloor(rand() % 11) + 48);
        }
        
        int signature = 0;
        for (int i = 0; i < randomChars.size(); i++)
            signature += (int(randomChars.toStdString()[i]) % 16);
        
        QString checksum = QByteArray(1,char(signature%16)).toHex().remove(0,1).toUpper();
        QString key = randomChars + checksum;
        
        ClientKeyMessage answer3;
        answer3.key = key;
        sender->send(answer3);
        
        GameContextCreateRequestMessage answer4;
        sender->send(answer4);
        
        ChannelEnablingMessage answer5;
        for (int i = 0; i < 13; i++)
            answer5.channel = i, answer5.enable = true, sender->send(answer5);
    }
        break;
        
    case MessageEnum::TEXTINFORMATIONMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized == 0)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;
            
            FriendsGetListMessage answer1;
            sender->send(answer1);
            
            IgnoredGetListMessage answer2;
            sender->send(answer2);
            
            QString randomChars;
            for (int i = 0; i < 20; i++)
            {
                int random =  qCeil(rand()%101);
                
                if (random <= 40)
                    randomChars += char(qFloor(rand() % 27) + 65);
                
                else if (random <= 80)
                    randomChars +=char(qFloor(rand() % 27) + 97);
                
                else
                    randomChars += char(qFloor(rand() % 11) + 48);
            }
            
            int signature = 0;
            for (int i = 0; i < randomChars.size(); i++)
                signature += (int(randomChars.toStdString()[i]) % 16);
            
            QString checksum = QByteArray(1,char(signature%16)).toHex().remove(0,1).toUpper();
            QString key = randomChars + checksum;
            
            ClientKeyMessage answer3;
            answer3.key = key;
            sender->send(answer3);
            
            GameContextCreateRequestMessage answer4;
            sender->send(answer4);
            
            ChannelEnablingMessage answer5;
            for (int i = 0; i < 13; i++)
                answer5.channel = i, answer5.enable = true, sender->send(answer5);
        }
        
        else if (m_botData[sender].connectionData.greetingMessageIsInitialized == 1)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }
    }
        break;
        
    case MessageEnum::SEQUENCENUMBERREQUESTMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized > 1)
        {
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }
    }
        break;
        
    case MessageEnum::BASICLATENCYSTATSREQUESTMESSAGE:
    {
        BasicLatencyStatsMessage answer;
        qDebug()<<"Stats connexion (en ms) - AVG"<<sender->getLatencyAverage()<<"SAMPLES"<<sender->getSampleCount()<<"MAX"<<sender->getMaxLatency();
        
        if(sender->getLatencyAverage() > 32767)
            answer.latency = 32767;
        else
            answer.latency = sender->getLatencyAverage();
        
        answer.sampleCount = sender->getSampleCount();
        answer.max = sender->getMaxLatency();
        
        //sender->send(answer);
    }
        break;
        
    case MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE:
        break;
        
    case MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE:
        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;
        break;
        
    case MessageEnum::RAWDATAMESSAGE:
    {
        RawDataMessage message;
        message.deserialize(&reader);

       QFile a("/Users/Victor/Desktop/FDP.swf");
       a.open(QIODevice::WriteOnly);
       a.write(message.content);


        QList<int> data;
        CheckIntegrityMessage reply;
        for (int i = 0; i < 256; i++)
            data << i;

        reply.data = data;
        sender->send(reply);

        info(sender)<<"Communication avec <b>AnonymServer</b>";
        //m_botData[sender].connectionData.rawDataRequestIndex = m_rawDataModule.requestTranslate(sender, message.content, m_botData[sender].connectionData.ticket);
    }
        break;

    case MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE:
    {
        SystemMessageDisplayMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, 40000 + message.msgId));

        QString output = ParamsDecoder::decodeParams(infoData->getText(), message.parameters);

        qDebug()<<output;
        alert(sender)<<output;
    }
        break;
    }
    
    return messageFound;
}

SocketIO *ConnectionModule::addConnection(const ConnectionInfos &connectionInfos)
{
    QMapIterator<SocketIO*, BotData> i(m_botData);

    while(i.hasNext())
    {
        i.next();

        if(i.value().connectionData.connectionInfos.character == connectionInfos.character &&
                i.value().connectionData.connectionInfos.login == connectionInfos.login)
        {
            delete i.key();
            m_botData.remove(i.key());
            break;
        }
    }
    
    SocketIO *socket = new SocketIO;
    
    m_botData[socket].connectionData.connectionInfos = connectionInfos;

    connectionAdded(socket);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(hasConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(hasDisconnected()));
    
    return socket;
}

void ConnectionModule::removeConnection(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            disconnect(sender);

        m_botData.erase(m_botData.find(sender));

        delete sender;
    }
}

void ConnectionModule::reconnect(SocketIO *sender)
{
    info(sender)<<"Procédure de reconnexion initiée"<<QString::number(WAIT_TIME_CONNECTION/1000)<<"s...";

    m_botData[sender].connectionData.hasRequestedReconnection = true;

    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
        disconnect(sender);

    else if(m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
        connect(sender);
}

void ConnectionModule::setReconnectionAuto(SocketIO *sender, bool active)
{
    m_botData[sender].connectionData.reconnectionAuto = active;
}

void ConnectionModule::connect(SocketIO *sender)
{
    if(m_botData.contains(sender) &&  m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = false;
        sender->connect(false);
    }
    
    else if(!m_botData.contains(sender))
        qDebug()<<"ERREUR - ConnectionModule ne connait pas cette connexion";
}

void ConnectionModule::disconnect(SocketIO *sender)
{
    if (m_botData.contains(sender) && m_botData[sender].connectionData.connectionState != ConnectionState::DISCONNECTED)
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = true;
        sender->disconnect();
    }
    
    else
        qDebug()<<"ERREUR - ConnectionModule ne connait pas cette connexion";
}

void ConnectionModule::hasConnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());
    m_botData[sender].connectionData.timeElapsed.start();
    m_botData[sender].generalData.botState = INACTIVE_STATE;
    m_botData[sender].connectionData.hasRequestedReconnection = false;
}

void ConnectionModule::hasDisconnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());
    
    if(m_botData.contains(sender))
    {
        if(m_botData[sender].connectionData.hasRequestedDisconnection)
            alert(sender)<<"---------Fin de la connexion-------";
        
        else if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            alert(sender)<<"---------Rupture inattendue de la connexion-------";

        if((m_botData[sender].connectionData.hasRequestedDisconnection && m_botData[sender].connectionData.reconnectionAuto)
                || m_botData[sender].connectionData.hasRequestedReconnection)
        {
            m_botData[sender].connectionData.autoReconnectionTimer = QSharedPointer<QTimer>(new QTimer);
            m_botData[sender].connectionData.autoReconnectionTimer->setSingleShot(true);
            m_botData[sender].connectionData.autoReconnectionTimer->setInterval(WAIT_TIME_CONNECTION);
            m_botData[sender].connectionData.autoReconnectionTimer->start();
            QObject::connect(m_botData[sender].connectionData.autoReconnectionTimer.data(), SIGNAL(timeout()), this, SLOT(processReconnection()));

            info(sender)<<"Tentative de reconnexion dans"<<QString::number(WAIT_TIME_CONNECTION/1000)<<"s...";
        }

        
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        emit botDisconnected(sender);
    }
}

void ConnectionModule::processReconnection()
{
    QTimer *timer = static_cast<QTimer*>(QObject::sender());

    QMapIterator<SocketIO*, BotData> i(m_botData);

    while (i.hasNext())
    {
        i.next();

        if(i.value().connectionData.autoReconnectionTimer == timer)
        {
            connect(i.key());
            break;
        }
    }
}

void ConnectionModule::processAntiBotReply(SocketIO *sender, int requestIndex, QList<int> answerData)
{
    if(m_botData.contains(sender) && m_botData[sender].connectionData.rawDataRequestIndex == requestIndex)
    {
        if (!answerData.isEmpty())
        {
            CheckIntegrityMessage message;
            message.data = answerData;
            sender->send(message);
            qDebug()<<"ConnectionModule - CheckIntegrityMessage sent";
        }
    }
}

void ConnectionModule::processAntiBotFailure(SocketIO *sender, int requestIndex, FailureReasonsEnum reason)
{
    if(m_botData.contains(sender) && m_botData[sender].connectionData.rawDataRequestIndex == requestIndex)
    {
        switch(reason)
        {
        case FailureReasonsEnum::WRONGCREDENTIALS:
            alert(sender)<<"Le compte AnonymBot configuré n'existe pas";
            break;
            
        case FailureReasonsEnum::NOTPREMIUM:
            alert(sender)<<"Le compte AnonymBot configuré n'est pas premium";
            break;
            
        case FailureReasonsEnum::BANNED:
            alert(sender)<<"Le compte AnonymBot configuré a été banni";
            break;
        }
        
        m_botData[sender].connectionData.hasRequestedDisconnection = true;
        sender->disconnect();
        emit requestUpdate(sender);
    }
}

void ConnectionModule::processBotServerConnectionFailure(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        m_botData[sender].connectionData.hasRequestedDisconnection = true;
        alert(sender)<<"Impossible de joindre <b>AnonymServer</b> pour l'instant, veuillez réessayer dans quelques instants...";
        sender->disconnect();
    }
}
