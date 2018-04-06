#ifndef ABSTRACTSOCIALGROUPINFOS_H
#define ABSTRACTSOCIALGROUPINFOS_H

#include "Network/Classes/AbstractClass.h"

class AbstractSocialGroupInfos : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractSocialGroupInfos(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractSocialGroupInfos(Reader *param1);
  AbstractSocialGroupInfos();
  bool operator==(const AbstractSocialGroupInfos &compared);
};

#endif // ABSTRACTSOCIALGROUPINFOS_H