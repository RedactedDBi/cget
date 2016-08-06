#pragma once
#include <vector>
#include <string>
#include "dependencyprogress.h"

namespace cget {
    namespace dependency_resolution {
        class PackageFile;

        class DependencyStore {
        private:
            PackageFile* _pkg;

        public:
            explicit DependencyStore(PackageFile *pkg);
            DependencyStore(const DependencyStore&) = delete;
            DependencyStore(DependencyStore&&) = delete;
            DependencyStore* operator=(const DependencyStore&) = delete;
            int resolveAll(std::vector<std::string> passedDeps, bool saveToPackageFile);
        };
    }
}