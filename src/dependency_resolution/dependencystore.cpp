#include <dependency_resolution/resolve.h>

using std::string;
using std::vector;

cget::dependency_resolution::DependencyStore::DependencyStore(PackageFile *pkg)
        : _pkg(pkg) {}

int cget::dependency_resolution::DependencyStore::resolveAll(
        vector<string> passedDeps, bool saveToPackageFile, ProgressReport report) {
    return 0;
}
