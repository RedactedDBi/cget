#pragma once
#include <command/command.h>
#include <dependency_resolution/resolve.h>

namespace cget {
    namespace command {
        class Install : public Command {
        private:
            dependency_resolution::PackageFile     _pkg;
            dependency_resolution::PackageFolder   _pkgFolder;
            dependency_resolution::DependencyStore _store;

        public:
            Install(const std::string &_name);
            int invoke(const std::vector<std::string>& args) override;
        };
    }
}