#include <gmock/gmock.h>

#include <smarthome/service/service_factory.hpp>

using namespace smarthome;

class AbstractBase {
    public:
        virtual void SomeFunction() = 0;
};

class ConcreteImpl : public AbstractBase {
    public:
        void SomeFunction() { }
};

TEST(ServiceFactory, ShouldAllowUserToRegisterConcreteImplementations) {

    ServiceFactory serviceFactory { };
    try {
        serviceFactory.Inject<ConcreteImpl, AbstractBase>();
    } catch (...) {
        FAIL();
    }
}

TEST(ServiceFactory, ShouldAllowUserToFetchAConcreteImplementationUsingTheAbstractBaseClass) {

    ServiceFactory serviceFactory { };
    try {
        auto concreteImplementation = serviceFactory.Get<AbstractBase>();
    } catch(...) {
        FAIL();
    }
}