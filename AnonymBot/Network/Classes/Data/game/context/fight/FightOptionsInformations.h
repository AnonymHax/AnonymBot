#ifndef FIGHTOPTIONSINFORMATIONS_H
#define FIGHTOPTIONSINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class FightOptionsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightOptionsInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightOptionsInformations(Reader *param1);
  FightOptionsInformations();
  bool operator==(const FightOptionsInformations &compared);

  bool isSecret;
  bool isRestrictedToPartyOnly;
  bool isClosed;
  bool isAskingForHelp;
};

#endif // FIGHTOPTIONSINFORMATIONS_H