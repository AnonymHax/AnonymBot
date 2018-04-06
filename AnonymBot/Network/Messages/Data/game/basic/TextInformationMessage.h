#ifndef TEXTINFORMATIONMESSAGE_H
#define TEXTINFORMATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TextInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TextInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TextInformationMessage(Reader *param1);
  TextInformationMessage();

  uint msgType;
  uint msgId;
  QList<QString> parameters;
};

#endif // TEXTINFORMATIONMESSAGE_H