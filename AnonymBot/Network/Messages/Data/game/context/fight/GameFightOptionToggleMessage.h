#ifndef GAMEFIGHTOPTIONTOGGLEMESSAGE_H
#define GAMEFIGHTOPTIONTOGGLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightOptionToggleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightOptionToggleMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightOptionToggleMessage(Reader *param1);
  GameFightOptionToggleMessage();

  uint option;
};

#endif // GAMEFIGHTOPTIONTOGGLEMESSAGE_H