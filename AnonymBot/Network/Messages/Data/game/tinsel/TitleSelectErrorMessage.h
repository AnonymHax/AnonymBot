#ifndef TITLESELECTERRORMESSAGE_H
#define TITLESELECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitleSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitleSelectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitleSelectErrorMessage(Reader *param1);
  TitleSelectErrorMessage();

  uint reason;
};

#endif // TITLESELECTERRORMESSAGE_H