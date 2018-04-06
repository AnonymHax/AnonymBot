#ifndef BASICNAMEDALLIANCEINFORMATIONS_H
#define BASICNAMEDALLIANCEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"

class BasicNamedAllianceInformations : public BasicAllianceInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicNamedAllianceInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicNamedAllianceInformations(Reader *param1);
  BasicNamedAllianceInformations();
  bool operator==(const BasicNamedAllianceInformations &compared);

  QString allianceName;
};

#endif // BASICNAMEDALLIANCEINFORMATIONS_H