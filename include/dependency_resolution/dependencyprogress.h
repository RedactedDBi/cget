#pragma once

#include <string>

namespace cget {
    namespace dependency_resolution {
        struct ResolvedDependency {
            ResolvedDependency* parent{nullptr};
        };

        struct DependencyProgress {
            ResolvedDependency* parent{nullptr};
            std::string name;
            int percentage{0};
        };
    }
}