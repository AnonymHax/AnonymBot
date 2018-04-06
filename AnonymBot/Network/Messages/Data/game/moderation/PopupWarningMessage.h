#ifndef POPUPWARNINGMESSAGE_H
#define POPUPWARNINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PopupWarningMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PopupWarningMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PopupWarningMessage(Reader *param1);
  PopupWarningMessage();

  uint lockDuration;
  QString author;
  QString content;
};

#endif // POPUPWARNINGMESSAGE_H