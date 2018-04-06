#ifndef ALLIANCECREATIONRESULTMESSAGE_H
#define ALLIANCECREATIONRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceCreationResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceCreationResultMessage(Reader *param1);
  AllianceCreationResultMessage();

  uint result;
};

#endif // ALLIANCECREATIONRESULTMESSAGE_H