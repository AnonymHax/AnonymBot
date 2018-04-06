#ifndef WORLDMAPDATA_H
#define WORLDMAPDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class WorldMapData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrigineX() const;
  int getOrigineY() const;
  double getMapWidth() const;
  double getMapHeight() const;
  uint getHorizontalChunck() const;
  uint getVerticalChunck() const;
  bool getViewableEverywhere() const;
  double getMinScale() const;
  double getMaxScale() const;
  double getStartScale() const;
  int getCenterX() const;
  int getCenterY() const;
  int getTotalWidth() const;
  int getTotalHeight() const;
  QList<QString> getZoom() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_origineX;
  int m_origineY;
  double m_mapWidth;
  double m_mapHeight;
  uint m_horizontalChunck;
  uint m_verticalChunck;
  bool m_viewableEverywhere;
  double m_minScale;
  double m_maxScale;
  double m_startScale;
  int m_centerX;
  int m_centerY;
  int m_totalWidth;
  int m_totalHeight;
  QList<QString> m_zoom;
};

#endif // WORLDMAPDATA_H