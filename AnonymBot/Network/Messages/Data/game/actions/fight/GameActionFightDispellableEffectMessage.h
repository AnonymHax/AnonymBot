#ifndef GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H

#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/ClassManager.h"

class GameActionFightDispellableEffectMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDispellableEffectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDispellableEffectMessage(Reader *param1);
  GameActionFightDispellableEffectMessage();

  QSharedPointer<AbstractFightDispellableEffect> effect;
};

#endif // GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H