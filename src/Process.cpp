#include "Process.h"
#include <iostream>

Process::Process(
    const std::string &name,
    const std::string &description,
    const std::vector<std::string> &requiredResourcesNames,
    const int durationInUnits)
        :Executable(name, description, requiredResourcesNames, durationInUnits)
{
}

void Process::addResource(std::unique_ptr<Resource> resource) {
    resourcePool.push_back(std::move(resource));
}

void Process::addTask(std::unique_ptr<Executable> task) {
    tasks.push_back(std::move(task));
}

void Process::execute() const {
    if (!requiredResourcesNames.empty() &&
        assignedResources.size() != requiredResourcesNames.size())
        throw std::runtime_error("Required resource count does not match assigned resource count for process: " + name);
    std::cout << "Executing process: " << name << std::endl;
    // Use resource Pool
    if (!assignedResources.empty())
        for (const auto& resource : assignedResources)
            resource->use();

    for (const auto& task : tasks) {
        try {
            if (task->canExecute(resourcePool)) {
                task->assignResources(resourcePool);
                std::cout << "Executing task: " << task->getName() << std::endl;
                task->execute();
                task->releaseResources();
            } else {
                std::cout << "Cannot execute task: " << task->getName() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error executing task: " << task->getName() << ": " << e.what() << std::endl;
        }
    }
}

void Process::run() {
    try {
        if (requiredResourcesNames.empty() || canExecute(resourcePool)) {
            if (!requiredResourcesNames.empty())
                assignResources(resourcePool);
            execute();
            releaseResources();
            std::cout << "Executing process: " << name << std::endl;
        } else {
            throw std::runtime_error("Insufficient resources to execute process: " + name);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error executing process: " << name << ": " << e.what() << std::endl;
    }
}

