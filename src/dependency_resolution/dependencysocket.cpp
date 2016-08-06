#include <string>
#include <dependency_resolution/resolve.h>

cget::dependency_resolution::DependencySocket::DependencySocket(
        const std::string& name, PackageFolder *_pkgFolder)
        : _name(_name), _pkgFolder(_pkgFolder) {}

bool cget::dependency_resolution::DependencySocket::done() {
    return true;
}

void cget::dependency_resolution::DependencySocket::update() {
    // ...
}
