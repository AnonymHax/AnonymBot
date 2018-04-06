#ifndef IDENTIFICATIONSUCCESSMESSAGE_H
#define IDENTIFICATIONSUCCESSMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IdentificationSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationSuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationSuccessMessage(Reader *param1);
  IdentificationSuccessMessage();

  QString login;
  QString nickname;
  uint accountId;
  uint communityId;
  bool hasRights;
  QString secretQuestion;
  double accountCreation;
  double subscriptionElapsedDuration;
  double subscriptionEndDate;
  bool wasAlreadyConnected;
  uint havenbagAvailableRoom;
};

#endif // IDENTIFICATIONSUCCESSMESSAGE_H