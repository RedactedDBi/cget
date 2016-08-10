#include "resolver.h"

void cget::dependency_resolution::Resolver::resolveChunk() {

}

bool cget::dependency_resolution::Resolver::done() {
    return false;
}

cget::dependency_resolution::Resolver::Resolver(cget::dependency_resolution::SocketFactory *factory)
        : _factory(factory) {}
