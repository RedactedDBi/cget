#pragma once
#include <vector>
#include <string>
#include <memory>

#include "packagefile.h"
#include "packagefolder.h"

namespace cget {
    namespace registry_api {
        class Registry;
    }

    namespace dependency_resolution {
        class ResolverFactory;

        class DependencyStorage {
        private:
            PackageFile   _pkg;
            PackageFolder _pkgFolder;
            ResolverFactory* _factory;

        public:
            DependencyStorage(ResolverFactory* factory);
            DependencyStorage(const DependencyStorage&) = delete;
            DependencyStorage(DependencyStorage&&) = delete;
            DependencyStorage* operator=(const DependencyStorage&) = delete;
            int resolveAll(std::vector<std::string> passedDeps, bool saveToPackageFile);
        };
    }
}