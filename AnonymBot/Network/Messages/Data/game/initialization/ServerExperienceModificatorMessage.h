#ifndef SERVEREXPERIENCEMODIFICATORMESSAGE_H
#define SERVEREXPERIENCEMODIFICATORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ServerExperienceModificatorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServerExperienceModificatorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServerExperienceModificatorMessage(Reader *param1);
  ServerExperienceModificatorMessage();

  uint experiencePercent;
};

#endif // SERVEREXPERIENCEMODIFICATORMESSAGE_H