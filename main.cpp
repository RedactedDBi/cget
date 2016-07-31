#include <string>
#include <iostream>
#include <inputparser.h>

using std::cout;
using std::cin;
using std::endl;

namespace {
    const std::string USAGE =
            "\n"
            "Usage: cget <command> [flags] [args...]\n"
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
    cout << USAGE;
    return 0;
}