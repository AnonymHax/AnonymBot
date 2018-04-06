#ifndef CHARACTERDELETIONERRORMESSAGE_H
#define CHARACTERDELETIONERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterDeletionErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterDeletionErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterDeletionErrorMessage(Reader *param1);
  CharacterDeletionErrorMessage();

  uint reason;
};

#endif // CHARACTERDELETIONERRORMESSAGE_H