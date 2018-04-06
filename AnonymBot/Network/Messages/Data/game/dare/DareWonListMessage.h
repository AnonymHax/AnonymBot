#ifndef DAREWONLISTMESSAGE_H
#define DAREWONLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareWonListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareWonListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareWonListMessage(Reader *param1);
  DareWonListMessage();

  QList<double> dareId;
};

#endif // DAREWONLISTMESSAGE_H