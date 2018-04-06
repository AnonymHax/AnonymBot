#ifndef MOUNTXPRATIOMESSAGE_H
#define MOUNTXPRATIOMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountXpRatioMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountXpRatioMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountXpRatioMessage(Reader *param1);
  MountXpRatioMessage();

  uint ratio;
};

#endif // MOUNTXPRATIOMESSAGE_H