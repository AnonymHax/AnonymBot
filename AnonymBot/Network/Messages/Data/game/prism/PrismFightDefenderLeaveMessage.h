#ifndef PRISMFIGHTDEFENDERLEAVEMESSAGE_H
#define PRISMFIGHTDEFENDERLEAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightDefenderLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightDefenderLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightDefenderLeaveMessage(Reader *param1);
  PrismFightDefenderLeaveMessage();

  uint subAreaId;
  uint fightId;
  double fighterToRemoveId;
};

#endif // PRISMFIGHTDEFENDERLEAVEMESSAGE_H