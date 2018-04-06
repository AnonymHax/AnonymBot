#ifndef NPCGENERICACTIONFAILUREMESSAGE_H
#define NPCGENERICACTIONFAILUREMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NpcGenericActionFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NpcGenericActionFailureMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NpcGenericActionFailureMessage(Reader *param1);
  NpcGenericActionFailureMessage();
};

#endif // NPCGENERICACTIONFAILUREMESSAGE_H