#pragma once
#include <string>
#include <vector>

namespace cget {
    class InputParser {
    public:
        struct Result {
            std::string command;
        };

        using Args = std::vector<std::string>;
        void parse(const Args& args, Result* result) const;
    };
}