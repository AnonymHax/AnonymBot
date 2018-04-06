#ifndef CHARACTERREPORTMESSAGE_H
#define CHARACTERREPORTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterReportMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterReportMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterReportMessage(Reader *param1);
  CharacterReportMessage();

  double reportedId;
  uint reason;
};

#endif // CHARACTERREPORTMESSAGE_H