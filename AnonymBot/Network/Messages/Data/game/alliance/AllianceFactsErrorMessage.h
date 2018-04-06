#ifndef ALLIANCEFACTSERRORMESSAGE_H
#define ALLIANCEFACTSERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceFactsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceFactsErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceFactsErrorMessage(Reader *param1);
  AllianceFactsErrorMessage();

  uint allianceId;
};

#endif // ALLIANCEFACTSERRORMESSAGE_H