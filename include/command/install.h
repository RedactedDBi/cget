#pragma once
#include <command/command.h>

namespace cget {
    namespace command {
        class Install : public Command {
        public:
            Install(const std::string &_name);

        private:
            int invoke(const std::vector<std::string>& args) override;
        };
    }
}