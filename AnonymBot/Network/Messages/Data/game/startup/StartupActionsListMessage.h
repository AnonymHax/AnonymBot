#ifndef STARTUPACTIONSLISTMESSAGE_H
#define STARTUPACTIONSLISTMESSAGE_H

#include "Network/Classes/Data/game/startup/StartupActionAddObject.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/startup/StartupActionAddObject.h"

class StartupActionsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionsListMessage(Reader *param1);
  StartupActionsListMessage();

  QList<QSharedPointer<StartupActionAddObject>> actions;
};

#endif // STARTUPACTIONSLISTMESSAGE_H