#ifndef WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H
#define WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class WrapperObjectDissociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_WrapperObjectDissociateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_WrapperObjectDissociateRequestMessage(Reader *param1);
  WrapperObjectDissociateRequestMessage();

  uint hostUID;
  uint hostPos;
};

#endif // WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H