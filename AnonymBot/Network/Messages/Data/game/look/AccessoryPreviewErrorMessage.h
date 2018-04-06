#ifndef ACCESSORYPREVIEWERRORMESSAGE_H
#define ACCESSORYPREVIEWERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AccessoryPreviewErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccessoryPreviewErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccessoryPreviewErrorMessage(Reader *param1);
  AccessoryPreviewErrorMessage();

  uint error;
};

#endif // ACCESSORYPREVIEWERRORMESSAGE_H