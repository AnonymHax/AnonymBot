#ifndef PORTALINFORMATION_H
#define PORTALINFORMATION_H

#include "Network/Classes/AbstractClass.h"

class PortalInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PortalInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PortalInformation(Reader *param1);
  PortalInformation();
  bool operator==(const PortalInformation &compared);

  int portalId;
  int areaId;
};

#endif // PORTALINFORMATION_H