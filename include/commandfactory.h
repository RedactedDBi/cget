#pragma once
#include <memory>
#include <string>

namespace cget {
    class Command;

    class CommandFactory {
    public:
        std::unique_ptr<Command> create(const std::string& name);
    };
}