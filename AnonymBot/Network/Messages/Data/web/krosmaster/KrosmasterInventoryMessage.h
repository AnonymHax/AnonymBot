#ifndef KROSMASTERINVENTORYMESSAGE_H
#define KROSMASTERINVENTORYMESSAGE_H

#include "Network/Classes/Data/web/krosmaster/KrosmasterFigure.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/web/krosmaster/KrosmasterFigure.h"

class KrosmasterInventoryMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterInventoryMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterInventoryMessage(Reader *param1);
  KrosmasterInventoryMessage();

  QList<KrosmasterFigure> figures;
};

#endif // KROSMASTERINVENTORYMESSAGE_H