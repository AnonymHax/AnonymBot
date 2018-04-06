#ifndef FRIENDSPOUSEINFORMATIONS_H
#define FRIENDSPOUSEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class FriendSpouseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSpouseInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSpouseInformations(Reader *param1);
  FriendSpouseInformations();
  bool operator==(const FriendSpouseInformations &compared);

  uint spouseAccountId;
  double spouseId;
  QString spouseName;
  uint spouseLevel;
  int breed;
  int sex;
  QSharedPointer<EntityLook> spouseEntityLook;
  QSharedPointer<GuildInformations> guildInfo;
  int alignmentSide;
};

#endif // FRIENDSPOUSEINFORMATIONS_H