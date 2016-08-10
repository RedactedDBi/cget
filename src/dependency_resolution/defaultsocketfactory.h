#pragma once
#include "socketfactory.h"

namespace cget {
    namespace dependency_resolution {
        class DefaultSocketFactory : public SocketFactory {
        public:
            virtual std::unique_ptr<Resolver> create(const std::string &dependency) override;
        };
    }
}