#pragma once
#include "resolverfactory.h"

namespace cget {
    namespace dependency_resolution {
        class DefaultResolverFactory : public ResolverFactory {
        public:
            virtual std::unique_ptr<Resolver> create(const std::string &dependency) override;
        };
    }
}