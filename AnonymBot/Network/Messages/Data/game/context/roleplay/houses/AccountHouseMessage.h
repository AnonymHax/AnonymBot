#ifndef ACCOUNTHOUSEMESSAGE_H
#define ACCOUNTHOUSEMESSAGE_H

#include "Network/Classes/Data/game/house/AccountHouseInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/AccountHouseInformations.h"

class AccountHouseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccountHouseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccountHouseMessage(Reader *param1);
  AccountHouseMessage();

  QList<AccountHouseInformations> houses;
};

#endif // ACCOUNTHOUSEMESSAGE_H