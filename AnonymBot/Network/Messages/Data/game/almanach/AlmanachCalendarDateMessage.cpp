#include "AlmanachCalendarDateMessage.h"

void AlmanachCalendarDateMessage::serialize(Writer *param1)
{
  this->serializeAs_AlmanachCalendarDateMessage(param1);
}

void AlmanachCalendarDateMessage::serializeAs_AlmanachCalendarDateMessage(Writer *param1)
{
  param1->writeInt((int)this->date);
}

void AlmanachCalendarDateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AlmanachCalendarDateMessage(param1);
}

void AlmanachCalendarDateMessage::deserializeAs_AlmanachCalendarDateMessage(Reader *param1)
{
  this->date = param1->readInt();
}

AlmanachCalendarDateMessage::AlmanachCalendarDateMessage()
{
  m_type = MessageEnum::ALMANACHCALENDARDATEMESSAGE;
}

