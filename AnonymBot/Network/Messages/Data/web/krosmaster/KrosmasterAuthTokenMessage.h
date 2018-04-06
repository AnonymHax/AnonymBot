#ifndef KROSMASTERAUTHTOKENMESSAGE_H
#define KROSMASTERAUTHTOKENMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterAuthTokenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterAuthTokenMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterAuthTokenMessage(Reader *param1);
  KrosmasterAuthTokenMessage();

  QString token;
};

#endif // KROSMASTERAUTHTOKENMESSAGE_H