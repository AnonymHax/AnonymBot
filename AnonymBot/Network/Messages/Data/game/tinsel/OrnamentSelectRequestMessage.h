#ifndef ORNAMENTSELECTREQUESTMESSAGE_H
#define ORNAMENTSELECTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OrnamentSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OrnamentSelectRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OrnamentSelectRequestMessage(Reader *param1);
  OrnamentSelectRequestMessage();

  uint ornamentId;
};

#endif // ORNAMENTSELECTREQUESTMESSAGE_H