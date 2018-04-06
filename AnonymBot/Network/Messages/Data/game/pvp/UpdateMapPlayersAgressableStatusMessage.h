#ifndef UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H
#define UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class UpdateMapPlayersAgressableStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateMapPlayersAgressableStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateMapPlayersAgressableStatusMessage(Reader *param1);
  UpdateMapPlayersAgressableStatusMessage();

  QList<double> playerIds;
  QList<uint> enable;
};

#endif // UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H