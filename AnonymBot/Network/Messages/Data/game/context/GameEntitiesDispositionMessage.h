#ifndef GAMEENTITIESDISPOSITIONMESSAGE_H
#define GAMEENTITIESDISPOSITIONMESSAGE_H

#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"

class GameEntitiesDispositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameEntitiesDispositionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameEntitiesDispositionMessage(Reader *param1);
  GameEntitiesDispositionMessage();

  QList<QSharedPointer<IdentifiedEntityDispositionInformations>> dispositions;
};

#endif // GAMEENTITIESDISPOSITIONMESSAGE_H