#include "RawDataModule.h"

RawDataModule::RawDataModule():
    m_nextIndex(0)
{
}

bool RawDataModule::processMessage(const ServerMessageInfos &data)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case ServerMessageEnum::RAWRESOLVEMESSAGE:
    {
        RawResolveMessage message;
        message.deserialize(&reader);

        bool hasFound = false;
        int requestedIndex = message.index;
        int position = 0;

        for(position = 0; position < m_requests.size(); position++)
        {
            if(m_requests[position].index == requestedIndex)
            {
                hasFound = true;
                break;
            }
        }

        if(hasFound)
        {
            emit translateSucess(m_requests[position].sender, message.index, message.data);
            m_requests.removeAt(position);
        }

        else
            qDebug()<<"ERREUR - RawDataManager - N'a pas trouvé de request associée à l'index"<<requestedIndex;
    }
        break;

    case ServerMessageEnum::RAWRESOLVEFAILUREMESSAGE:
    {
        RawResolveFailureMessage message;
        message.deserialize(&reader);

        bool hasFound = false;
        int requestedIndex = message.index;
        int position = 0;

        for(position = 0; position < m_requests.size(); position++)
        {
            if(m_requests[position].index == requestedIndex)
            {
                hasFound = true;
                break;
            }
        }

        if(hasFound)
        {
            emit translateFailure(m_requests[position].sender, message.index, message.reason);
            m_requests.removeAt(position);
        }

        else
            qDebug()<<"ERREUR - RawDataManager - N'a pas trouvé de request associée à l'index"<<requestedIndex;
    }
        break;
    }

    return messageFound;
}

int RawDataModule::requestTranslate(SocketIO *sender, const QByteArray &rawFile, const QString &ticket)
{
    RawDataTranslateRequest request;
    request.sender = sender;
    request.rawFile = rawFile;
    request.ticket = ticket;
    request.index = m_nextIndex;

    m_requests<<request;

    processRequests();

    m_nextIndex++;

    return m_nextIndex-1;
}

void RawDataModule::serverConnectionEstablished()
{
    processRequests();
}

void RawDataModule::serverConnectionFailed()
{
    foreach(const RawDataTranslateRequest request, m_requests)
        emit serverConnectionFailed(request.sender);

    m_requests.clear();
}

void RawDataModule::processRequests()
{
    for(int i = 0; i < m_requests.size(); i++)
    {
        if(!m_requests.isEmpty() && ServerHandlerSingleton::get()->isConnected())
        {
            if(!m_requests[i].hasBeenSent)
            {
                RawResolveRequestMessage request;

                request.content = m_requests[i].rawFile;
                request.index = m_requests[i].index;
                request.ticket = m_requests[i].ticket;

                ServerHandlerSingleton::get()->send(request);

                m_requests[i].hasBeenSent = true;

                qDebug()<<"RawDataManager - Requete envoyée à AnonymServer";
            }
        }

        else if(!m_requests.isEmpty() && !ServerHandlerSingleton::get()->isConnected())
        {
            ServerHandlerSingleton::get()->connect();
            return;
        }
    }
}

