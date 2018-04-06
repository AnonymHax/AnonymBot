#ifndef FINISHMOVELISTMESSAGE_H
#define FINISHMOVELISTMESSAGE_H

#include "Network/Classes/Data/game/finishmoves/FinishMoveInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/finishmoves/FinishMoveInformations.h"

class FinishMoveListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FinishMoveListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FinishMoveListMessage(Reader *param1);
  FinishMoveListMessage();

  QList<FinishMoveInformations> finishMoves;
};

#endif // FINISHMOVELISTMESSAGE_H