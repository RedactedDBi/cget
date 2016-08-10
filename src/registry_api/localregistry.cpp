#include "localregistry.h"

cget::registry_api::PackageEntry
cget::registry_api::LocalRegistry::readEntry(const std::string &string) {
    // Just some temporary fake package data
    PackageEntry entry;
    entry.description = "Sample Description";
    entry.name = "Sample name";
    entry.repository = "https://github.com/Lavesson/t-unit";
    return entry;
}
