#ifndef INTERACTIVEMAPUPDATEMESSAGE_H
#define INTERACTIVEMAPUPDATEMESSAGE_H

#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/ClassManager.h"

class InteractiveMapUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveMapUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveMapUpdateMessage(Reader *param1);
  InteractiveMapUpdateMessage();

  QList<QSharedPointer<InteractiveElement>> interactiveElements;
};

#endif // INTERACTIVEMAPUPDATEMESSAGE_H