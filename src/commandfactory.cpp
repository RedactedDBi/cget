#include <commandfactory.h>
#include <command/command.h>

// Sub commands
#include <command/install.h>

using std::string;
using std::vector;

std::unique_ptr<cget::Command> cget::CommandFactory::create(const string& name) {
    // Just return the install command for now
    return std::unique_ptr<Command>(new Install(name));
}
