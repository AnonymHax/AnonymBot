#ifndef NPCDIALOGCREATIONMESSAGE_H
#define NPCDIALOGCREATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NpcDialogCreationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NpcDialogCreationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NpcDialogCreationMessage(Reader *param1);
  NpcDialogCreationMessage();

  int mapId;
  int npcId;
};

#endif // NPCDIALOGCREATIONMESSAGE_H