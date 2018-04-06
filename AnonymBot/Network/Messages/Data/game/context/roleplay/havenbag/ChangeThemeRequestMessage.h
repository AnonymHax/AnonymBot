#ifndef CHANGETHEMEREQUESTMESSAGE_H
#define CHANGETHEMEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChangeThemeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChangeThemeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChangeThemeRequestMessage(Reader *param1);
  ChangeThemeRequestMessage();

  int theme;
};

#endif // CHANGETHEMEREQUESTMESSAGE_H