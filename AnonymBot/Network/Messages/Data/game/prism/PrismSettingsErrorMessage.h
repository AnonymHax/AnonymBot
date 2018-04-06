#ifndef PRISMSETTINGSERRORMESSAGE_H
#define PRISMSETTINGSERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismSettingsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismSettingsErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismSettingsErrorMessage(Reader *param1);
  PrismSettingsErrorMessage();
};

#endif // PRISMSETTINGSERRORMESSAGE_H