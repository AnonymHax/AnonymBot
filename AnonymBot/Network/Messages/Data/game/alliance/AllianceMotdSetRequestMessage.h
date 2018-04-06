#ifndef ALLIANCEMOTDSETREQUESTMESSAGE_H
#define ALLIANCEMOTDSETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

class AllianceMotdSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceMotdSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceMotdSetRequestMessage(Reader *param1);
  AllianceMotdSetRequestMessage();

  QString content;
};

#endif // ALLIANCEMOTDSETREQUESTMESSAGE_H