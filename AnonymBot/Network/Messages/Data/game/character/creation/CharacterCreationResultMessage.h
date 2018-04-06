#ifndef CHARACTERCREATIONRESULTMESSAGE_H
#define CHARACTERCREATIONRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterCreationResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterCreationResultMessage(Reader *param1);
  CharacterCreationResultMessage();

  uint result;
};

#endif // CHARACTERCREATIONRESULTMESSAGE_H