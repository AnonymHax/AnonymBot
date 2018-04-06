#ifndef TRUSTCERTIFICATE_H
#define TRUSTCERTIFICATE_H

#include "Network/Classes/AbstractClass.h"

class TrustCertificate : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TrustCertificate(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TrustCertificate(Reader *param1);
  TrustCertificate();
  bool operator==(const TrustCertificate &compared);

  uint id;
  QString hash;
};

#endif // TRUSTCERTIFICATE_H