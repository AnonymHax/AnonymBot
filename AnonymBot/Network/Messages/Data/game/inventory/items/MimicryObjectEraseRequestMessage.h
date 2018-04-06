#ifndef MIMICRYOBJECTERASEREQUESTMESSAGE_H
#define MIMICRYOBJECTERASEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MimicryObjectEraseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MimicryObjectEraseRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MimicryObjectEraseRequestMessage(Reader *param1);
  MimicryObjectEraseRequestMessage();

  uint hostUID;
  uint hostPos;
};

#endif // MIMICRYOBJECTERASEREQUESTMESSAGE_H