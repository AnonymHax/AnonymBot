#ifndef CHARACTERSELECTEDFORCEREADYMESSAGE_H
#define CHARACTERSELECTEDFORCEREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterSelectedForceReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectedForceReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectedForceReadyMessage(Reader *param1);
  CharacterSelectedForceReadyMessage();
};

#endif // CHARACTERSELECTEDFORCEREADYMESSAGE_H