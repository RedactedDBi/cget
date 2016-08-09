#include <arch/bsdsocketresolver.h>
#include <iostream>

void cget::arch::BsdSocketResolver::resolveChunk() {
    std::cout << "Resolving chunk..." << std::endl;
}

bool cget::arch::BsdSocketResolver::done() {
    return false;
}
