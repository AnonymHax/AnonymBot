#ifndef SEQUENCESTARTMESSAGE_H
#define SEQUENCESTARTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SequenceStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SequenceStartMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SequenceStartMessage(Reader *param1);
  SequenceStartMessage();

  int sequenceType;
  double authorId;
};

#endif // SEQUENCESTARTMESSAGE_H