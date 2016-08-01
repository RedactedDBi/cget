#include <commandfactory.h>
#include <command/command.h>
#include <unordered_map>

// Sub commands
#include <command/install.h>
#include <command/init.h>

using std::string;
using std::vector;

namespace {
    typedef cget::Command*(*RegFunc)(const std::string&);

    template <typename T>
    cget::Command* instantiate(const std::string& name) {
        return new T(name);
    }

    std::unordered_map<std::string, RegFunc> typeMap = {
            { "install", &instantiate<cget::Install> },
            { "init", &instantiate<cget::Init> },
    };
}

std::unique_ptr<cget::Command> cget::CommandFactory::create(const string& name) {
    if (typeMap.find(name) == typeMap.end())
        throw std::invalid_argument("Could not find command");

    return std::unique_ptr<Command>(typeMap[name](name));
}
