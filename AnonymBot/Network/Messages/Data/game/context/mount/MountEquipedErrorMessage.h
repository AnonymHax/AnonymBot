#ifndef MOUNTEQUIPEDERRORMESSAGE_H
#define MOUNTEQUIPEDERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountEquipedErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountEquipedErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountEquipedErrorMessage(Reader *param1);
  MountEquipedErrorMessage();

  uint errorType;
};

#endif // MOUNTEQUIPEDERRORMESSAGE_H