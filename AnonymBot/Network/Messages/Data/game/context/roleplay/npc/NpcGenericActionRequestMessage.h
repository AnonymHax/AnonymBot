#ifndef NPCGENERICACTIONREQUESTMESSAGE_H
#define NPCGENERICACTIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NpcGenericActionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NpcGenericActionRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NpcGenericActionRequestMessage(Reader *param1);
  NpcGenericActionRequestMessage();

  int npcId;
  uint npcActionId;
  int npcMapId;
};

#endif // NPCGENERICACTIONREQUESTMESSAGE_H