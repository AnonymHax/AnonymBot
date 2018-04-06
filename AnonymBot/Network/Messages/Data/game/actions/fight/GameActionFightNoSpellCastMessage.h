#ifndef GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H
#define GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameActionFightNoSpellCastMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightNoSpellCastMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightNoSpellCastMessage(Reader *param1);
  GameActionFightNoSpellCastMessage();

  uint spellLevelId;
};

#endif // GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H