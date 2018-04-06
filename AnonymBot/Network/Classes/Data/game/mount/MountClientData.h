#ifndef MOUNTCLIENTDATA_H
#define MOUNTCLIENTDATA_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectInteger.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectInteger.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class MountClientData : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountClientData(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountClientData(Reader *param1);
  MountClientData();
  bool operator==(const MountClientData &compared);

  double id;
  uint model;
  QList<uint> ancestor;
  QList<uint> behaviors;
  QString name;
  bool sex;
  uint ownerId;
  double experience;
  double experienceForLevel;
  double experienceForNextLevel;
  uint level;
  bool isRideable;
  uint maxPods;
  bool isWild;
  uint stamina;
  uint staminaMax;
  uint maturity;
  uint maturityForAdult;
  uint energy;
  uint energyMax;
  int serenity;
  int aggressivityMax;
  uint serenityMax;
  uint love;
  uint loveMax;
  int fecondationTime;
  bool isFecondationReady;
  uint boostLimiter;
  double boostMax;
  int reproductionCount;
  uint reproductionCountMax;
  uint harnessGID;
  bool useHarnessColors;
  QList<QSharedPointer<ObjectEffectInteger>> effectList;
};

#endif // MOUNTCLIENTDATA_H