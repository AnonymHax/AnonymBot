#ifndef CHARACTERSLISTWITHREMODELINGMESSAGE_H
#define CHARACTERSLISTWITHREMODELINGMESSAGE_H

#include "Network/Classes/Data/game/character/choice/CharacterToRemodelInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/choice/CharactersListMessage.h"
#include "Network/Classes/Data/game/character/choice/CharacterToRemodelInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"

class CharactersListWithRemodelingMessage : public CharactersListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharactersListWithRemodelingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharactersListWithRemodelingMessage(Reader *param1);
  CharactersListWithRemodelingMessage();

  QList<CharacterToRemodelInformations> charactersToRemodel;
};

#endif // CHARACTERSLISTWITHREMODELINGMESSAGE_H