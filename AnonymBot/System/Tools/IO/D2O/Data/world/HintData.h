#ifndef HINTDATA_H
#define HINTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class HintData : public AbstractGameData
{
public:
  int getId() const;
  uint getGfx() const;
  uint getNameId() const;
  uint getMapId() const;
  uint getRealMapId() const;
  int getX() const;
  int getY() const;
  bool getOutdoor() const;
  int getSubareaId() const;
  int getWorldMapId() const;
  uint getLevel() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_gfx;
  uint m_nameId;
  uint m_mapId;
  uint m_realMapId;
  int m_x;
  int m_y;
  bool m_outdoor;
  int m_subareaId;
  int m_worldMapId;
  uint m_level;
};

#endif // HINTDATA_H