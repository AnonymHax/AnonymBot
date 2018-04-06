#ifndef SOCIALNOTICEMESSAGE_H
#define SOCIALNOTICEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SocialNoticeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SocialNoticeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SocialNoticeMessage(Reader *param1);
  SocialNoticeMessage();

  QString content;
  uint timestamp;
  double memberId;
  QString memberName;
};

#endif // SOCIALNOTICEMESSAGE_H