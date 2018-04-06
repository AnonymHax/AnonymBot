#ifndef ABSTRACTCONTACTINFORMATIONS_H
#define ABSTRACTCONTACTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class AbstractContactInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractContactInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractContactInformations(Reader *param1);
  AbstractContactInformations();
  bool operator==(const AbstractContactInformations &compared);

  uint accountId;
  QString accountName;
};

#endif // ABSTRACTCONTACTINFORMATIONS_H