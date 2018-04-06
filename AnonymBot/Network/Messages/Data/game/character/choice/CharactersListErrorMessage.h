#ifndef CHARACTERSLISTERRORMESSAGE_H
#define CHARACTERSLISTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharactersListErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharactersListErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharactersListErrorMessage(Reader *param1);
  CharactersListErrorMessage();
};

#endif // CHARACTERSLISTERRORMESSAGE_H