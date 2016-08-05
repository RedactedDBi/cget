#include <command/install.h>
#include <inputparser.h>
#include <iostream>

int cget::command::Install::invoke(const std::vector<std::string> &args) {
    InputParser::ShortFlags f { { "s", "save" } };
    InputParser p(f);
    InputParser::Result r;
    p.parseFlags(args, &r);

    bool saveToPkgFile = r.binaryFlags.find("save") != r.binaryFlags.end();

    if (saveToPkgFile) {
        std::cout << "Should be saved" << std::endl;
    } else {
        std::cout << "Should NOT be saved" << std::endl;
    }

    return 0;
}

cget::command::Install::Install(const std::string &_name) : Command(_name) {}
