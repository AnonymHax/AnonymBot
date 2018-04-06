#ifndef IGNOREDLISTMESSAGE_H
#define IGNOREDLISTMESSAGE_H

#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/ClassManager.h"

class IgnoredListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredListMessage(Reader *param1);
  IgnoredListMessage();

  QList<QSharedPointer<IgnoredInformations>> ignoredList;
};

#endif // IGNOREDLISTMESSAGE_H