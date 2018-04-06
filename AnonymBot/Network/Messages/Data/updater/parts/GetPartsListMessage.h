#ifndef GETPARTSLISTMESSAGE_H
#define GETPARTSLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GetPartsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GetPartsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GetPartsListMessage(Reader *param1);
  GetPartsListMessage();
};

#endif // GETPARTSLISTMESSAGE_H