#ifndef ALMANACHCALENDARDATEMESSAGE_H
#define ALMANACHCALENDARDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AlmanachCalendarDateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlmanachCalendarDateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlmanachCalendarDateMessage(Reader *param1);
  AlmanachCalendarDateMessage();

  int date;
};

#endif // ALMANACHCALENDARDATEMESSAGE_H