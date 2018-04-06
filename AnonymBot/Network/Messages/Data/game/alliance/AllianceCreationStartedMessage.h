#ifndef ALLIANCECREATIONSTARTEDMESSAGE_H
#define ALLIANCECREATIONSTARTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceCreationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceCreationStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceCreationStartedMessage(Reader *param1);
  AllianceCreationStartedMessage();
};

#endif // ALLIANCECREATIONSTARTEDMESSAGE_H