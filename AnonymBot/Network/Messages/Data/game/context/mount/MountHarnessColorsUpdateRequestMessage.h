#ifndef MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H
#define MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountHarnessColorsUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountHarnessColorsUpdateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountHarnessColorsUpdateRequestMessage(Reader *param1);
  MountHarnessColorsUpdateRequestMessage();

  bool useHarnessColors;
};

#endif // MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H