#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace cget {
    class InputParser {
    public: // Structs and typedefs/using statements
        struct Result {
            std::string command;
            std::unordered_set<std::string> binaryFlags;
            std::vector<std::string> args;
        };

        // Convenience typedefs
        using Args = std::vector<std::string>;
        using ShortFlags = std::unordered_map<std::string, std::string>;

    private:
        ShortFlags _shortFlags;

    public: // methods
        // Delete the default non-RAII stuff
        InputParser(const InputParser&) = delete;
        InputParser(InputParser&&) = delete;
        InputParser* operator=(const InputParser&) = delete;

        // shortFlags: A mapping of shorter versions for each flag to parse
        //             For instance, mapping "s" -> "save" will parse "-s"
        //             equivalent to "--save"
        explicit InputParser(const ShortFlags& shortFlags);

        // Parses sub-command, flags and arguments from an array
        void parse(const Args& args, Result* result) const;
    };
}