#ifndef DOCUMENTDATA_H
#define DOCUMENTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class DocumentData : public AbstractGameData
{
public:
  int getId() const;
  uint getTypeId() const;
  bool getShowTitle() const;
  bool getShowBackgroundImage() const;
  uint getTitleId() const;
  uint getAuthorId() const;
  uint getSubTitleId() const;
  uint getContentId() const;
  QString getContentCSS() const;
  QString getClientProperties() const;
  QString getTitle() const;
  QString getAuthor() const;
  QString getSubTitle() const;
  QString getContent() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_typeId;
  bool m_showTitle;
  bool m_showBackgroundImage;
  uint m_titleId;
  uint m_authorId;
  uint m_subTitleId;
  uint m_contentId;
  QString m_contentCSS;
  QString m_clientProperties;
};

#endif // DOCUMENTDATA_H