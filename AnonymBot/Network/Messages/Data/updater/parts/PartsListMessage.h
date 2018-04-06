#ifndef PARTSLISTMESSAGE_H
#define PARTSLISTMESSAGE_H

#include "Network/Classes/Data/updater/ContentPart.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/updater/ContentPart.h"

class PartsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartsListMessage(Reader *param1);
  PartsListMessage();

  QList<ContentPart> parts;
};

#endif // PARTSLISTMESSAGE_H