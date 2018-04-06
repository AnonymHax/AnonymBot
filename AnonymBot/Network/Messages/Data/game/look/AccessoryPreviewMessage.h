#ifndef ACCESSORYPREVIEWMESSAGE_H
#define ACCESSORYPREVIEWMESSAGE_H

#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class AccessoryPreviewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccessoryPreviewMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccessoryPreviewMessage(Reader *param1);
  AccessoryPreviewMessage();

  QSharedPointer<EntityLook> look;
};

#endif // ACCESSORYPREVIEWMESSAGE_H