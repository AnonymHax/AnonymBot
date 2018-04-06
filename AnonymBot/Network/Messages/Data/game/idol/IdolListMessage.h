#ifndef IDOLLISTMESSAGE_H
#define IDOLLISTMESSAGE_H

#include "Network/Classes/Data/game/idol/PartyIdol.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/idol/PartyIdol.h"
#include "Network/Classes/ClassManager.h"

class IdolListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolListMessage(Reader *param1);
  IdolListMessage();

  QList<uint> chosenIdols;
  QList<uint> partyChosenIdols;
  QList<QSharedPointer<PartyIdol>> partyIdols;
};

#endif // IDOLLISTMESSAGE_H