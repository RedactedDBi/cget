#pragma once
#include <string>

namespace cget {
    namespace dependency_resolution {
        class PackageFolder;

        class DependencySocket {
        private:
            std::string _name;
            PackageFolder* _pkgFolder;

        public:
            DependencySocket(const std::string& name, PackageFolder* pkgFolder);

            bool done();
            void update();
        };
    }
}