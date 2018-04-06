#ifndef EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountsTakenFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsTakenFromPaddockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsTakenFromPaddockMessage(Reader *param1);
  ExchangeMountsTakenFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString ownername;
};

#endif // EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H