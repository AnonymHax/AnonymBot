#ifndef GAMEACTIONFIGHTSPELLCASTMESSAGE_H
#define GAMEACTIONFIGHTSPELLCASTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/AbstractGameActionFightTargetedAbilityMessage.h"

class GameActionFightSpellCastMessage : public AbstractGameActionFightTargetedAbilityMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightSpellCastMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightSpellCastMessage(Reader *param1);
  GameActionFightSpellCastMessage();

  uint spellId;
  int spellLevel;
  QList<int> portalsIds;
};

#endif // GAMEACTIONFIGHTSPELLCASTMESSAGE_H