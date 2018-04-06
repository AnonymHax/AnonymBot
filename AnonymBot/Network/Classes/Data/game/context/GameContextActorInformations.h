#ifndef GAMECONTEXTACTORINFORMATIONS_H
#define GAMECONTEXTACTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/ClassManager.h"

class GameContextActorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextActorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextActorInformations(Reader *param1);
  GameContextActorInformations();
  bool operator==(const GameContextActorInformations &compared);

  double contextualId;
  QSharedPointer<EntityLook> look;
  QSharedPointer<EntityDispositionInformations> disposition;
};

#endif // GAMECONTEXTACTORINFORMATIONS_H