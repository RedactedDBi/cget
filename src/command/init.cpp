#include <command/init.h>
#include <iostream>
#include <json.hpp>
#include <regex>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using json = nlohmann::json;

namespace {
    const int JSON_SPACING = 4;
    const std::string DEFAULT_VERSION = "1.0.0";
    const std::string JSON_FILE = "cget.json";
    const std::regex VERSION_REGEX("^(\\d+\\.\\d+\\.\\d+)$");

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

    // Parse the package name from stdin
    void parseName(Package* p) {
        do {
            cout << "name: ";
            getline(cin, p->name);
        } while (p->name.length() == 0);
    }

    // Parse the version number from stdin. Needs to pass a regex
    // check against a semver-format to be accepted.
    void parseVersion(Package* p) {
        do {
            std::string version;
            cout << "version: (" << DEFAULT_VERSION << ") ";
            std::getline(cin, version);

            if (version.length() == 0)
                version = DEFAULT_VERSION;

            if (regex_match(version, VERSION_REGEX)) {
                p->version = version;
            }
            else {
                cout << "Invalid version" << endl;
            }

        } while(p->version.length() == 0);
    }

    // Parse all parameters for the package file
    void parsePackageParams(Package* p) {
        // Name and version are a bit involved, so extracted in order to de-clutter:
        parseName(p);
        parseVersion(p);

        // Description and author are simple, so let's just grab those:
        cout << "description: ";
        std::getline(cin, p->description);
        cout << "author: ";
        std::getline(cin, p->author);
    }

    // Check whether input was yes or no
    bool affirmative(const std::string& answer) {
        // Transform the string to lower case
        std::string lower = answer;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        return lower.length() == 0 ||
               lower == "y" || lower == "yes";
    }

    void writePackageFile(const std::string& json) {
        ofstream packageFile;
        packageFile.open (JSON_FILE);
        packageFile << json << endl;
        packageFile.close();
    }
}

cget::Init::Init(const std::string &_name)
        : Command(_name) {}

int cget::Init::invoke(const std::vector<std::string> &args) {
    cout << "This utility will walk you through creating a " << JSON_FILE << " file." << endl;
    cout << "You'll be asked to setup the most common items" << endl;
    cout << endl;
    cout << "Use `cget install --save <dependency>` afterwards to install a dependency" << endl;
    cout << "and save it to your " << JSON_FILE << " file." << endl;
    cout << endl;
    cout << "Press ^C at any time to quit." << endl;
    cout << endl;

    Package p;
    parsePackageParams(&p);

    cout << "About to write the following to " << JSON_FILE << ":" << endl;
    cout << endl;
    string packageJson = constructJSON(p);
    cout << packageJson << endl;
    cout << endl;
    cout << "Is this ok? (yes) ";

    string answer;
    std::getline(cin, answer);

    if (affirmative(answer)) {
        cout << "Writing " << JSON_FILE << endl;
        writePackageFile(packageJson);
    }

    return 0;
}
