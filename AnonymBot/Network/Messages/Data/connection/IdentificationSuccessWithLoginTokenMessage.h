#ifndef IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H
#define IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/connection/IdentificationSuccessMessage.h"

class IdentificationSuccessWithLoginTokenMessage : public IdentificationSuccessMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationSuccessWithLoginTokenMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationSuccessWithLoginTokenMessage(Reader *param1);
  IdentificationSuccessWithLoginTokenMessage();

  QString loginToken;
};

#endif // IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H