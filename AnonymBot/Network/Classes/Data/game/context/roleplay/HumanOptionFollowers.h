#ifndef HUMANOPTIONFOLLOWERS_H
#define HUMANOPTIONFOLLOWERS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/IndexedEntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/look/IndexedEntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/look/IndexedEntityLook.h"

class HumanOptionFollowers : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionFollowers(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionFollowers(Reader *param1);
  HumanOptionFollowers();
  bool operator==(const HumanOptionFollowers &compared);

  QList<QSharedPointer<IndexedEntityLook>> followingCharactersLook;
};

#endif // HUMANOPTIONFOLLOWERS_H