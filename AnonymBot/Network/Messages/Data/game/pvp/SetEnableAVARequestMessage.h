#ifndef SETENABLEAVAREQUESTMESSAGE_H
#define SETENABLEAVAREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SetEnableAVARequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SetEnableAVARequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SetEnableAVARequestMessage(Reader *param1);
  SetEnableAVARequestMessage();

  bool enable;
};

#endif // SETENABLEAVAREQUESTMESSAGE_H