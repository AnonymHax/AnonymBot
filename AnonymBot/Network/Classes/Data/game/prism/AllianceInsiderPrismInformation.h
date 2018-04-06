#ifndef ALLIANCEINSIDERPRISMINFORMATION_H
#define ALLIANCEINSIDERPRISMINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class AllianceInsiderPrismInformation : public PrismInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInsiderPrismInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInsiderPrismInformation(Reader *param1);
  AllianceInsiderPrismInformation();
  bool operator==(const AllianceInsiderPrismInformation &compared);

  uint lastTimeSlotModificationDate;
  uint lastTimeSlotModificationAuthorGuildId;
  double lastTimeSlotModificationAuthorId;
  QString lastTimeSlotModificationAuthorName;
  QList<QSharedPointer<ObjectItem>> modulesObjects;
};

#endif // ALLIANCEINSIDERPRISMINFORMATION_H