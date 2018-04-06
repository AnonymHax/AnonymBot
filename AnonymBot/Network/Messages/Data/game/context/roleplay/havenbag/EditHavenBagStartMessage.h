#ifndef EDITHAVENBAGSTARTMESSAGE_H
#define EDITHAVENBAGSTARTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EditHavenBagStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EditHavenBagStartMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EditHavenBagStartMessage(Reader *param1);
  EditHavenBagStartMessage();
};

#endif // EDITHAVENBAGSTARTMESSAGE_H