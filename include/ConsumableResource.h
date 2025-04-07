#ifndef CONSUMABLERESOURCE_H
#define CONSUMABLERESOURCE_H

#include "Resource.h"

class ConsumableResource final : public Resource {
private:
  int totalCapacity;
  int remainingCapacity;
public:
  ConsumableResource(const std::string& name, int capacity);
  bool isAvailableForUse() const override;
  void allocate() override;
  void release() override;
  void use() const override;
  int getRemainingCapacity() const;
};
#endif //CONSUMABLERESOURCE_H
