#ifndef SELLERBUYERDESCRIPTOR_H
#define SELLERBUYERDESCRIPTOR_H

#include "Network/Classes/AbstractClass.h"

class SellerBuyerDescriptor : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SellerBuyerDescriptor(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SellerBuyerDescriptor(Reader *param1);
  SellerBuyerDescriptor();
  bool operator==(const SellerBuyerDescriptor &compared);

  QList<uint> quantities;
  QList<uint> types;
  double taxPercentage;
  double taxModificationPercentage;
  uint maxItemLevel;
  uint maxItemPerAccount;
  int npcContextualId;
  uint unsoldDelay;
};

#endif // SELLERBUYERDESCRIPTOR_H