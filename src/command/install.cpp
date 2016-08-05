#include <command/install.h>
#include <inputparser.h>
#include <iostream>

using cget::dependency_resolution::DependencyProgress;

int cget::command::Install::invoke(const std::vector<std::string> &args) {
    InputParser::ShortFlags f { { "s", "save" } };
    InputParser p(f);
    InputParser::Result r;
    p.parseFlags(args, &r);

    bool saveToPkgFile = r.binaryFlags.find("save") != r.binaryFlags.end();

    return _store.resolveAll(r.args, saveToPkgFile, [this](const DependencyProgress& d){

    });
}

cget::command::Install::Install(const std::string &_name)
        : Command(_name), _store(&_pkg) {}
