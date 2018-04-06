#ifndef ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H
#define ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementDetailedListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementDetailedListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementDetailedListRequestMessage(Reader *param1);
  AchievementDetailedListRequestMessage();

  uint categoryId;
};

#endif // ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H