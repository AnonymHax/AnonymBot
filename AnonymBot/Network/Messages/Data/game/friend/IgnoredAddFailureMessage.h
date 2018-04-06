#ifndef IGNOREDADDFAILUREMESSAGE_H
#define IGNOREDADDFAILUREMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IgnoredAddFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredAddFailureMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredAddFailureMessage(Reader *param1);
  IgnoredAddFailureMessage();

  uint reason;
};

#endif // IGNOREDADDFAILUREMESSAGE_H