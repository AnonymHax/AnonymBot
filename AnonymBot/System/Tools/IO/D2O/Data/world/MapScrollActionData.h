#ifndef MAPSCROLLACTIONDATA_H
#define MAPSCROLLACTIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MapScrollActionData : public AbstractGameData
{
public:
  int getId() const;
  bool getRightExists() const;
  bool getBottomExists() const;
  bool getLeftExists() const;
  bool getTopExists() const;
  int getRightMapId() const;
  int getBottomMapId() const;
  int getLeftMapId() const;
  int getTopMapId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  bool m_rightExists;
  bool m_bottomExists;
  bool m_leftExists;
  bool m_topExists;
  int m_rightMapId;
  int m_bottomMapId;
  int m_leftMapId;
  int m_topMapId;
};

#endif // MAPSCROLLACTIONDATA_H