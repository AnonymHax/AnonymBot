#ifndef MOUNTINFORMATIONSFORPADDOCK_H
#define MOUNTINFORMATIONSFORPADDOCK_H

#include "Network/Classes/AbstractClass.h"

class MountInformationsForPaddock : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountInformationsForPaddock(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountInformationsForPaddock(Reader *param1);
  MountInformationsForPaddock();
  bool operator==(const MountInformationsForPaddock &compared);

  uint modelId;
  QString name;
  QString ownerName;
};

#endif // MOUNTINFORMATIONSFORPADDOCK_H