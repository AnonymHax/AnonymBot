#ifndef ARENAFIGHTERLEAVEMESSAGE_H
#define ARENAFIGHTERLEAVEMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterBasicMinimalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterBasicMinimalInformations.h"

class ArenaFighterLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ArenaFighterLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ArenaFighterLeaveMessage(Reader *param1);
  ArenaFighterLeaveMessage();

  CharacterBasicMinimalInformations leaver;
};

#endif // ARENAFIGHTERLEAVEMESSAGE_H