#ifndef RAWDATAMODULE_H
#define RAWDATAMODULE_H

#include "Public.h"
#include "AbstractServerModule.h"
#include "Network/SocketIO.h"
#include "Network/ServerMessages/RawResolveRequestMessage.h"
#include "Network/ServerMessages/RawResolveMessage.h"
#include "Network/ServerMessages/RawResolveFailureMessage.h"

struct RawDataTranslateRequest
{
    QByteArray rawFile;
    SocketIO* sender;
    QString ticket;
    int index;
    bool hasBeenSent = false;
};

class RawDataModule : public QObject, public AbstractServerModule
{

    Q_OBJECT
public:
    RawDataModule();

    virtual bool processMessage(const ServerMessageInfos &data);
    int requestTranslate(SocketIO* sender,  const QByteArray &rawFile, const QString &ticket);

protected:
    virtual void serverConnectionEstablished();
    virtual void serverConnectionFailed();

signals:
    void translateFailure(SocketIO *sender, int requestIndex, FailureReasonsEnum reason);
    void translateSucess(SocketIO *sender, int requestIndex, QList<int> answerData);
    void serverConnectionFailed(SocketIO *sender);

private:
    void processRequests();

    QList<RawDataTranslateRequest> m_requests;
    int m_nextIndex;
};


#endif // RAWDATAMODULE_H
