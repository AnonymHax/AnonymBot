#ifndef SHORTCUTBARCONTENTMESSAGE_H
#define SHORTCUTBARCONTENTMESSAGE_H

#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"

class ShortcutBarContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShortcutBarContentMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShortcutBarContentMessage(Reader *param1);
  ShortcutBarContentMessage();

  uint barType;
  QList<QSharedPointer<Shortcut>> shortcuts;
};

#endif // SHORTCUTBARCONTENTMESSAGE_H