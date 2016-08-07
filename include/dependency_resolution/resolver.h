#pragma once

namespace cget {
    namespace dependency_resolution {
        class Resolver {
        public:
            virtual void resolveChunk() = 0;
            virtual bool done() = 0;
        };
    }
}