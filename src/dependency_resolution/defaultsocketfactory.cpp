#include <memory>
#include "socketfactory.h"
#include "dr.h"

using namespace cget::dependency_resolution;
using std::string;
using std::unique_ptr;

unique_ptr<Resolver> DefaultSocketFactory::create(const string &dependency) {
    return nullptr;
}
