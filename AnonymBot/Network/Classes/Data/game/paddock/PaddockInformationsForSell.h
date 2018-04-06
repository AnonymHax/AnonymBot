#ifndef PADDOCKINFORMATIONSFORSELL_H
#define PADDOCKINFORMATIONSFORSELL_H

#include "Network/Classes/AbstractClass.h"

class PaddockInformationsForSell : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockInformationsForSell(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockInformationsForSell(Reader *param1);
  PaddockInformationsForSell();
  bool operator==(const PaddockInformationsForSell &compared);

  QString guildOwner;
  int worldX;
  int worldY;
  uint subAreaId;
  int nbMount;
  int nbObject;
  uint price;
};

#endif // PADDOCKINFORMATIONSFORSELL_H