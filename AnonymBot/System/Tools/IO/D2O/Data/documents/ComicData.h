#ifndef COMICDATA_H
#define COMICDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ComicData : public AbstractGameData
{
public:
  int getId() const;
  QString getRemoteId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_remoteId;
};

#endif // COMICDATA_H