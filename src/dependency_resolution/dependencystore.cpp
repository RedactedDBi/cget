#include <dependency_resolution/resolve.h>

using std::string;
using std::vector;

cget::dependency_resolution::DependencyStore::DependencyStore(PackageFile *_pkg)
        : _pkg(_pkg) {}

int cget::dependency_resolution::DependencyStore::resolveAll(
        vector<string> passedDeps, bool saveToPackageFile, ProgressReport report) {

    return 0;
}
