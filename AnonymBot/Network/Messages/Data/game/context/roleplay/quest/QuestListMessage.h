#ifndef QUESTLISTMESSAGE_H
#define QUESTLISTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/ClassManager.h"

class QuestListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestListMessage(Reader *param1);
  QuestListMessage();

  QList<uint> finishedQuestsIds;
  QList<uint> finishedQuestsCounts;
  QList<QSharedPointer<QuestActiveInformations>> activeQuests;
  QList<uint> reinitDoneQuestsIds;
};

#endif // QUESTLISTMESSAGE_H