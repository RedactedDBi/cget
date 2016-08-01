#include <command/command.h>

std::string cget::command::Command::name() const {
    return _name;
}

cget::command::Command::Command(const std::string &_name)
        : _name(_name) {}
