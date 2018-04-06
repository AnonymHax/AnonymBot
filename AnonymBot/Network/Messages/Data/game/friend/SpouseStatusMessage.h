#ifndef SPOUSESTATUSMESSAGE_H
#define SPOUSESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpouseStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpouseStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpouseStatusMessage(Reader *param1);
  SpouseStatusMessage();

  bool hasSpouse;
};

#endif // SPOUSESTATUSMESSAGE_H