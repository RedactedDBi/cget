#pragma once
#include <dependency_resolution/resolver.h>

namespace cget {
    namespace arch {
        // This is the Berkeley / BSD socket implementation of the dependency
        // resolver. Currently we're only support Linux/Unix, which is where
        // this resolver makes sense to use.
        class BsdSocketResolver : public dependency_resolution::Resolver {
        private:
            bool _done{false};

        public:
            virtual void resolveChunk() override;
            virtual bool done() override;
        };
    }
}