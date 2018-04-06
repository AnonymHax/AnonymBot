#ifndef EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountFreeFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountFreeFromPaddockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountFreeFromPaddockMessage(Reader *param1);
  ExchangeMountFreeFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString liberator;
};

#endif // EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H