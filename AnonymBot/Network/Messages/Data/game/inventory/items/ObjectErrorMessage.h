#ifndef OBJECTERRORMESSAGE_H
#define OBJECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectErrorMessage(Reader *param1);
  ObjectErrorMessage();

  int reason;
};

#endif // OBJECTERRORMESSAGE_H