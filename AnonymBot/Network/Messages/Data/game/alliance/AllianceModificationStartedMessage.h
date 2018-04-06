#ifndef ALLIANCEMODIFICATIONSTARTEDMESSAGE_H
#define ALLIANCEMODIFICATIONSTARTEDMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class AllianceModificationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceModificationStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceModificationStartedMessage(Reader *param1);
  AllianceModificationStartedMessage();

  bool canChangeName;
  bool canChangeTag;
  bool canChangeEmblem;
};

#endif // ALLIANCEMODIFICATIONSTARTEDMESSAGE_H