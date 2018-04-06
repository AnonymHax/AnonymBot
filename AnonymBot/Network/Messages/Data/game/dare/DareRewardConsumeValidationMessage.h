#ifndef DAREREWARDCONSUMEVALIDATIONMESSAGE_H
#define DAREREWARDCONSUMEVALIDATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareRewardConsumeValidationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareRewardConsumeValidationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareRewardConsumeValidationMessage(Reader *param1);
  DareRewardConsumeValidationMessage();

  double dareId;
  uint type;
};

#endif // DAREREWARDCONSUMEVALIDATIONMESSAGE_H