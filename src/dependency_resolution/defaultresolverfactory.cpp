#include <memory>
#include <dependency_resolution/resolverfactory.h>
#include <dependency_resolution/resolve.h>
#include <arch/bsdsocketresolver.h>

using namespace cget::dependency_resolution;
using std::string;
using std::unique_ptr;

unique_ptr<Resolver> DefaultResolverFactory::create(const string &dependency) {
    return unique_ptr<Resolver>(new arch::BsdSocketResolver);
}
