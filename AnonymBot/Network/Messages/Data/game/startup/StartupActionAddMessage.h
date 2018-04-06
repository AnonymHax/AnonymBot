#ifndef STARTUPACTIONADDMESSAGE_H
#define STARTUPACTIONADDMESSAGE_H

#include "Network/Classes/Data/game/startup/StartupActionAddObject.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/startup/StartupActionAddObject.h"

class StartupActionAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionAddMessage(Reader *param1);
  StartupActionAddMessage();

  QSharedPointer<StartupActionAddObject> newAction;
};

#endif // STARTUPACTIONADDMESSAGE_H