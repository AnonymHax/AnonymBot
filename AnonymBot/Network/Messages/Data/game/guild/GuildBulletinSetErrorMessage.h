#ifndef GUILDBULLETINSETERRORMESSAGE_H
#define GUILDBULLETINSETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class GuildBulletinSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildBulletinSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildBulletinSetErrorMessage(Reader *param1);
  GuildBulletinSetErrorMessage();
};

#endif // GUILDBULLETINSETERRORMESSAGE_H