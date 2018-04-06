#include "AllianceTaxCollectorDialogQuestionExtendedMessage.h"

void AllianceTaxCollectorDialogQuestionExtendedMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(param1);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Writer *param1)
{
  TaxCollectorDialogQuestionExtendedMessage::serializeAs_TaxCollectorDialogQuestionExtendedMessage(param1);
  this->alliance->serializeAs_BasicNamedAllianceInformations(param1);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(param1);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Reader *param1)
{
  TaxCollectorDialogQuestionExtendedMessage::deserialize(param1);
  this->alliance = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->alliance->deserialize(param1);
}

AllianceTaxCollectorDialogQuestionExtendedMessage::AllianceTaxCollectorDialogQuestionExtendedMessage()
{
  m_type = MessageEnum::ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE;
}

