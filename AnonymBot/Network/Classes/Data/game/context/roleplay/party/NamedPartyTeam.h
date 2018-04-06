#ifndef NAMEDPARTYTEAM_H
#define NAMEDPARTYTEAM_H

#include "Network/Classes/AbstractClass.h"

class NamedPartyTeam : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NamedPartyTeam(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NamedPartyTeam(Reader *param1);
  NamedPartyTeam();
  bool operator==(const NamedPartyTeam &compared);

  uint teamId;
  QString partyName;
};

#endif // NAMEDPARTYTEAM_H