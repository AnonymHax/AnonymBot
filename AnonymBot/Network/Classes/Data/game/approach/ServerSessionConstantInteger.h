#ifndef SERVERSESSIONCONSTANTINTEGER_H
#define SERVERSESSIONCONSTANTINTEGER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"

class ServerSessionConstantInteger : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSessionConstantInteger(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSessionConstantInteger(Reader *param1);
  ServerSessionConstantInteger();
  bool operator==(const ServerSessionConstantInteger &compared);

  int value;
};

#endif // SERVERSESSIONCONSTANTINTEGER_H