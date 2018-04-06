#ifndef TAXCOLLECTORSTATICINFORMATIONS_H
#define TAXCOLLECTORSTATICINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class TaxCollectorStaticInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorStaticInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorStaticInformations(Reader *param1);
  TaxCollectorStaticInformations();
  bool operator==(const TaxCollectorStaticInformations &compared);

  uint firstNameId;
  uint lastNameId;
  QSharedPointer<GuildInformations> guildIdentity;
};

#endif // TAXCOLLECTORSTATICINFORMATIONS_H