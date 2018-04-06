#ifndef SPEAKINGITEMTEXTDATA_H
#define SPEAKINGITEMTEXTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SpeakingItemTextData : public AbstractGameData
{
public:
  int getTextId() const;
  double getTextProba() const;
  uint getTextStringId() const;
  int getTextLevel() const;
  int getTextSound() const;
  QString getTextRestriction() const;
  QString getTextString() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_textId;
  double m_textProba;
  uint m_textStringId;
  int m_textLevel;
  int m_textSound;
  QString m_textRestriction;
};

#endif // SPEAKINGITEMTEXTDATA_H