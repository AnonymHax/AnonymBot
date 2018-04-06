#ifndef PADDOCKPROPERTIESMESSAGE_H
#define PADDOCKPROPERTIESMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"
#include "Network/Classes/ClassManager.h"

class PaddockPropertiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockPropertiesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockPropertiesMessage(Reader *param1);
  PaddockPropertiesMessage();

  QSharedPointer<PaddockInformations> properties;
};

#endif // PADDOCKPROPERTIESMESSAGE_H