#ifndef PADDOCKCONTENTINFORMATIONS_H
#define PADDOCKCONTENTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/paddock/MountInformationsForPaddock.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"
#include "Network/Classes/Data/game/paddock/MountInformationsForPaddock.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"

class PaddockContentInformations : public PaddockInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockContentInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockContentInformations(Reader *param1);
  PaddockContentInformations();
  bool operator==(const PaddockContentInformations &compared);

  int paddockId;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  bool abandonned;
  QList<MountInformationsForPaddock> mountsInformations;
};

#endif // PADDOCKCONTENTINFORMATIONS_H