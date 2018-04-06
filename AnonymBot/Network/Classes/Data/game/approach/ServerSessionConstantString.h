#ifndef SERVERSESSIONCONSTANTSTRING_H
#define SERVERSESSIONCONSTANTSTRING_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"

class ServerSessionConstantString : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSessionConstantString(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSessionConstantString(Reader *param1);
  ServerSessionConstantString();
  bool operator==(const ServerSessionConstantString &compared);

  QString value;
};

#endif // SERVERSESSIONCONSTANTSTRING_H