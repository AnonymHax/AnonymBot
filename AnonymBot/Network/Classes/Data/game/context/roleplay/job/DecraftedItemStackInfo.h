#ifndef DECRAFTEDITEMSTACKINFO_H
#define DECRAFTEDITEMSTACKINFO_H

#include "Network/Classes/AbstractClass.h"

class DecraftedItemStackInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DecraftedItemStackInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DecraftedItemStackInfo(Reader *param1);
  DecraftedItemStackInfo();
  bool operator==(const DecraftedItemStackInfo &compared);

  uint objectUID;
  double bonusMin;
  double bonusMax;
  QList<uint> runesId;
  QList<uint> runesQty;
};

#endif // DECRAFTEDITEMSTACKINFO_H