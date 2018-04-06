#ifndef ALLIANCEINVITATIONMESSAGE_H
#define ALLIANCEINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceInvitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInvitationMessage(Reader *param1);
  AllianceInvitationMessage();

  double targetId;
};

#endif // ALLIANCEINVITATIONMESSAGE_H