#ifndef SOUNDUIELEMENTDATA_H
#define SOUNDUIELEMENTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SoundUiElementData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getName() const;
  uint getHookId() const;
  QString getFile() const;
  uint getVolume() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_name;
  uint m_hookId;
  QString m_file;
  uint m_volume;
};

#endif // SOUNDUIELEMENTDATA_H