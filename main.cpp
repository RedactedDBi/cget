#include <string>
#include <iostream>
#include <unordered_map>
#include <inputparser.h>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::string;

namespace {
    const string USAGE =
            "\n"
            "Usage: cget <command> [flags] [argsFullFlag...]\n"
            "\n"
            "The most commonly used cget commands are:\n"
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
    cget::InputParser::ShortFlags flags;
    cget::InputParser parser(flags);
    cget::InputParser::Args args;
    cget::InputParser::Result result;

    for (int i = 1; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }

    try {
        parser.parse(args, &result);
    } catch(std::invalid_argument) {
        // Just show the usage if we failed parsing
        cout << USAGE;
        return 1;
    }

    return 0;
}