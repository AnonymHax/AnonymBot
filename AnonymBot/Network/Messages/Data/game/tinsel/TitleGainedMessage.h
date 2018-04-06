#ifndef TITLEGAINEDMESSAGE_H
#define TITLEGAINEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitleGainedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitleGainedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitleGainedMessage(Reader *param1);
  TitleGainedMessage();

  uint titleId;
};

#endif // TITLEGAINEDMESSAGE_H