#ifndef IDOLPARTYREFRESHMESSAGE_H
#define IDOLPARTYREFRESHMESSAGE_H

#include "Network/Classes/Data/game/idol/PartyIdol.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/idol/PartyIdol.h"

class IdolPartyRefreshMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolPartyRefreshMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolPartyRefreshMessage(Reader *param1);
  IdolPartyRefreshMessage();

  QSharedPointer<PartyIdol> partyIdol;
};

#endif // IDOLPARTYREFRESHMESSAGE_H