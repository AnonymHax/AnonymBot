#ifndef ALLIANCEGUILDLEAVINGMESSAGE_H
#define ALLIANCEGUILDLEAVINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceGuildLeavingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceGuildLeavingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceGuildLeavingMessage(Reader *param1);
  AllianceGuildLeavingMessage();

  bool kicked;
  uint guildId;
};

#endif // ALLIANCEGUILDLEAVINGMESSAGE_H