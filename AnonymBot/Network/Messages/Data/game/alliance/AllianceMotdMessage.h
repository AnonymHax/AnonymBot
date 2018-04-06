#ifndef ALLIANCEMOTDMESSAGE_H
#define ALLIANCEMOTDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeMessage.h"

class AllianceMotdMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceMotdMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceMotdMessage(Reader *param1);
  AllianceMotdMessage();
};

#endif // ALLIANCEMOTDMESSAGE_H