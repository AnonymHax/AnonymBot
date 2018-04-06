#ifndef GUILDINFOSUPGRADEMESSAGE_H
#define GUILDINFOSUPGRADEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInfosUpgradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInfosUpgradeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInfosUpgradeMessage(Reader *param1);
  GuildInfosUpgradeMessage();

  uint maxTaxCollectorsCount;
  uint taxCollectorsCount;
  uint taxCollectorLifePoints;
  uint taxCollectorDamagesBonuses;
  uint taxCollectorPods;
  uint taxCollectorProspecting;
  uint taxCollectorWisdom;
  uint boostPoints;
  QList<uint> spellId;
  QList<int> spellLevel;
};

#endif // GUILDINFOSUPGRADEMESSAGE_H