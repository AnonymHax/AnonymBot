#ifndef REMODELINGINFORMATION_H
#define REMODELINGINFORMATION_H

#include "Network/Classes/AbstractClass.h"

class RemodelingInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_RemodelingInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_RemodelingInformation(Reader *param1);
  RemodelingInformation();
  bool operator==(const RemodelingInformation &compared);

  QString name;
  int breed;
  bool sex;
  uint cosmeticId;
  QList<int> colors;
};

#endif // REMODELINGINFORMATION_H