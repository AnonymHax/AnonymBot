#ifndef JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H
#define JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Enum/Data/PlayableBreedEnum.h"
#include "Network/Classes/ClassManager.h"

class JobCrafterDirectoryEntryPlayerInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryEntryPlayerInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryEntryPlayerInfo(Reader *param1);
  JobCrafterDirectoryEntryPlayerInfo();
  bool operator==(const JobCrafterDirectoryEntryPlayerInfo &compared);

  double playerId;
  QString playerName;
  int alignmentSide;
  int breed;
  bool sex;
  bool isInWorkshop;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QSharedPointer<PlayerStatus> status;
};

#endif // JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H