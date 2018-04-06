#ifndef HAVENBAGFURNITURESREQUESTMESSAGE_H
#define HAVENBAGFURNITURESREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HavenBagFurnituresRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HavenBagFurnituresRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HavenBagFurnituresRequestMessage(Reader *param1);
  HavenBagFurnituresRequestMessage();

  QList<uint> cellIds;
  QList<int> funitureIds;
  QList<uint> orientations;
};

#endif // HAVENBAGFURNITURESREQUESTMESSAGE_H