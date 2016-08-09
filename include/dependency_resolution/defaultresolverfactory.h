#pragma once
#include "resolverfactory.h"

namespace cget {
    namespace registry_api {
        class Registry;
    }

    namespace dependency_resolution {
        class DefaultResolverFactory : public ResolverFactory {
        private:
            registry_api::Registry* _registry;

        public:
            DefaultResolverFactory(registry_api::Registry *_registry);
            virtual std::unique_ptr<Resolver> create(const std::string &dependency) override;
        };
    }
}