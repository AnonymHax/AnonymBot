#ifndef ALLIANCEBULLETINSETERRORMESSAGE_H
#define ALLIANCEBULLETINSETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class AllianceBulletinSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceBulletinSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceBulletinSetErrorMessage(Reader *param1);
  AllianceBulletinSetErrorMessage();
};

#endif // ALLIANCEBULLETINSETERRORMESSAGE_H