#ifndef TASK_H
#define TASK_H

#include "Executable.h"

class Task final : public Executable {
  public:
    Task(const std::string& name,
        const std::string& description,
        const std::vector<std::string>& requiredResourcesNames,
        int durationUnits);
    void execute() const override;
};
#endif //TASK_H
