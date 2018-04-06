#ifndef GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H
#define GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextRemoveMultipleElementsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextRemoveMultipleElementsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextRemoveMultipleElementsMessage(Reader *param1);
  GameContextRemoveMultipleElementsMessage();

  QList<double> id;
};

#endif // GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H