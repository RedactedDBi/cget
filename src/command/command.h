#pragma once
#include <vector>
#include <string>

namespace cget {
    namespace command {
        // Abstract base for all commands
        class Command {
        private:
            std::string _name;

        public:
            Command(const Command&&) = delete;
            Command(const Command&) = delete;
            Command* operator=(const Command&) = delete;
            Command(const std::string &_name);

            // Get the name of this command
            std::string name() const;

            // Main sub-command entry point
            // Return value is zero for success and non-zero for failure
            virtual int invoke(const std::vector<std::string>& args) = 0;
        };
    }
}