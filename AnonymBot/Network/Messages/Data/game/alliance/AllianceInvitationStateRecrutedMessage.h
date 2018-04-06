#ifndef ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H
#define ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceInvitationStateRecrutedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInvitationStateRecrutedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInvitationStateRecrutedMessage(Reader *param1);
  AllianceInvitationStateRecrutedMessage();

  uint invitationState;
};

#endif // ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H