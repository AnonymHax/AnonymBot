#ifndef DOWNLOADERRORMESSAGE_H
#define DOWNLOADERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DownloadErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DownloadErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DownloadErrorMessage(Reader *param1);
  DownloadErrorMessage();

  uint errorId;
  QString message;
  QString helpUrl;
};

#endif // DOWNLOADERRORMESSAGE_H