#ifndef OBJECTGROUNDLISTADDEDMESSAGE_H
#define OBJECTGROUNDLISTADDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectGroundListAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectGroundListAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectGroundListAddedMessage(Reader *param1);
  ObjectGroundListAddedMessage();

  QList<uint> cells;
  QList<uint> referenceIds;
};

#endif // OBJECTGROUNDLISTADDEDMESSAGE_H