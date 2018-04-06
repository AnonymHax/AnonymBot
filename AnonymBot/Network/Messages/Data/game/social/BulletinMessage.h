#ifndef BULLETINMESSAGE_H
#define BULLETINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeMessage.h"

class BulletinMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BulletinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BulletinMessage(Reader *param1);
  BulletinMessage();

  uint lastNotifiedTimestamp;
};

#endif // BULLETINMESSAGE_H