#include "ConsumableResource.h"

#include <stdexcept>
#include <iostream>

ConsumableResource::ConsumableResource(
    const std::string &name,
    const int capacity)
        :Resource(name, Type::Consumable),
    totalCapacity(capacity),
    remainingCapacity(capacity) {
    if (capacity <= 0)
        throw std::invalid_argument("Capacity for resource " + name + " must be positive");
}
bool ConsumableResource::isAvailableForUse() const {
    return remainingCapacity > 0;
}

void ConsumableResource::allocate() {
    if (remainingCapacity <= 0)
        throw std::runtime_error("No remaining capacity for consumable resource " + getName());
    remainingCapacity--;
    isAvailable = (remainingCapacity > 0);
}

void ConsumableResource::use() const  {
    std::cout << "Using consumable resource " << getName() << std::endl;
}

void ConsumableResource::release() {
    if (remainingCapacity == 0 && !isAvailable) {
        std::cerr << "Warning: Consumable resource '" << getName() << "' is depleted and cannot be reused without reallocation" << std::endl;
    }
    isAvailable = (remainingCapacity > 0);
}

int ConsumableResource::getRemainingCapacity() const {
    return remainingCapacity;
}




