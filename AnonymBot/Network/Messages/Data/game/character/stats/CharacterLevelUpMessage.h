#ifndef CHARACTERLEVELUPMESSAGE_H
#define CHARACTERLEVELUPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterLevelUpMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterLevelUpMessage(Reader *param1);
  CharacterLevelUpMessage();

  uint newLevel;
};

#endif // CHARACTERLEVELUPMESSAGE_H