#ifndef INTERACTIVEUSEERRORMESSAGE_H
#define INTERACTIVEUSEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InteractiveUseErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveUseErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveUseErrorMessage(Reader *param1);
  InteractiveUseErrorMessage();

  uint elemId;
  uint skillInstanceUid;
};

#endif // INTERACTIVEUSEERRORMESSAGE_H