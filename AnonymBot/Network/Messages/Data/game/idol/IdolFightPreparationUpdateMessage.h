#ifndef IDOLFIGHTPREPARATIONUPDATEMESSAGE_H
#define IDOLFIGHTPREPARATIONUPDATEMESSAGE_H

#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/ClassManager.h"

class IdolFightPreparationUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolFightPreparationUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolFightPreparationUpdateMessage(Reader *param1);
  IdolFightPreparationUpdateMessage();

  uint idolSource;
  QList<QSharedPointer<Idol>> idols;
};

#endif // IDOLFIGHTPREPARATIONUPDATEMESSAGE_H