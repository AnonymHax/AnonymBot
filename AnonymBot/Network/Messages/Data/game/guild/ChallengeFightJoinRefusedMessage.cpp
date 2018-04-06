#include "ChallengeFightJoinRefusedMessage.h"

void ChallengeFightJoinRefusedMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeFightJoinRefusedMessage(param1);
}

void ChallengeFightJoinRefusedMessage::serializeAs_ChallengeFightJoinRefusedMessage(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChallengeFightJoinRefusedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeByte(this->reason);
    return;
  }
}

void ChallengeFightJoinRefusedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeFightJoinRefusedMessage(param1);
}

void ChallengeFightJoinRefusedMessage::deserializeAs_ChallengeFightJoinRefusedMessage(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChallengeFightJoinRefusedMessage -"<<"Forbidden value (" << this->playerId << ") on element of ChallengeFightJoinRefusedMessage.playerId.";
  }
  else
  {
    this->reason = param1->readByte();
    return;
  }
}

ChallengeFightJoinRefusedMessage::ChallengeFightJoinRefusedMessage()
{
  m_type = MessageEnum::CHALLENGEFIGHTJOINREFUSEDMESSAGE;
}

