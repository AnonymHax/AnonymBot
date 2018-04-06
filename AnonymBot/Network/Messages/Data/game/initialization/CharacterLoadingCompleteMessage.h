#ifndef CHARACTERLOADINGCOMPLETEMESSAGE_H
#define CHARACTERLOADINGCOMPLETEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterLoadingCompleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterLoadingCompleteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterLoadingCompleteMessage(Reader *param1);
  CharacterLoadingCompleteMessage();
};

#endif // CHARACTERLOADINGCOMPLETEMESSAGE_H