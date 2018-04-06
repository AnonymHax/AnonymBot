#ifndef IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H
#define IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class IdentifiedEntityDispositionInformations : public EntityDispositionInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentifiedEntityDispositionInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentifiedEntityDispositionInformations(Reader *param1);
  IdentifiedEntityDispositionInformations();
  bool operator==(const IdentifiedEntityDispositionInformations &compared);

  double id;
};

#endif // IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H