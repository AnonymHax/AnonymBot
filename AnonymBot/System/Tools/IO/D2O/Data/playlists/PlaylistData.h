#ifndef PLAYLISTDATA_H
#define PLAYLISTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/PlaylistSoundData.h"

class PlaylistData : public AbstractGameData
{
public:
  int getId() const;
  int getSilenceDuration() const;
  int getIteration() const;
  int getType() const;
  QList<PlaylistSoundData> getSounds() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_silenceDuration;
  int m_iteration;
  int m_type;
  QList<PlaylistSoundData> m_sounds;
};

#endif // PLAYLISTDATA_H