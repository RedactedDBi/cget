#include <command/init.h>
#include <iostream>
#include <json.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using json = nlohmann::json;

namespace {
    const int JSON_SPACING = 4;

    struct Package {
        std::string name;
        std::string version;
        std::string description;
        std::string author;
    };

    std::string constructJSON(const Package& p) {
        json j = {
            { "name", p.name },
            { "version", p.version },
            { "description", p.description },
            { "author", p.author },
        };

        return j.dump(JSON_SPACING);
    }
}

cget::Init::Init(const std::string &_name)
        : Command(_name) {}

int cget::Init::invoke(const std::vector<std::string> &args) {
    Package p;

    cout << "This utility will walk you through creating a package.json file." << endl;
    cout << "You'll be asked to setup the most common items" << endl;
    cout << endl;
    cout << "Use `cget install --save <dependency>` afterwards to install a dependency" << endl;
    cout << "and save it to your package.json file." << endl;
    cout << endl;
    cout << "Press ^C at any time to quit." << endl;
    cout << endl;
    cout << "name: () ";
    cin >> p.name;
    cout << "version: (1.0.0) ";
    cin >> p.version;
    cout << "description: ";
    cin >> p.description;
    cout << "author: ";
    cin >> p.author;

    cout << "About to write the following to package.json:" << endl;
    cout << endl;
    cout << constructJSON(p) << endl;
    cout << endl;
    cout << "Is this ok? (yes) ";
    string answer;
    cin >> answer;

    return 0;
}
