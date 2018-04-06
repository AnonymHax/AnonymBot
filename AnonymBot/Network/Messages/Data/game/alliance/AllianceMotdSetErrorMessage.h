#ifndef ALLIANCEMOTDSETERRORMESSAGE_H
#define ALLIANCEMOTDSETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class AllianceMotdSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceMotdSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceMotdSetErrorMessage(Reader *param1);
  AllianceMotdSetErrorMessage();
};

#endif // ALLIANCEMOTDSETERRORMESSAGE_H