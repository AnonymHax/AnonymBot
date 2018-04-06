#ifndef INTERACTIVEELEMENTUPDATEDMESSAGE_H
#define INTERACTIVEELEMENTUPDATEDMESSAGE_H

#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"

class InteractiveElementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveElementUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveElementUpdatedMessage(Reader *param1);
  InteractiveElementUpdatedMessage();

  QSharedPointer<InteractiveElement> interactiveElement;
};

#endif // INTERACTIVEELEMENTUPDATEDMESSAGE_H