#ifndef ORNAMENTSELECTERRORMESSAGE_H
#define ORNAMENTSELECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OrnamentSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OrnamentSelectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OrnamentSelectErrorMessage(Reader *param1);
  OrnamentSelectErrorMessage();

  uint reason;
};

#endif // ORNAMENTSELECTERRORMESSAGE_H