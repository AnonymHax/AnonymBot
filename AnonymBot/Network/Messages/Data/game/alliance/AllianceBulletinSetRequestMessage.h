#ifndef ALLIANCEBULLETINSETREQUESTMESSAGE_H
#define ALLIANCEBULLETINSETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

class AllianceBulletinSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceBulletinSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceBulletinSetRequestMessage(Reader *param1);
  AllianceBulletinSetRequestMessage();

  QString content;
  bool notifyMembers;
};

#endif // ALLIANCEBULLETINSETREQUESTMESSAGE_H