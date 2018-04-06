#ifndef KROSMASTERFIGURE_H
#define KROSMASTERFIGURE_H

#include "Network/Classes/AbstractClass.h"

class KrosmasterFigure : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterFigure(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterFigure(Reader *param1);
  KrosmasterFigure();
  bool operator==(const KrosmasterFigure &compared);

  QString uid;
  uint figure;
  uint pedestal;
  bool bound;
};

#endif // KROSMASTERFIGURE_H