#ifndef ALLIANCEVERSATILEINFORMATIONS_H
#define ALLIANCEVERSATILEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class AllianceVersatileInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceVersatileInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceVersatileInformations(Reader *param1);
  AllianceVersatileInformations();
  bool operator==(const AllianceVersatileInformations &compared);

  uint allianceId;
  uint nbGuilds;
  uint nbMembers;
  uint nbSubarea;
};

#endif // ALLIANCEVERSATILEINFORMATIONS_H