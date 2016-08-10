#include "defaultsocketfactory.h"
#include <network/socket.h>
#include "dr.h"

// Concrete types
#include <arch/unix/bsdsocket.h>

using namespace cget::dependency_resolution;
using std::string;
using std::unique_ptr;
using cget::network::Socket;
using cget::arch::unix::BsdSocket;

unique_ptr<Socket> DefaultSocketFactory::create(const std::string& dependency) {
    // Currently, we're only supporting BSD sockets
    return std::unique_ptr<Socket>(new BsdSocket());
}
