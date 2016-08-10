#include "init.h"
#include <iostream>
#include <json.hpp>
#include <regex>
#include <fstream>
#include "../constants.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::function;
using json = nlohmann::json;
using namespace cget::constants;

namespace {
    const int JSON_SPACING = 4;
    const std::regex VERSION_REGEX("^(\\d+\\.\\d+\\.\\d+)$");
}

cget::command::Init::Init(const std::string &_name)
        : Command(_name) {}

int cget::command::Init::invoke(const std::vector<std::string> &args) {
    cout << "This utility will walk you through creating a " << PACKAGE_FILE << " file." << endl;
    cout << "You'll be asked to setup the most common items" << endl;
    cout << endl;
    cout << "Use `cget install --save <dependency>` afterwards to install a dependency" << endl;
    cout << "and save it to your " << PACKAGE_FILE << " file." << endl;
    cout << endl;
    cout << "Press ^C at any time to quit." << endl;
    cout << endl;

    Model model;

    eval("name:", [&model](const string& input){
        model.setName(input);
    });

    eval("version:", [&model](const string& input){
        model.setSemanticVersion(input);
    }, DEFAULT_VERSION);

    eval("description:", [&model](const string& input){
        model.setDescription(input);
    });

    eval("author:", [&model](const string& input){
        model.setAuthor(input);
    });

    cout << "About to write the following to '" << PACKAGE_FILE << "':" << endl;
    cout << model.getJSONRepresentation() << endl;

    eval("OK?", [&model](const string& input){
        string lower = input;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower == "y" || lower == "yes") {
            model.writePackageFile();
        }
    }, "Yes");

    return 0;
}

void cget::command::Init::eval(
        const string& prompt, function<void(const std::string&)> f, const string& defaultValue) {
    while (true) {
        try {
            cout << prompt << " ";
            if (!defaultValue.empty())
                cout << "(" << defaultValue << ") ";
            std::string value;
            getline(cin, value);
            f(value.empty() ? defaultValue : value);
            break;
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
}

void cget::command::Init::Model::setName(const string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }

    _package.name = name;
}

void cget::command::Init::Model::setSemanticVersion(const string& version) {
    if (!std::regex_match(version, VERSION_REGEX)) {
        throw std::invalid_argument("Invalid version");
    }

    _package.version = version;
}

void cget::command::Init::Model::setDescription(const std::string& desc) {
    _package.description = desc;
}

void cget::command::Init::Model::setAuthor(const std::string& author) {
    _package.author = author;
}

string cget::command::Init::Model::getJSONRepresentation() {
    json j = {
            { "name", _package.name },
            { "version", _package.version },
            { "description", _package.description },
            { "author", _package.author },
    };

    return j.dump(JSON_SPACING);
}

void cget::command::Init::Model::writePackageFile() {
    ofstream out(PACKAGE_FILE);
    out << getJSONRepresentation() << endl;
    out.close();
}

