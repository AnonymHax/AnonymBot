#ifndef ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H
#define ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class AbstractGameActionFightTargetedAbilityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractGameActionFightTargetedAbilityMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractGameActionFightTargetedAbilityMessage(Reader *param1);
  AbstractGameActionFightTargetedAbilityMessage();

  double targetId;
  int destinationCellId;
  uint critical;
  bool silentCast;
  bool verboseCast;
};

#endif // ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H