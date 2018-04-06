#ifndef MAPFIGHTCOUNTMESSAGE_H
#define MAPFIGHTCOUNTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MapFightCountMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapFightCountMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapFightCountMessage(Reader *param1);
  MapFightCountMessage();

  uint fightCount;
};

#endif // MAPFIGHTCOUNTMESSAGE_H