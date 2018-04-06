#ifndef STARTUPACTIONADDOBJECT_H
#define STARTUPACTIONADDOBJECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItemInformationWithQuantity.h"
#include "Network/Classes/Data/game/data/items/ObjectItemInformationWithQuantity.h"

class StartupActionAddObject : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionAddObject(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionAddObject(Reader *param1);
  StartupActionAddObject();
  bool operator==(const StartupActionAddObject &compared);

  uint uid;
  QString title;
  QString text;
  QString descUrl;
  QString pictureUrl;
  QList<QSharedPointer<ObjectItemInformationWithQuantity>> items;
};

#endif // STARTUPACTIONADDOBJECT_H