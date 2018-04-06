#ifndef MAPPOSITIONDATA_H
#define MAPPOSITIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/AmbientSoundData.h"

class MapPositionData : public AbstractGameData
{
public:
  int getId() const;
  int getPosX() const;
  int getPosY() const;
  bool getOutdoor() const;
  int getCapabilities() const;
  int getNameId() const;
  bool getShowNameOnFingerpost() const;
  QList<AmbientSoundData> getSounds() const;
  QList<QList<int>> getPlaylists() const;
  int getSubAreaId() const;
  int getWorldMap() const;
  bool getHasPriorityOnWorldmap() const;
  bool getIsUnderWater() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_posX;
  int m_posY;
  bool m_outdoor;
  int m_capabilities;
  int m_nameId;
  bool m_showNameOnFingerpost;
  QList<AmbientSoundData> m_sounds;
  QList<QList<int>> m_playlists;
  int m_subAreaId;
  int m_worldMap;
  bool m_hasPriorityOnWorldmap;
  bool m_isUnderWater;
};

#endif // MAPPOSITIONDATA_H