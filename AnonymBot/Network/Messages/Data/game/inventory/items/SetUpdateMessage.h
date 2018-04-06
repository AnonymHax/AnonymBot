#ifndef SETUPDATEMESSAGE_H
#define SETUPDATEMESSAGE_H

#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class SetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SetUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SetUpdateMessage(Reader *param1);
  SetUpdateMessage();

  uint setId;
  QList<uint> setObjects;
  QList<QSharedPointer<ObjectEffect>> setEffects;
};

#endif // SETUPDATEMESSAGE_H