#ifndef SEQUENCENUMBERMESSAGE_H
#define SEQUENCENUMBERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SequenceNumberMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SequenceNumberMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SequenceNumberMessage(Reader *param1);
  SequenceNumberMessage();

  uint number;
};

#endif // SEQUENCENUMBERMESSAGE_H