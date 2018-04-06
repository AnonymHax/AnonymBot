#ifndef PRISMGEOLOCALIZEDINFORMATION_H
#define PRISMGEOLOCALIZEDINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/ClassManager.h"

class PrismGeolocalizedInformation : public PrismSubareaEmptyInfo
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismGeolocalizedInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismGeolocalizedInformation(Reader *param1);
  PrismGeolocalizedInformation();
  bool operator==(const PrismGeolocalizedInformation &compared);

  int worldX;
  int worldY;
  int mapId;
  QSharedPointer<PrismInformation> prism;
};

#endif // PRISMGEOLOCALIZEDINFORMATION_H