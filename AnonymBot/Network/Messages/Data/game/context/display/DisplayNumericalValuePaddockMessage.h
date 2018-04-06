#ifndef DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H
#define DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DisplayNumericalValuePaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DisplayNumericalValuePaddockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DisplayNumericalValuePaddockMessage(Reader *param1);
  DisplayNumericalValuePaddockMessage();

  int rideId;
  int value;
  uint type;
};

#endif // DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H