#ifndef SPOUSEGETINFORMATIONSMESSAGE_H
#define SPOUSEGETINFORMATIONSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpouseGetInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpouseGetInformationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpouseGetInformationsMessage(Reader *param1);
  SpouseGetInformationsMessage();
};

#endif // SPOUSEGETINFORMATIONSMESSAGE_H