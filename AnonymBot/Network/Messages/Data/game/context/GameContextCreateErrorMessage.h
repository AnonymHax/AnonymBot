#ifndef GAMECONTEXTCREATEERRORMESSAGE_H
#define GAMECONTEXTCREATEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextCreateErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextCreateErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextCreateErrorMessage(Reader *param1);
  GameContextCreateErrorMessage();
};

#endif // GAMECONTEXTCREATEERRORMESSAGE_H