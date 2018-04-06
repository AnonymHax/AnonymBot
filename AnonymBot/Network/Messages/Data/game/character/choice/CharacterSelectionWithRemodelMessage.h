#ifndef CHARACTERSELECTIONWITHREMODELMESSAGE_H
#define CHARACTERSELECTIONWITHREMODELMESSAGE_H

#include "Network/Classes/Data/game/character/choice/RemodelingInformation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/choice/CharacterSelectionMessage.h"
#include "Network/Classes/Data/game/character/choice/RemodelingInformation.h"

class CharacterSelectionWithRemodelMessage : public CharacterSelectionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectionWithRemodelMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectionWithRemodelMessage(Reader *param1);
  CharacterSelectionWithRemodelMessage();

  RemodelingInformation remodel;
};

#endif // CHARACTERSELECTIONWITHREMODELMESSAGE_H