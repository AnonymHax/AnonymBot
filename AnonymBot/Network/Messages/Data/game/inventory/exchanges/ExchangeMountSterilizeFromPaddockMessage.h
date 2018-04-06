#ifndef EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountSterilizeFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountSterilizeFromPaddockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountSterilizeFromPaddockMessage(Reader *param1);
  ExchangeMountSterilizeFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString sterilizator;
};

#endif // EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H