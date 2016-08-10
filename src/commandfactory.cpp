#include "commandfactory.h"
#include "command/command.h"
#include <unordered_map>

// Sub commands
#include "command/install.h"
#include "command/init.h"
#include <algorithm>

using std::string;
using std::vector;

#define REGISTER(name) { toLower(#name), &instantiate<cget::command::name> }

namespace {
    typedef cget::command::Command*(*RegFunc)(const std::string&);

    std::string toLower(const std::string& input) {
        std::string output = input;
        std::transform(output.begin(), output.end(), output.begin(), ::tolower);
        return output;
    }

    template <typename T>
    cget::command::Command* instantiate(const std::string& name) {
        return new T(name);
    }

    /* NOTE: In order to register commands:
     * REGISTER(<name>) assumes that there's a member cget::command::<name> which inherits from cget::command::Command.
     * The usable terminal sub-command will be the lowercase version of whatever <name> is. That is, REGISTER(Install)
     * will register an instance Install : public Command and expose an "install" command from the terminal */
    std::unordered_map<std::string, RegFunc> typeMap = {
        REGISTER(Install),
        REGISTER(Init),
    };
}

std::unique_ptr<cget::command::Command> cget::CommandFactory::create(const string& name) {
    if (typeMap.find(name) == typeMap.end())
        throw std::invalid_argument("Could not find command");

    return std::unique_ptr<command::Command>(typeMap[name](name));
}
