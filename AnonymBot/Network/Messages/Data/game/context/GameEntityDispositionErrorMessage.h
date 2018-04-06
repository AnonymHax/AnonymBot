#ifndef GAMEENTITYDISPOSITIONERRORMESSAGE_H
#define GAMEENTITYDISPOSITIONERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameEntityDispositionErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameEntityDispositionErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameEntityDispositionErrorMessage(Reader *param1);
  GameEntityDispositionErrorMessage();
};

#endif // GAMEENTITYDISPOSITIONERRORMESSAGE_H