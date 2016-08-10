#pragma once

#include "socketfactory.h"

namespace cget {
    namespace dependency_resolution {
        class Resolver {
        private:
            SocketFactory* _factory;

        public:
            Resolver(SocketFactory *factory);

            void resolveChunk();
            bool done();
        };
    }
}