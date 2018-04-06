#ifndef ACCOUNTCAPABILITIESMESSAGE_H
#define ACCOUNTCAPABILITIESMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class AccountCapabilitiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccountCapabilitiesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccountCapabilitiesMessage(Reader *param1);
  AccountCapabilitiesMessage();

  uint accountId;
  bool tutorialAvailable;
  uint breedsVisible;
  uint breedsAvailable;
  int status;
  bool canCreateNewCharacter;
};

#endif // ACCOUNTCAPABILITIESMESSAGE_H