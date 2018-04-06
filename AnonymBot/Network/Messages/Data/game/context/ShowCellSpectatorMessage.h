#ifndef SHOWCELLSPECTATORMESSAGE_H
#define SHOWCELLSPECTATORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/ShowCellMessage.h"

class ShowCellSpectatorMessage : public ShowCellMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShowCellSpectatorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShowCellSpectatorMessage(Reader *param1);
  ShowCellSpectatorMessage();

  QString playerName;
};

#endif // SHOWCELLSPECTATORMESSAGE_H