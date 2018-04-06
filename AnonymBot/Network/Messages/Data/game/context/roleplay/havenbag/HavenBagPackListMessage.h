#ifndef HAVENBAGPACKLISTMESSAGE_H
#define HAVENBAGPACKLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HavenBagPackListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HavenBagPackListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HavenBagPackListMessage(Reader *param1);
  HavenBagPackListMessage();

  QList<int> packIds;
};

#endif // HAVENBAGPACKLISTMESSAGE_H