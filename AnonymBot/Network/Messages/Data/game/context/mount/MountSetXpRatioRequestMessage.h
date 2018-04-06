#ifndef MOUNTSETXPRATIOREQUESTMESSAGE_H
#define MOUNTSETXPRATIOREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountSetXpRatioRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountSetXpRatioRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountSetXpRatioRequestMessage(Reader *param1);
  MountSetXpRatioRequestMessage();

  uint xpRatio;
};

#endif // MOUNTSETXPRATIOREQUESTMESSAGE_H