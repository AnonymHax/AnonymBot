#ifndef ERRORMAPNOTFOUNDMESSAGE_H
#define ERRORMAPNOTFOUNDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ErrorMapNotFoundMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ErrorMapNotFoundMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ErrorMapNotFoundMessage(Reader *param1);
  ErrorMapNotFoundMessage();

  uint mapId;
};

#endif // ERRORMAPNOTFOUNDMESSAGE_H