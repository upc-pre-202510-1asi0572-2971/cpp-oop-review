#ifndef CONSUMABLE_RESOURCE_H
#define CONSUMABLE_RESOURCE_H

#include "Resource.h"

class ConsumableResource final : public Resource {
private:
  int totalCapacity;
  int remainingCapacity;
public:
  ConsumableResource(const std::string& name, int capacity);
  [[nodiscard]] bool isAvailableForUse() const override;
  void allocate() override;
  void release() override;
  void use() const override;
  [[nodiscard]] int getRemainingCapacity() const;
};
#endif //CONSUMABLE_RESOURCE_H
