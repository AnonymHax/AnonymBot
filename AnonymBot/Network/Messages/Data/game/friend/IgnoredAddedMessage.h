#ifndef IGNOREDADDEDMESSAGE_H
#define IGNOREDADDEDMESSAGE_H

#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/ClassManager.h"

class IgnoredAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredAddedMessage(Reader *param1);
  IgnoredAddedMessage();

  QSharedPointer<IgnoredInformations> ignoreAdded;
  bool session;
};

#endif // IGNOREDADDEDMESSAGE_H