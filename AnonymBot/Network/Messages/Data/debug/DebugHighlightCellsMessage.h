#ifndef DEBUGHIGHLIGHTCELLSMESSAGE_H
#define DEBUGHIGHLIGHTCELLSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DebugHighlightCellsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DebugHighlightCellsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DebugHighlightCellsMessage(Reader *param1);
  DebugHighlightCellsMessage();

  int color;
  QList<uint> cells;
};

#endif // DEBUGHIGHLIGHTCELLSMESSAGE_H