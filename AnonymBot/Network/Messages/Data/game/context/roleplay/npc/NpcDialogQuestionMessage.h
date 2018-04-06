#ifndef NPCDIALOGQUESTIONMESSAGE_H
#define NPCDIALOGQUESTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NpcDialogQuestionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NpcDialogQuestionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NpcDialogQuestionMessage(Reader *param1);
  NpcDialogQuestionMessage();

  uint messageId;
  QList<QString> dialogParams;
  QList<uint> visibleReplies;
};

#endif // NPCDIALOGQUESTIONMESSAGE_H