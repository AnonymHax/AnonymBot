#ifndef CHARACTERFIRSTSELECTIONMESSAGE_H
#define CHARACTERFIRSTSELECTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/choice/CharacterSelectionMessage.h"

class CharacterFirstSelectionMessage : public CharacterSelectionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterFirstSelectionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterFirstSelectionMessage(Reader *param1);
  CharacterFirstSelectionMessage();

  bool doTutorial;
};

#endif // CHARACTERFIRSTSELECTIONMESSAGE_H