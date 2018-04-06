#ifndef GAMECONTEXTREMOVEELEMENTMESSAGE_H
#define GAMECONTEXTREMOVEELEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextRemoveElementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextRemoveElementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextRemoveElementMessage(Reader *param1);
  GameContextRemoveElementMessage();

  double id;
};

#endif // GAMECONTEXTREMOVEELEMENTMESSAGE_H