#pragma once
#include <vector>
#include <string>
#include "resolve.h"

namespace cget {
    namespace dependency_resolution {
        class PackageFile;
        class PackageFolder;

        class DependencyStore {
        private:
            PackageFile*   _pkg;
            PackageFolder* _pkgFolder;

        public:
            DependencyStore(PackageFile *pkg, PackageFolder *pkgFolder);
            DependencyStore(const DependencyStore&) = delete;
            DependencyStore(DependencyStore&&) = delete;
            DependencyStore* operator=(const DependencyStore&) = delete;
            int resolveAll(std::vector<std::string> passedDeps, bool saveToPackageFile);
        };
    }
}