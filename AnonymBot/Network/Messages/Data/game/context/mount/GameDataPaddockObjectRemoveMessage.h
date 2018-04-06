#ifndef GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H
#define GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameDataPaddockObjectRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameDataPaddockObjectRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameDataPaddockObjectRemoveMessage(Reader *param1);
  GameDataPaddockObjectRemoveMessage();

  uint cellId;
};

#endif // GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H