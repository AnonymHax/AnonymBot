#ifndef SEQUENCEENDMESSAGE_H
#define SEQUENCEENDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SequenceEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SequenceEndMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SequenceEndMessage(Reader *param1);
  SequenceEndMessage();

  uint actionId;
  double authorId;
  int sequenceType;
};

#endif // SEQUENCEENDMESSAGE_H