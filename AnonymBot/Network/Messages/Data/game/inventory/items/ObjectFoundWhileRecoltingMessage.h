#ifndef OBJECTFOUNDWHILERECOLTINGMESSAGE_H
#define OBJECTFOUNDWHILERECOLTINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectFoundWhileRecoltingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectFoundWhileRecoltingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectFoundWhileRecoltingMessage(Reader *param1);
  ObjectFoundWhileRecoltingMessage();

  uint genericId;
  uint quantity;
  uint resourceGenericId;
};

#endif // OBJECTFOUNDWHILERECOLTINGMESSAGE_H