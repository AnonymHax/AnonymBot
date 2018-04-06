#ifndef RAWDATAMESSAGE_H
#define RAWDATAMESSAGE_H

#include "AbstractDofusMessage.h"

class RawDataMessage : public AbstractDofusMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_RawDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_RawDataMessage(Reader *param1);
  RawDataMessage();

  QByteArray content;
  QString ticket;
};

#endif // RAWDATAMESSAGE_H
