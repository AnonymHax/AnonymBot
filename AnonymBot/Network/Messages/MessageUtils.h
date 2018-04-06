#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H

#include "Public.h"
#include "Network/Messages/MessageEnum.h"

class MessageUtils
{
public:
  static QString getName(const MessageEnum &messageEnum);
};

#endif // MESSAGEUTILS_H