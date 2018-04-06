#ifndef DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H
#define DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DebugClearHighlightCellsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DebugClearHighlightCellsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DebugClearHighlightCellsMessage(Reader *param1);
  DebugClearHighlightCellsMessage();
};

#endif // DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H