#ifndef CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H
#define CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H

#include "Network/Classes/Data/game/character/choice/RemodelingInformation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/replay/CharacterReplayRequestMessage.h"
#include "Network/Classes/Data/game/character/choice/RemodelingInformation.h"

class CharacterReplayWithRemodelRequestMessage : public CharacterReplayRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterReplayWithRemodelRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterReplayWithRemodelRequestMessage(Reader *param1);
  CharacterReplayWithRemodelRequestMessage();

  RemodelingInformation remodel;
};

#endif // CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H