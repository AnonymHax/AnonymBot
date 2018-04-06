#ifndef SOUNDUIHOOKDATA_H
#define SOUNDUIHOOKDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SoundUiHookData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_name;
};

#endif // SOUNDUIHOOKDATA_H