#include <commandfactory.h>
#include <command/command.h>

using std::string;
using std::vector;

std::unique_ptr<cget::Command> cget::CommandFactory::create(const string& name) {
    throw std::invalid_argument("Not implemented");
}
