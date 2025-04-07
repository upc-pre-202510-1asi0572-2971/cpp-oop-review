#include "Process.h"
#include "Task.h"
#include "UsableResource.h"
#include "ConsumableResource.h"
#include <iostream>

int main() {
    try {
        const auto compilationProcess = std::unique_ptr<Process>(
            new Process(
                "CompileMain",
                "Compile main.cpp to main.exe",
                {"CentralProcessingUnit", "Memory"},
                15));
        // Add resources to the process
        compilationProcess->addResource(
            std::unique_ptr<ConsumableResource>(
                new ConsumableResource("Memory", 4096)));
        compilationProcess->addResource(
            std::unique_ptr<UsableResource>(
                new UsableResource("CentralProcessingUnit", 3)));
        // Define compilation tasks
        compilationProcess->addTask(
            std::unique_ptr<Task>(
                new Task("ScanSourceCode", "Tokenize main.c",
                         {"CentralProcessingUnit", "Memory"}, 2)));
        // Run the process
        std::cout << "Running process: " << compilationProcess->getName() << std::endl;
        compilationProcess->run();
    } catch (const std::exception &e) {
        std::cerr << "Critical error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
