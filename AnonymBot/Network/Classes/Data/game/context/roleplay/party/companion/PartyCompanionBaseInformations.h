#ifndef PARTYCOMPANIONBASEINFORMATIONS_H
#define PARTYCOMPANIONBASEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class PartyCompanionBaseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCompanionBaseInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCompanionBaseInformations(Reader *param1);
  PartyCompanionBaseInformations();
  bool operator==(const PartyCompanionBaseInformations &compared);

  uint indexId;
  uint companionGenericId;
  QSharedPointer<EntityLook> entityLook;
};

#endif // PARTYCOMPANIONBASEINFORMATIONS_H