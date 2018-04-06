#include "TaxCollectorDialogQuestionBasicMessage.h"

void TaxCollectorDialogQuestionBasicMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorDialogQuestionBasicMessage(param1);
}

void TaxCollectorDialogQuestionBasicMessage::serializeAs_TaxCollectorDialogQuestionBasicMessage(Writer *param1)
{
  this->guildInfo->serializeAs_BasicGuildInformations(param1);
}

void TaxCollectorDialogQuestionBasicMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorDialogQuestionBasicMessage(param1);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAs_TaxCollectorDialogQuestionBasicMessage(Reader *param1)
{
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserialize(param1);
}

TaxCollectorDialogQuestionBasicMessage::TaxCollectorDialogQuestionBasicMessage()
{
  m_type = MessageEnum::TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE;
}

