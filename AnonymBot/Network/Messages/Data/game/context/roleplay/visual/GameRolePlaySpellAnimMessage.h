#ifndef GAMEROLEPLAYSPELLANIMMESSAGE_H
#define GAMEROLEPLAYSPELLANIMMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlaySpellAnimMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlaySpellAnimMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlaySpellAnimMessage(Reader *param1);
  GameRolePlaySpellAnimMessage();

  double casterId;
  uint targetCellId;
  uint spellId;
  int spellLevel;
};

#endif // GAMEROLEPLAYSPELLANIMMESSAGE_H