#ifndef SOCIALNOTICESETREQUESTMESSAGE_H
#define SOCIALNOTICESETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SocialNoticeSetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SocialNoticeSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SocialNoticeSetRequestMessage(Reader *param1);
  SocialNoticeSetRequestMessage();
};

#endif // SOCIALNOTICESETREQUESTMESSAGE_H