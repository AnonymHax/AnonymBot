#ifndef ENTITYTALKMESSAGE_H
#define ENTITYTALKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EntityTalkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EntityTalkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EntityTalkMessage(Reader *param1);
  EntityTalkMessage();

  double entityId;
  uint textId;
  QList<QString> parameters;
};

#endif // ENTITYTALKMESSAGE_H