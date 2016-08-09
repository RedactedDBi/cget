#pragma once
#include <dependency_resolution/resolver.h>

namespace cget {
    namespace arch {
        class BsdSocketResolver : public dependency_resolution::Resolver {
        public:
            virtual void resolveChunk() override;

            virtual bool done() override;
        };
    }
}