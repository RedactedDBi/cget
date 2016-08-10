#pragma once
#include <memory>
#include <string>

namespace cget {
    namespace network {
        class Socket;
    }

    namespace dependency_resolution {
        class SocketFactory {
        public:
            virtual std::unique_ptr<network::Socket> create(const std::string& dependency) = 0;
        };
    }
}