#ifndef CHARACTERLEVELUPINFORMATIONMESSAGE_H
#define CHARACTERLEVELUPINFORMATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/stats/CharacterLevelUpMessage.h"

class CharacterLevelUpInformationMessage : public CharacterLevelUpMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterLevelUpInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterLevelUpInformationMessage(Reader *param1);
  CharacterLevelUpInformationMessage();

  QString name;
  double id;
};

#endif // CHARACTERLEVELUPINFORMATIONMESSAGE_H