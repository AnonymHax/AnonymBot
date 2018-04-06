#include "BasicLatencyStatsMessage.h"

void BasicLatencyStatsMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicLatencyStatsMessage(param1);
}

void BasicLatencyStatsMessage::serializeAs_BasicLatencyStatsMessage(Writer *param1)
{
  if(this->latency < 0 || this->latency > 65535)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->latency << ") on element latency.";
  }
  else
  {
    param1->writeShort((short)this->latency);
    if(this->sampleCount < 0)
    {
      qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->sampleCount << ") on element sampleCount.";
    }
    else
    {
      param1->writeVarShort((int)this->sampleCount);
      if(this->max < 0)
      {
        qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->max << ") on element max.";
      }
      else
      {
        param1->writeVarShort((int)this->max);
        return;
      }
    }
  }
}

void BasicLatencyStatsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicLatencyStatsMessage(param1);
}

void BasicLatencyStatsMessage::deserializeAs_BasicLatencyStatsMessage(Reader *param1)
{
  this->latency = param1->readUShort();
  if(this->latency < 0 || this->latency > 65535)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->latency << ") on element of BasicLatencyStatsMessage.latency.";
  }
  else
  {
    this->sampleCount = param1->readVarUhShort();
    if(this->sampleCount < 0)
    {
      qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->sampleCount << ") on element of BasicLatencyStatsMessage.sampleCount.";
    }
    else
    {
      this->max = param1->readVarUhShort();
      if(this->max < 0)
      {
        qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->max << ") on element of BasicLatencyStatsMessage.max.";
      }
      else
      {
        return;
      }
    }
  }
}

BasicLatencyStatsMessage::BasicLatencyStatsMessage()
{
  m_type = MessageEnum::BASICLATENCYSTATSMESSAGE;
  m_needsHash = true;
}

