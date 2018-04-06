#ifndef ALLIANCEINSIDERINFOREQUESTMESSAGE_H
#define ALLIANCEINSIDERINFOREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceInsiderInfoRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInsiderInfoRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInsiderInfoRequestMessage(Reader *param1);
  AllianceInsiderInfoRequestMessage();
};

#endif // ALLIANCEINSIDERINFOREQUESTMESSAGE_H