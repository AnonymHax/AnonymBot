#ifndef IDOLPARTYREGISTERREQUESTMESSAGE_H
#define IDOLPARTYREGISTERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolPartyRegisterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolPartyRegisterRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolPartyRegisterRequestMessage(Reader *param1);
  IdolPartyRegisterRequestMessage();

  bool m_register;
};

#endif // IDOLPARTYREGISTERREQUESTMESSAGE_H
