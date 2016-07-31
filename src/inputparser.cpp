#include <inputparser.h>
#include <regex>
#include <iostream>

using std::regex;
using std::regex_match;

namespace {
    const std::string FULL_FLAG = "^\\-\\-([\\w]+)$";
    const std::string SHORT_FLAG = "^\\-(\\w)$";
    const regex FULL_FLAG_REGEX(FULL_FLAG);
    const regex SHORT_FLAG_REGEX(SHORT_FLAG);
    const regex ANY_FLAG_REGEX(FULL_FLAG + "|" + SHORT_FLAG);

    void assertSubCommand(const cget::InputParser::Args &args) {
        auto& maybeCommand = args[0];
        if (args.size() == 0 || std::regex_match(maybeCommand, ANY_FLAG_REGEX))
            throw std::invalid_argument("Expected sub-command at first position");
    }
}

cget::InputParser::InputParser(const ShortFlags& shortFlags)
        : _shortFlags(shortFlags) {}

void cget::InputParser::parse(const Args& args, Result* result) const {
    assertSubCommand(args);
    result->command = args[0];

    // iterate through the rest of the items and parse them as either
    // flags or arguments
    for (int i = 1; i < args.size(); ++i) {
        std::smatch matches;

        if (std::regex_match(args[i], matches, FULL_FLAG_REGEX)) {
            result->binaryFlags.insert(matches[1].str());
        }
        else if (std::regex_match(args[i], matches, SHORT_FLAG_REGEX)) {
            auto match = matches[1].str();
            result->binaryFlags.insert(_shortFlags.at(match));
        }
        else {
            // Should be safe to assume this is an argument here
            result->args.push_back(args[i]);
        }
    }
}