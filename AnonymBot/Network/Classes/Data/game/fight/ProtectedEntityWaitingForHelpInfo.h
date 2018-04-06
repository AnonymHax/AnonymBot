#ifndef PROTECTEDENTITYWAITINGFORHELPINFO_H
#define PROTECTEDENTITYWAITINGFORHELPINFO_H

#include "Network/Classes/AbstractClass.h"

class ProtectedEntityWaitingForHelpInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ProtectedEntityWaitingForHelpInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ProtectedEntityWaitingForHelpInfo(Reader *param1);
  ProtectedEntityWaitingForHelpInfo();
  bool operator==(const ProtectedEntityWaitingForHelpInfo &compared);

  int timeLeftBeforeFight;
  int waitTimeForPlacement;
  uint nbPositionForDefensors;
};

#endif // PROTECTEDENTITYWAITINGFORHELPINFO_H