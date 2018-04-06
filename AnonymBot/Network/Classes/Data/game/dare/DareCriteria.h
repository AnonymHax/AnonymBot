#ifndef DARECRITERIA_H
#define DARECRITERIA_H

#include "Network/Classes/AbstractClass.h"

class DareCriteria : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCriteria(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCriteria(Reader *param1);
  DareCriteria();
  bool operator==(const DareCriteria &compared);

  uint type;
  QList<int> params;
};

#endif // DARECRITERIA_H