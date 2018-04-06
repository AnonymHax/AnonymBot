#ifndef SERVERSESSIONCONSTANT_H
#define SERVERSESSIONCONSTANT_H

#include "Network/Classes/AbstractClass.h"

class ServerSessionConstant : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerSessionConstant(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerSessionConstant(Reader *param1);
  ServerSessionConstant();
  bool operator==(const ServerSessionConstant &compared);

  uint id;
};

#endif // SERVERSESSIONCONSTANT_H