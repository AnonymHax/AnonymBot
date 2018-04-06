#ifndef ALIGNMENTRANKUPDATEMESSAGE_H
#define ALIGNMENTRANKUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AlignmentRankUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlignmentRankUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlignmentRankUpdateMessage(Reader *param1);
  AlignmentRankUpdateMessage();

  uint alignmentRank;
  bool verbose;
};

#endif // ALIGNMENTRANKUPDATEMESSAGE_H