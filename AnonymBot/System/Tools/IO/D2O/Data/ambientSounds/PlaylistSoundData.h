#ifndef PLAYLISTSOUNDDATA_H
#define PLAYLISTSOUNDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class PlaylistSoundData : public AbstractGameData
{
public:
  QString getId() const;
  int getVolume() const;
  int getChannel() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  QString m_id;
  int m_volume;
  int m_channel;
};

#endif // PLAYLISTSOUNDDATA_H