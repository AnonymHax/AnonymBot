#ifndef GUILDBULLETINSETREQUESTMESSAGE_H
#define GUILDBULLETINSETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

class GuildBulletinSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildBulletinSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildBulletinSetRequestMessage(Reader *param1);
  GuildBulletinSetRequestMessage();

  QString content;
  bool notifyMembers;
};

#endif // GUILDBULLETINSETREQUESTMESSAGE_H