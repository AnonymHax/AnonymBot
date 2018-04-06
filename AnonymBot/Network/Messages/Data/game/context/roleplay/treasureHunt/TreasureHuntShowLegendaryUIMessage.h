#ifndef TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H
#define TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntShowLegendaryUIMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntShowLegendaryUIMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntShowLegendaryUIMessage(Reader *param1);
  TreasureHuntShowLegendaryUIMessage();

  QList<uint> availableLegendaryIds;
};

#endif // TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H