#include <command/command.h>

std::string cget::Command::name() const {
    return _name;
}

cget::Command::Command(const std::string &_name)
        : _name(_name) {}
