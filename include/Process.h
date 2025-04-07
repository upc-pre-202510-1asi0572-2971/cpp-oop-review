#ifndef PROCESS_H
#define PROCESS_H

#include "Executable.h"

class Process final : public Executable {
private:
    std::vector<std::unique_ptr<Resource>> resourcePool;
    std::vector<std::unique_ptr<Executable>> tasks;
public:
      Process(  const std::string& name,
                const std::string& description,
                const std::vector<std::string>& requiredResourcesNames,
                int durationInUnits);
      void addTask(std::unique_ptr<Executable> task);
      void execute() const override;
      void run();
};

#endif //PROCESS_H
