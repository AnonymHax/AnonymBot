#ifndef ALLIANCEINVITATIONANSWERMESSAGE_H
#define ALLIANCEINVITATIONANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceInvitationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInvitationAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInvitationAnswerMessage(Reader *param1);
  AllianceInvitationAnswerMessage();

  bool accept;
};

#endif // ALLIANCEINVITATIONANSWERMESSAGE_H