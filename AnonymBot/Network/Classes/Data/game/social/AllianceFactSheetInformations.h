#ifndef ALLIANCEFACTSHEETINFORMATIONS_H
#define ALLIANCEFACTSHEETINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AllianceFactSheetInformations : public AllianceInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceFactSheetInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceFactSheetInformations(Reader *param1);
  AllianceFactSheetInformations();
  bool operator==(const AllianceFactSheetInformations &compared);

  uint creationDate;
};

#endif // ALLIANCEFACTSHEETINFORMATIONS_H