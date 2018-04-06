#ifndef CONTENTPART_H
#define CONTENTPART_H

#include "Network/Classes/AbstractClass.h"

class ContentPart : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContentPart(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContentPart(Reader *param1);
  ContentPart();
  bool operator==(const ContentPart &compared);

  QString id;
  uint state;
};

#endif // CONTENTPART_H