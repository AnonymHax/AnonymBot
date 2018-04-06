#ifndef TAXCOLLECTORERRORMESSAGE_H
#define TAXCOLLECTORERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TaxCollectorErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorErrorMessage(Reader *param1);
  TaxCollectorErrorMessage();

  int reason;
};

#endif // TAXCOLLECTORERRORMESSAGE_H