#include <iostream>
#include "resolver.h"

cget::dependency_resolution::Resolver::Resolver(
        const std::string &dependency, cget::dependency_resolution::SocketFactory *factory)
        : _factory(factory), _dep(dependency) {}

void cget::dependency_resolution::Resolver::resolveChunk() {
    std::cout << "Resolving chunk for " << _dep << std::endl;
}

bool cget::dependency_resolution::Resolver::done() {
    return false;
}
