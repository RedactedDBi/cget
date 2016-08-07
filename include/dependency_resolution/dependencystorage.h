#pragma once
#include <vector>
#include <string>
#include "packagefile.h"
#include "packagefolder.h"

namespace cget {
    namespace dependency_resolution {
        class DependencyStorage {
        private:
            PackageFile   _pkg;
            PackageFolder _pkgFolder;

        public:
            DependencyStorage();
            DependencyStorage(const DependencyStorage&) = delete;
            DependencyStorage(DependencyStorage&&) = delete;
            DependencyStorage* operator=(const DependencyStorage&) = delete;
            int resolveAll(std::vector<std::string> passedDeps, bool saveToPackageFile);
        };
    }
}