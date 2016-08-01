#pragma once
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

namespace cget {
    class Command;

    class CommandFactory {
    public:
        std::unique_ptr<Command> create(const std::string& name);
    };
}