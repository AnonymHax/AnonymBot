#ifndef IGNOREDDELETERESULTMESSAGE_H
#define IGNOREDDELETERESULTMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IgnoredDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredDeleteResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredDeleteResultMessage(Reader *param1);
  IgnoredDeleteResultMessage();

  bool success;
  QString name;
  bool session;
};

#endif // IGNOREDDELETERESULTMESSAGE_H