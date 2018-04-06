#ifndef CHARACTERSLISTWITHMODIFICATIONSMESSAGE_H
#define CHARACTERSLISTWITHMODIFICATIONSMESSAGE_H

#include "Network/Classes/Data/game/character/choice/CharacterToRecolorInformation.h"
#include "Network/Classes/Data/game/character/choice/CharacterToRelookInformation.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/choice/CharactersListMessage.h"
#include "Network/Classes/Data/game/character/choice/CharacterToRecolorInformation.h"
#include "Network/Classes/Data/game/character/choice/CharacterToRelookInformation.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"

class CharactersListWithModificationsMessage : public CharactersListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharactersListWithModificationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharactersListWithModificationsMessage(Reader *param1);
  CharactersListWithModificationsMessage();

  QList<CharacterToRecolorInformation> charactersToRecolor;
  QList<int> charactersToRename;
  QList<int> unusableCharacters;
  QList<CharacterToRelookInformation> charactersToRelook;
};

#endif // CHARACTERSLISTWITHMODIFICATIONSMESSAGE_H