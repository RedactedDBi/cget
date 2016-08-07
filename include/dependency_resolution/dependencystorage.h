#pragma once
#include <vector>
#include <string>
#include <memory>

#include "packagefile.h"
#include "packagefolder.h"

namespace cget {
    namespace dependency_resolution {
        class ResolverFactory;

        class DependencyStorage {
        private:
            PackageFile   _pkg;
            PackageFolder _pkgFolder;
            std::unique_ptr<ResolverFactory> _factory;

        public:
            DependencyStorage();
            DependencyStorage(const DependencyStorage&) = delete;
            DependencyStorage(DependencyStorage&&) = delete;
            DependencyStorage* operator=(const DependencyStorage&) = delete;
            int resolveAll(std::vector<std::string> passedDeps, bool saveToPackageFile);
        };
    }
}