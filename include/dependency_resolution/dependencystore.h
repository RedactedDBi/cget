#pragma once
#include <vector>
#include <string>
#include <functional>
#include "dependencyprogress.h"

namespace cget {
    namespace dependency_resolution {
        class PackageFile;

        class DependencyStore {
        private:
            PackageFile* _pkg;

        public:
            explicit DependencyStore(PackageFile *_pkg);
            DependencyStore(const DependencyStore&) = delete;
            DependencyStore(DependencyStore&&) = delete;
            DependencyStore* operator=(const DependencyStore&) = delete;

            using ProgressReport = std::function<void(const cget::dependency_resolution::DependencyProgress&)>;
            int resolveAll(
                    std::vector<std::string> passedDeps,
                    bool saveToPackageFile,
                    ProgressReport report);
        };
    }
}