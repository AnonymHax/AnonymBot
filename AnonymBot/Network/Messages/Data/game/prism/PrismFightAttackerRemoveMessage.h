#ifndef PRISMFIGHTATTACKERREMOVEMESSAGE_H
#define PRISMFIGHTATTACKERREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightAttackerRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightAttackerRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightAttackerRemoveMessage(Reader *param1);
  PrismFightAttackerRemoveMessage();

  uint subAreaId;
  uint fightId;
  double fighterToRemoveId;
};

#endif // PRISMFIGHTATTACKERREMOVEMESSAGE_H