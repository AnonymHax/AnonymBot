#ifndef TITLESANDORNAMENTSLISTMESSAGE_H
#define TITLESANDORNAMENTSLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitlesAndOrnamentsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitlesAndOrnamentsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitlesAndOrnamentsListMessage(Reader *param1);
  TitlesAndOrnamentsListMessage();

  QList<uint> titles;
  QList<uint> ornaments;
  uint activeTitle;
  uint activeOrnament;
};

#endif // TITLESANDORNAMENTSLISTMESSAGE_H