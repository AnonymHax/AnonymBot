#ifndef OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H
#define OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectGroundRemovedMultipleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectGroundRemovedMultipleMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectGroundRemovedMultipleMessage(Reader *param1);
  ObjectGroundRemovedMultipleMessage();

  QList<uint> cells;
};

#endif // OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H