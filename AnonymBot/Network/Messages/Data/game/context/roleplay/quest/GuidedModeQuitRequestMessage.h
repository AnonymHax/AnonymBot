#ifndef GUIDEDMODEQUITREQUESTMESSAGE_H
#define GUIDEDMODEQUITREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuidedModeQuitRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuidedModeQuitRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuidedModeQuitRequestMessage(Reader *param1);
  GuidedModeQuitRequestMessage();
};

#endif // GUIDEDMODEQUITREQUESTMESSAGE_H