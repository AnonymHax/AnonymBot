#ifndef ALLIANCEKICKREQUESTMESSAGE_H
#define ALLIANCEKICKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceKickRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceKickRequestMessage(Reader *param1);
  AllianceKickRequestMessage();

  uint kickedId;
};

#endif // ALLIANCEKICKREQUESTMESSAGE_H