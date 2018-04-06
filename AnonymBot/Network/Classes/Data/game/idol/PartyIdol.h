#ifndef PARTYIDOL_H
#define PARTYIDOL_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/Data/game/idol/Idol.h"

class PartyIdol : public Idol
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyIdol(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyIdol(Reader *param1);
  PartyIdol();
  bool operator==(const PartyIdol &compared);

  QList<double> ownersIds;
};

#endif // PARTYIDOL_H