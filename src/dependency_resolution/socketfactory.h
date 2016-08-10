#pragma once
#include <memory>

namespace cget {
    namespace dependency_resolution {
        class Resolver;

        class SocketFactory {
        public:
            virtual std::unique_ptr<Resolver> create(const std::string& dependency) = 0;
        };
    }
}