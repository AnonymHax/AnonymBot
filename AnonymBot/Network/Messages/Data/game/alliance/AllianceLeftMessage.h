#ifndef ALLIANCELEFTMESSAGE_H
#define ALLIANCELEFTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceLeftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceLeftMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceLeftMessage(Reader *param1);
  AllianceLeftMessage();
};

#endif // ALLIANCELEFTMESSAGE_H