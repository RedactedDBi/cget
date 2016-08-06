#include <dependency_resolution/resolve.h>
#include <list>

using std::string;
using std::vector;

cget::dependency_resolution::DependencyStore::DependencyStore(PackageFile* pkg, PackageFolder* pkgFolder)
        : _pkg(pkg), _pkgFolder(pkgFolder) {}

int cget::dependency_resolution::DependencyStore::resolveAll(vector<string> passedDeps, bool saveToPackageFile) {
    std::list<DependencySocket*> sockets;

    for (auto dep : passedDeps) {
        auto sock = new DependencySocket(dep, _pkgFolder);
        sockets.push_back(sock);
    }

    auto i = sockets.begin();
    while (i != sockets.end())
    {
        if ((*i)->done())
            sockets.erase(i++);
        else
        {
            (*i)->update();
            ++i;
        }
    }

    return 0;
}
