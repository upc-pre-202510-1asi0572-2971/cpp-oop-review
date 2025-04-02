#ifndef USABLERESOURCE_H
#define USABLERESOURCE_H

#include "Resource.h"

class UsableResource final : public Resource {
private:
  int capacity;

public:
  UsableResource(const std::string& name, int capacity);
  bool isAvailableForUse() const override;
  void allocate() override;
  void release() override;
  void use() override;
};
#endif //USABLERESOURCE_H
