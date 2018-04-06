#ifndef ALLIANCEINVITEDMESSAGE_H
#define ALLIANCEINVITEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"

class AllianceInvitedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInvitedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInvitedMessage(Reader *param1);
  AllianceInvitedMessage();

  double recruterId;
  QString recruterName;
  QSharedPointer<BasicNamedAllianceInformations> allianceInfo;
};

#endif // ALLIANCEINVITEDMESSAGE_H