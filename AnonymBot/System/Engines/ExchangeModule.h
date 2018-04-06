#ifndef EXCHANGEMODULE_H
#define EXCHANGEMODULE_H

/*!
 * \class ExchangeModule
 * \brief
 */

#include "Public.h"
#include "AbstractModule.h"

class ExchangeModule : public AbstractModule
{
public:
    ExchangeModule(QMap<SocketIO*, BotData> *connectionsData);

    virtual void reset(SocketIO *sender);

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    void setState(SocketIO *sender, bool state);
    bool isActive(SocketIO *sender) const;

    void addRequestedObject(SocketIO *sender, const RequestTradeObject &item);
    void removeRequestedObject(SocketIO *sender, uint objectGID);

private:
    void updateExchange(SocketIO *sender);
};

#endif // EXCHANGEMODULE_H
