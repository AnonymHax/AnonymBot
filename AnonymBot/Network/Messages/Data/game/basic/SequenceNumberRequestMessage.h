#ifndef SEQUENCENUMBERREQUESTMESSAGE_H
#define SEQUENCENUMBERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SequenceNumberRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SequenceNumberRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SequenceNumberRequestMessage(Reader *param1);
  SequenceNumberRequestMessage();
};

#endif // SEQUENCENUMBERREQUESTMESSAGE_H