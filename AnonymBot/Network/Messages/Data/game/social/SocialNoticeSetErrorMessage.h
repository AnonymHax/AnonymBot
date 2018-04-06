#ifndef SOCIALNOTICESETERRORMESSAGE_H
#define SOCIALNOTICESETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SocialNoticeSetErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SocialNoticeSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SocialNoticeSetErrorMessage(Reader *param1);
  SocialNoticeSetErrorMessage();

  uint reason;
};

#endif // SOCIALNOTICESETERRORMESSAGE_H