#pragma once
#include <command/command.h>

namespace cget {
    class Init : public Command {
    public:
        Init(const std::string &_name);
        int invoke(const std::vector<std::string> &args) override;
    };
}