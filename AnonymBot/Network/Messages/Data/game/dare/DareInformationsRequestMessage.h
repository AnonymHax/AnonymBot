#ifndef DAREINFORMATIONSREQUESTMESSAGE_H
#define DAREINFORMATIONSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareInformationsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareInformationsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareInformationsRequestMessage(Reader *param1);
  DareInformationsRequestMessage();

  double dareId;
};

#endif // DAREINFORMATIONSREQUESTMESSAGE_H