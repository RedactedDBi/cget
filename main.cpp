#include <string>
#include <iostream>
#include <unordered_map>
#include "src/cget.h"

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::string;

namespace {
    const string USAGE =
            "\n"
            "Usage: cget <command> [flags...] [args...]\n"
            "\n"
            "The most commonly used cget commands are:\n"
            "   init         Initialize a new module, and create a cget.json\n"
            "   install      Install a dependency\n"
            "   uninstall    Uninstall a dependency\n"
            "   update       Recursively check dependencies for newer versions\n"
            "\n"
            "Example usages:\n"
            "\n"
            "cget install example/dep         # Install latest registered semver\n"
            "cget install example/dep:^5.0    # Install v5.0 or greater\n"
            "cget install example/dep:~5.0    # Install latest version within v5.0\n"
            "\n";
}

int main(int argc, char* argv[]) {
    // Shove incoming args into a vector
    cget::InputParser::Args initialArgs, subCmdArgs;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        // Special case: If we encounter a version flag,
        // we'll just print the version and bail out
        if (arg == "--version" || arg == "-v") {
            std::cout << cget::CGET_VERSION << std::endl;
            return 0;
        }

        initialArgs.push_back(arg);
    }

    try {
        // Try to parse the sub command
        auto subCmd = cget::InputParser::parseSubCommand(initialArgs, &subCmdArgs);
        cget::command::CommandFactory cmdFactory;
        auto cmd = cmdFactory.create(subCmd);
        return cmd ? cmd->invoke(subCmdArgs) : 1;
    } catch(std::invalid_argument) {
        // Just show the usage if we failed parsing
        cout << USAGE;
        return 1;
    }
}