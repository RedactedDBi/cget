#pragma once
#include <memory>
#include <string>

namespace cget {
    namespace command {
        class Command;

        class CommandFactory {
        public:
            std::unique_ptr<command::Command> create(const std::string& name);
        };
    }
}