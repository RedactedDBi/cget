#pragma once

#include "socketfactory.h"

namespace cget {
    namespace dependency_resolution {
        class Resolver {
        private:
            SocketFactory* _factory;
            std::string _dep;

        public:
            Resolver(const std::string& dependency, SocketFactory *factory);

            void resolveChunk();
            bool done();
        };
    }
}