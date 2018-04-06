#ifndef CHARACTERREPLAYREQUESTMESSAGE_H
#define CHARACTERREPLAYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterReplayRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterReplayRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterReplayRequestMessage(Reader *param1);
  CharacterReplayRequestMessage();

  double characterId;
};

#endif // CHARACTERREPLAYREQUESTMESSAGE_H