#ifndef MIMICRYOBJECTPREVIEWMESSAGE_H
#define MIMICRYOBJECTPREVIEWMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class MimicryObjectPreviewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MimicryObjectPreviewMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MimicryObjectPreviewMessage(Reader *param1);
  MimicryObjectPreviewMessage();

  QSharedPointer<ObjectItem> result;
};

#endif // MIMICRYOBJECTPREVIEWMESSAGE_H