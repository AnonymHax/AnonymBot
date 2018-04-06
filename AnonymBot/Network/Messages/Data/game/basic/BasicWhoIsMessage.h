#ifndef BASICWHOISMESSAGE_H
#define BASICWHOISMESSAGE_H

#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Classes/ClassManager.h"

class BasicWhoIsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicWhoIsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicWhoIsMessage(Reader *param1);
  BasicWhoIsMessage();

  bool self;
  int position;
  QString accountNickname;
  uint accountId;
  QString playerName;
  double playerId;
  int areaId;
  int serverId;
  int originServerId;
  QList<QSharedPointer<AbstractSocialGroupInfos>> socialGroups;
  bool verbose;
  uint playerState;
};

#endif // BASICWHOISMESSAGE_H