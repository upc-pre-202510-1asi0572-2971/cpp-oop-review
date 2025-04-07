#include "Executable.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

Executable::Executable(const std::string &name, std::string description, const std::vector<std::string> &requiredResourcesNames, int durationUnits)
    : name(name),
description(std::move(description)),
requiredResourcesNames(requiredResourcesNames),
durationUnits(durationUnits),
assignedResources() {
    if (name.empty())
        throw std::invalid_argument("Executable name cannot be empty");
    if (durationUnits <= 0)
        throw std::invalid_argument("Duration units must be positive");
}

std::string Executable::getName() const {
    return name;
}

const std::vector<std::string>& Executable::getRequiredResourcesNames() const {
    return requiredResourcesNames;
}

int Executable::getDurationUnits() const {
    return durationUnits;
}

void Executable::assignResources(
    const std::vector<std::unique_ptr<Resource> > &resourcePool) {
    assignedResources.clear();
    if (requiredResourcesNames.empty()) return;
    for (const auto &resourceName : requiredResourcesNames) {
        bool found = false;
        for (auto &resource : resourcePool) {
            if (resource-> getName() == resourceName &&
                resource-> isAvailableForUse()) {
                resource->allocate();
                assignedResources.push_back(resource.get());
                found = true;
                break;
            }
        }
        if (!found) {
            releaseResources();
            throw std::runtime_error("Resource " + resourceName +
                " not found or not available for " + name + " executable");
        }
    }
}

void Executable::releaseResources() {
    for (auto *resource : assignedResources) {
        try {
            resource->release();
        } catch (std::exception &e) {
            std::cerr << "Warning: Failed to release resource " << resource->getName()
                      << " for executable " << name << ": " << e.what() << std::endl;
        }
    }
    assignedResources.clear();
}

bool Executable::canExecute(const std::vector<std::unique_ptr<Resource> > &resourcePool) const {
    if (requiredResourcesNames.empty()) {
        std::cout << "No resources required for " << name << " executable" << std::endl;
        return true;
    }
    for (const auto &resourceName : requiredResourcesNames) {
        if (std::none_of(resourcePool.begin(), resourcePool.end(),
            ([&resourceName](const std::unique_ptr<Resource> &resource) {
                return resource->getName() == resourceName &&
                    resource->isAvailableForUse();
            }))) { return false; }

    }
    return true;
}


