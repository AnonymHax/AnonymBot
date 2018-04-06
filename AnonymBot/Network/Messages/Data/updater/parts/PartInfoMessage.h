#ifndef PARTINFOMESSAGE_H
#define PARTINFOMESSAGE_H

#include "Network/Classes/Data/updater/ContentPart.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/updater/ContentPart.h"

class PartInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartInfoMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartInfoMessage(Reader *param1);
  PartInfoMessage();

  ContentPart part;
  double installationPercent;
};

#endif // PARTINFOMESSAGE_H