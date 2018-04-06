#ifndef CHARACTERSELECTEDERRORMESSAGE_H
#define CHARACTERSELECTEDERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterSelectedErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectedErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectedErrorMessage(Reader *param1);
  CharacterSelectedErrorMessage();
};

#endif // CHARACTERSELECTEDERRORMESSAGE_H