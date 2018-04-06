#ifndef SERVERSETTINGSMESSAGE_H
#define SERVERSETTINGSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ServerSettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSettingsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSettingsMessage(Reader *param1);
  ServerSettingsMessage();

  QString lang;
  uint community;
  int gameType;
  uint arenaLeaveBanTime;
};

#endif // SERVERSETTINGSMESSAGE_H