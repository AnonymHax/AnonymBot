#ifndef KROSMASTERAUTHTOKENERRORMESSAGE_H
#define KROSMASTERAUTHTOKENERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterAuthTokenErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterAuthTokenErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterAuthTokenErrorMessage(Reader *param1);
  KrosmasterAuthTokenErrorMessage();

  uint reason;
};

#endif // KROSMASTERAUTHTOKENERRORMESSAGE_H