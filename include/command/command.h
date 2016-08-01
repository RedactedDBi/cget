#pragma once
#include <vector>
#include <string>

namespace cget {
    // Abstract base for all commands
    class Command {
    private:
        std::string _name;

    public:
        Command(const Command&&) = delete;
        Command(const Command&) = delete;
        Command* operator=(const Command&) = delete;
        Command(const std::string &_name);

        std::string name() const;
        virtual int invoke(const std::vector<std::string>& args) = 0;
    };
}