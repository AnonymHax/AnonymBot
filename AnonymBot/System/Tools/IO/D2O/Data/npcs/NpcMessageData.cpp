#include "NpcMessageData.h"

int NpcMessageData::getId() const
{
  return m_id;
}

uint NpcMessageData::getMessageId() const
{
  return m_messageId;
}

QList<QString> NpcMessageData::getMessageParams() const
{
  return m_messageParams;
}

void NpcMessageData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "messageId")
        m_messageId = readUInt(field->getValue());
    
    else if(field->getName() == "messageParams")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_messageParams << readUTF(data);
    }
    
  }
}

