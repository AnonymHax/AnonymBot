#ifndef URLOPENMESSAGE_H
#define URLOPENMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class URLOpenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_URLOpenMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_URLOpenMessage(Reader *param1);
  URLOpenMessage();

  uint urlId;
};

#endif // URLOPENMESSAGE_H