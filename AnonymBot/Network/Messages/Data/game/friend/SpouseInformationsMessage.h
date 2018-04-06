#ifndef SPOUSEINFORMATIONSMESSAGE_H
#define SPOUSEINFORMATIONSMESSAGE_H

#include "Network/Classes/Data/game/friend/FriendSpouseInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/FriendSpouseInformations.h"
#include "Network/Classes/ClassManager.h"

class SpouseInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpouseInformationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpouseInformationsMessage(Reader *param1);
  SpouseInformationsMessage();

  QSharedPointer<FriendSpouseInformations> spouse;
};

#endif // SPOUSEINFORMATIONSMESSAGE_H