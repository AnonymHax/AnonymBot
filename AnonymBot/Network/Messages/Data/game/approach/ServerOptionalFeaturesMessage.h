#ifndef SERVEROPTIONALFEATURESMESSAGE_H
#define SERVEROPTIONALFEATURESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ServerOptionalFeaturesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerOptionalFeaturesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerOptionalFeaturesMessage(Reader *param1);
  ServerOptionalFeaturesMessage();

  QList<uint> features;
};

#endif // SERVEROPTIONALFEATURESMESSAGE_H