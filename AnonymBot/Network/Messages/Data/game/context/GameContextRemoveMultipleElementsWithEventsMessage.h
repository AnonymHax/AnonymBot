#ifndef GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H
#define GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/GameContextRemoveMultipleElementsMessage.h"

class GameContextRemoveMultipleElementsWithEventsMessage : public GameContextRemoveMultipleElementsMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Reader *param1);
  GameContextRemoveMultipleElementsWithEventsMessage();

  QList<uint> elementEventIds;
};

#endif // GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H