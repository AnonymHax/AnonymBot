#ifndef EDITHAVENBAGFINISHEDMESSAGE_H
#define EDITHAVENBAGFINISHEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EditHavenBagFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EditHavenBagFinishedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EditHavenBagFinishedMessage(Reader *param1);
  EditHavenBagFinishedMessage();
};

#endif // EDITHAVENBAGFINISHEDMESSAGE_H