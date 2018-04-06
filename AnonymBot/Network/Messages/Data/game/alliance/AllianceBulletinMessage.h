#ifndef ALLIANCEBULLETINMESSAGE_H
#define ALLIANCEBULLETINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/BulletinMessage.h"

class AllianceBulletinMessage : public BulletinMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceBulletinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceBulletinMessage(Reader *param1);
  AllianceBulletinMessage();
};

#endif // ALLIANCEBULLETINMESSAGE_H