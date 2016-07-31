#pragma once
#include <vector>
#include <string>

namespace cget {
    // Abstract base for all commands
    class Command {
    public:
        virtual int invoke(const std::vector<std::string>& args) = 0;
    };
}