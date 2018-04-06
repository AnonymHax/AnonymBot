#ifndef ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H
#define ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceInvitationStateRecruterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInvitationStateRecruterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInvitationStateRecruterMessage(Reader *param1);
  AllianceInvitationStateRecruterMessage();

  QString recrutedName;
  uint invitationState;
};

#endif // ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H