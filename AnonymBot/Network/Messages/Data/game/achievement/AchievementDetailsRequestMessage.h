#ifndef ACHIEVEMENTDETAILSREQUESTMESSAGE_H
#define ACHIEVEMENTDETAILSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementDetailsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementDetailsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementDetailsRequestMessage(Reader *param1);
  AchievementDetailsRequestMessage();

  uint achievementId;
};

#endif // ACHIEVEMENTDETAILSREQUESTMESSAGE_H