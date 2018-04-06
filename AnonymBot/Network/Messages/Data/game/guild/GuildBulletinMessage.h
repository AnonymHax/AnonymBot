#ifndef GUILDBULLETINMESSAGE_H
#define GUILDBULLETINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/BulletinMessage.h"

class GuildBulletinMessage : public BulletinMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildBulletinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildBulletinMessage(Reader *param1);
  GuildBulletinMessage();
};

#endif // GUILDBULLETINMESSAGE_H