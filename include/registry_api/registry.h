#pragma once

#include <string>

namespace cget {
    namespace registry_api {
        struct PackageEntry {
            std::string name;
            std::string description;
            std::string repository;

            struct Downloads {
                int total{0};
                int monthly{0};
                int daily{0};
            };
        };

        class Registry {
            virtual PackageEntry readEntry(const std::string&) = 0;
        };
    }
}