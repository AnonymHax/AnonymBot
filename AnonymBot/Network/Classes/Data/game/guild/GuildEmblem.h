#ifndef GUILDEMBLEM_H
#define GUILDEMBLEM_H

#include "Network/Classes/AbstractClass.h"

class GuildEmblem : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildEmblem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildEmblem(Reader *param1);
  GuildEmblem();
  bool operator==(const GuildEmblem &compared);

  uint symbolShape;
  int symbolColor;
  uint backgroundShape;
  int backgroundColor;
};

#endif // GUILDEMBLEM_H