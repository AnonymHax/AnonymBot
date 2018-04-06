#ifndef SERVERSESSIONCONSTANTSMESSAGE_H
#define SERVERSESSIONCONSTANTSMESSAGE_H

#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/ClassManager.h"

class ServerSessionConstantsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSessionConstantsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSessionConstantsMessage(Reader *param1);
  ServerSessionConstantsMessage();

  QList<QSharedPointer<ServerSessionConstant>> variables;
};

#endif // SERVERSESSIONCONSTANTSMESSAGE_H