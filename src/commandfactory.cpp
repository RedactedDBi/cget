#include <commandfactory.h>
#include <command/command.h>
#include <unordered_map>

// Sub commands
#include <command/install.h>
#include <command/init.h>

using std::string;
using std::vector;

namespace {
    typedef cget::command::Command*(*RegFunc)(const std::string&);

    template <typename T>
    cget::command::Command* instantiate(const std::string& name) {
        return new T(name);
    }

    std::unordered_map<std::string, RegFunc> typeMap = {
            { "install", &instantiate<cget::command::Install> },
            { "init", &instantiate<cget::command::Init> },
    };
}

std::unique_ptr<cget::command::Command> cget::CommandFactory::create(const string& name) {
    if (typeMap.find(name) == typeMap.end())
        throw std::invalid_argument("Could not find command");

    return std::unique_ptr<command::Command>(typeMap[name](name));
}
