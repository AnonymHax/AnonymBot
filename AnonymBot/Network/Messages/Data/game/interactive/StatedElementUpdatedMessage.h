#ifndef STATEDELEMENTUPDATEDMESSAGE_H
#define STATEDELEMENTUPDATEDMESSAGE_H

#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"

class StatedElementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatedElementUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatedElementUpdatedMessage(Reader *param1);
  StatedElementUpdatedMessage();

  StatedElement statedElement;
};

#endif // STATEDELEMENTUPDATEDMESSAGE_H