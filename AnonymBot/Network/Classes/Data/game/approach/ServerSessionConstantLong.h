#ifndef SERVERSESSIONCONSTANTLONG_H
#define SERVERSESSIONCONSTANTLONG_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"

class ServerSessionConstantLong : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSessionConstantLong(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSessionConstantLong(Reader *param1);
  ServerSessionConstantLong();
  bool operator==(const ServerSessionConstantLong &compared);

  double value;
};

#endif // SERVERSESSIONCONSTANTLONG_H