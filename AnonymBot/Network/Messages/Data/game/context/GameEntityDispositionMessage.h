#ifndef GAMEENTITYDISPOSITIONMESSAGE_H
#define GAMEENTITYDISPOSITIONMESSAGE_H

#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"

class GameEntityDispositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameEntityDispositionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameEntityDispositionMessage(Reader *param1);
  GameEntityDispositionMessage();

  QSharedPointer<IdentifiedEntityDispositionInformations> disposition;
};

#endif // GAMEENTITYDISPOSITIONMESSAGE_H