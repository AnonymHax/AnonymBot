#ifndef GAMEFIGHTTURNLISTMESSAGE_H
#define GAMEFIGHTTURNLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnListMessage(Reader *param1);
  GameFightTurnListMessage();

  QList<double> ids;
  QList<double> deadsIds;
};

#endif // GAMEFIGHTTURNLISTMESSAGE_H