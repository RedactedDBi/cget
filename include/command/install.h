#pragma once
#include <command/command.h>
#include <dependency_resolution/dr.h>
#include <registry_api/localregistry.h>

namespace cget {
    namespace command {
        class Install : public Command {
        private:
            // We'll start by hooking up a local registry with static resources
            registry_api::LocalRegistry            _registry;

            // Dependency resolution stuff:
            dependency_resolution::PackageFile     _pkg;
            dependency_resolution::PackageFolder   _pkgFolder;
            dependency_resolution::DefaultResolverFactory _factory;
            dependency_resolution::DependencyStorage _store;

        public:
            Install(const std::string &_name);
            int invoke(const std::vector<std::string>& args) override;
        };
    }
}