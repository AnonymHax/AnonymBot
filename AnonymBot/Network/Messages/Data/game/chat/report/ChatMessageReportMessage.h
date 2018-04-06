#ifndef CHATMESSAGEREPORTMESSAGE_H
#define CHATMESSAGEREPORTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatMessageReportMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatMessageReportMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatMessageReportMessage(Reader *param1);
  ChatMessageReportMessage();

  QString senderName;
  QString content;
  uint timestamp;
  uint channel;
  QString fingerprint;
  uint reason;
};

#endif // CHATMESSAGEREPORTMESSAGE_H