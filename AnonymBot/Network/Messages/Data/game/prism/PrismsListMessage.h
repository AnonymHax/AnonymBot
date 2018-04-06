#ifndef PRISMSLISTMESSAGE_H
#define PRISMSLISTMESSAGE_H

#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/ClassManager.h"

class PrismsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismsListMessage(Reader *param1);
  PrismsListMessage();

  QList<QSharedPointer<PrismSubareaEmptyInfo>> prisms;
};

#endif // PRISMSLISTMESSAGE_H