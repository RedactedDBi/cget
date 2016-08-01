#include <command/install.h>
#include <iostream>

int cget::command::Install::invoke(const std::vector<std::string> &args) {
    std::cout << "ECHO: Passed command '" << name() << "'" << std::endl << std::endl;

    if (args.size() == 0) {
        std::cout << "No other args were passed" << std::endl;
    } else {
        std::cout << "The following args were passed:" << std::endl;
        for (int i = 0; i < args.size(); ++i) {
            std::cout << "   " << args[i] << std::endl;
        }
    }

    return 0;
}

cget::command::Install::Install(const std::string &_name) : Command(_name) {}
