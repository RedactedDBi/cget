#pragma once

#include <string>

namespace cget {
    namespace registry_api {
        struct PackageEntry {
            std::string name;
            std::string description;
            std::string repository;
        };

        class Registry {
            virtual PackageEntry readEntry(const std::string&) = 0;
        };
    }
}