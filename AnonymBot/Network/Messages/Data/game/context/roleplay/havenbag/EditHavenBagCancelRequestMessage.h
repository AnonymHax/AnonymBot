#ifndef EDITHAVENBAGCANCELREQUESTMESSAGE_H
#define EDITHAVENBAGCANCELREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EditHavenBagCancelRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EditHavenBagCancelRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EditHavenBagCancelRequestMessage(Reader *param1);
  EditHavenBagCancelRequestMessage();
};

#endif // EDITHAVENBAGCANCELREQUESTMESSAGE_H