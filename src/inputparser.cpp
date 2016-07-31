#include <inputparser.h>

void cget::InputParser::parse(const Args& args, Result* result) const {
    // Assume that the first argument is the sub command
    result->command = args[0];
}