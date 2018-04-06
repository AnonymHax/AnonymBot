#ifndef CHARACTERSELECTIONMESSAGE_H
#define CHARACTERSELECTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterSelectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectionMessage(Reader *param1);
  CharacterSelectionMessage();

  double id;
};

#endif // CHARACTERSELECTIONMESSAGE_H