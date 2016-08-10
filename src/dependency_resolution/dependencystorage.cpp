#include <dependency_resolution/dr.h>
#include <list>

using std::string;
using std::vector;

cget::dependency_resolution::DependencyStorage::DependencyStorage(
        cget::dependency_resolution::SocketFactory* factory)
        : _factory(factory) {}

int cget::dependency_resolution::DependencyStorage::resolveAll(vector<string> passedDeps, bool saveToPackageFile) {
    std::list<std::unique_ptr<Resolver>> resolvers;

    for (auto dep : passedDeps) {
        auto resolver = _factory->create(dep);
        resolvers.push_back(std::move(resolver));
    }

    auto i = resolvers.begin();
    while (i != resolvers.end())
    {
        if ((*i)->done()) {
            resolvers.erase(i++);
        }
        else
        {
            (*i)->resolveChunk();
            ++i;
        }
    }

    return 0;
}

