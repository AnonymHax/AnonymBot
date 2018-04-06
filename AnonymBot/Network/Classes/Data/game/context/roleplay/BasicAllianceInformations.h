#ifndef BASICALLIANCEINFORMATIONS_H
#define BASICALLIANCEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"

class BasicAllianceInformations : public AbstractSocialGroupInfos
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicAllianceInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicAllianceInformations(Reader *param1);
  BasicAllianceInformations();
  bool operator==(const BasicAllianceInformations &compared);

  uint allianceId;
  QString allianceTag;
};

#endif // BASICALLIANCEINFORMATIONS_H