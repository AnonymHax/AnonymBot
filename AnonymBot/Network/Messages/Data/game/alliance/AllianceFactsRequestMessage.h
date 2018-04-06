#ifndef ALLIANCEFACTSREQUESTMESSAGE_H
#define ALLIANCEFACTSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceFactsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceFactsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceFactsRequestMessage(Reader *param1);
  AllianceFactsRequestMessage();

  uint allianceId;
};

#endif // ALLIANCEFACTSREQUESTMESSAGE_H