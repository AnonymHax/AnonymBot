#ifndef PRISMSETTINGSREQUESTMESSAGE_H
#define PRISMSETTINGSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismSettingsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismSettingsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismSettingsRequestMessage(Reader *param1);
  PrismSettingsRequestMessage();

  uint subAreaId;
  uint startDefenseTime;
};

#endif // PRISMSETTINGSREQUESTMESSAGE_H