#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace cget {
    class InputParser {
    public: // Structs and typedefs/using statements
        struct Result {
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

        // shortFlags: A mapping of shorter versions for each flag to parseFlags
        //             For instance, mapping "s" -> "save" will parseFlags "-s"
        //             equivalent to "--save"
        explicit InputParser(const ShortFlags& shortFlags);

        // Given input from command line, parse the sub command to use, and store
        // all further arguments in 'output'
        static std::string parseSubCommand(const Args& args, Args* output);

        // Parse flags and arguments from an array
        void parseFlags(const Args& args, Result* result) const;
    };
}