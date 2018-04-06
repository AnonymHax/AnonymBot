#ifndef CHARACTERSLISTMESSAGE_H
#define CHARACTERSLISTMESSAGE_H

#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/choice/BasicCharactersListMessage.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"

class CharactersListMessage : public BasicCharactersListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharactersListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharactersListMessage(Reader *param1);
  CharactersListMessage();

  bool hasStartupActions;
};

#endif // CHARACTERSLISTMESSAGE_H