#ifndef TITLESANDORNAMENTSLISTREQUESTMESSAGE_H
#define TITLESANDORNAMENTSLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitlesAndOrnamentsListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitlesAndOrnamentsListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitlesAndOrnamentsListRequestMessage(Reader *param1);
  TitlesAndOrnamentsListRequestMessage();
};

#endif // TITLESANDORNAMENTSLISTREQUESTMESSAGE_H