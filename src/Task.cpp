#include "Task.h"
#include <iostream>

Task::Task(
    const std::string &name,
    const std::string &description,
    const std::vector<std::string> &requiredResourcesNames,
    const int durationUnits)
        :Executable(name, description, requiredResourcesNames, durationUnits)
{}

void Task::execute() const {
    if (assignedResources.size() != requiredResourcesNames.size())
        throw std::runtime_error("Not all resources are assigned to the task'" + name + "'");
    std::cout << "Executing task '" << getName() << "': " << description << " (Duration: " << durationUnits << ")" << std::endl;
    for (const auto& resource : assignedResources)
        resource->use();
}


