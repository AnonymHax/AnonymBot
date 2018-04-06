#ifndef DAREINFORMATIONSMESSAGE_H
#define DAREINFORMATIONSMESSAGE_H

#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"

class DareInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareInformationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareInformationsMessage(Reader *param1);
  DareInformationsMessage();

  DareInformations dareFixedInfos;
  DareVersatileInformations dareVersatilesInfos;
};

#endif // DAREINFORMATIONSMESSAGE_H