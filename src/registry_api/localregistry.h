#pragma once

#include "registry.h"

namespace cget {
    namespace registry_api {
        class LocalRegistry : public Registry {
            PackageEntry readEntry(const std::string &string) override;
        };
    }
}