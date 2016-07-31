#include <inputparser.h>
#include <regex>
#include <iostream>

using std::regex;
using std::regex_match;

cget::InputParser::InputParser(const ShortFlags& shortFlags)
        : _shortFlags(shortFlags) {}

void cget::InputParser::parse(const Args& args, Result* result) const {
    // Assume that the first argument is the sub command
    result->command = args[0];
    regex fullFlagRegex("^\\-\\-([\\w]+)$");
    regex shortFlagRegex("^\\-(\\w)$");

    // iterate through the rest of the items and parse them as either
    // flags or arguments
    for (int i = 1; i < args.size(); ++i) {
        std::smatch matches;

        if (std::regex_match(args[i], matches, fullFlagRegex)) {
            result->binaryFlags.insert(matches[1].str());
        }
        else if (std::regex_match(args[i], matches, shortFlagRegex)) {
            auto match = matches[1].str();
            result->binaryFlags.insert(_shortFlags.at(match));
        }
    }
}