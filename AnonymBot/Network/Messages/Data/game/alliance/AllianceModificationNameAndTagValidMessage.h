#ifndef ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceModificationNameAndTagValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceModificationNameAndTagValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceModificationNameAndTagValidMessage(Reader *param1);
  AllianceModificationNameAndTagValidMessage();

  QString allianceName;
  QString allianceTag;
};

#endif // ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H