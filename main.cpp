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
                { "CentralProcessingUnit", "Memory"},
                15));
    } catch (const std::exception &e) {
        std::cerr << "Critical error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}