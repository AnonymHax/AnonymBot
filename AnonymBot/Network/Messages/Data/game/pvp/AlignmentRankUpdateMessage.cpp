#include "AlignmentRankUpdateMessage.h"

void AlignmentRankUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_AlignmentRankUpdateMessage(param1);
}

void AlignmentRankUpdateMessage::serializeAs_AlignmentRankUpdateMessage(Writer *param1)
{
  if(this->alignmentRank < 0)
  {
    qDebug()<<"ERREUR - AlignmentRankUpdateMessage -"<<"Forbidden value (" << this->alignmentRank << ") on element alignmentRank.";
  }
  else
  {
    param1->writeByte(this->alignmentRank);
    param1->writeBool(this->verbose);
    return;
  }
}

void AlignmentRankUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AlignmentRankUpdateMessage(param1);
}

void AlignmentRankUpdateMessage::deserializeAs_AlignmentRankUpdateMessage(Reader *param1)
{
  this->alignmentRank = param1->readByte();
  if(this->alignmentRank < 0)
  {
    qDebug()<<"ERREUR - AlignmentRankUpdateMessage -"<<"Forbidden value (" << this->alignmentRank << ") on element of AlignmentRankUpdateMessage.alignmentRank.";
  }
  else
  {
    this->verbose = param1->readBool();
    return;
  }
}

AlignmentRankUpdateMessage::AlignmentRankUpdateMessage()
{
  m_type = MessageEnum::ALIGNMENTRANKUPDATEMESSAGE;
}

