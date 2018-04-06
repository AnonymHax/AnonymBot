#ifndef SERVERDATA_H
#define SERVERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ServerData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getCommentId() const;
  double getOpeningDate() const;
  QString getLanguage() const;
  int getPopulationId() const;
  uint getGameTypeId() const;
  int getCommunityId() const;
  QList<QString> getRestrictedToLanguages() const;
  QString getName() const;
  QString getComment() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_commentId;
  double m_openingDate;
  QString m_language;
  int m_populationId;
  uint m_gameTypeId;
  int m_communityId;
  QList<QString> m_restrictedToLanguages;
};

#endif // SERVERDATA_H