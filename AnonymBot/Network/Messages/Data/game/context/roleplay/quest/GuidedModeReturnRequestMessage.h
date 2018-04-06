#ifndef GUIDEDMODERETURNREQUESTMESSAGE_H
#define GUIDEDMODERETURNREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuidedModeReturnRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuidedModeReturnRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuidedModeReturnRequestMessage(Reader *param1);
  GuidedModeReturnRequestMessage();
};

#endif // GUIDEDMODERETURNREQUESTMESSAGE_H