#ifndef SYSTEMMESSAGEDISPLAYMESSAGE_H
#define SYSTEMMESSAGEDISPLAYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SystemMessageDisplayMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SystemMessageDisplayMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SystemMessageDisplayMessage(Reader *param1);
  SystemMessageDisplayMessage();

  bool hangUp;
  uint msgId;
  QList<QString> parameters;
};

#endif // SYSTEMMESSAGEDISPLAYMESSAGE_H