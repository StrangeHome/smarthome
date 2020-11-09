# smarthome
A smart home implementation designed with privacy, security, simplicity and production-grade stability in mind.

## Dependencies
1. Clang (C++17)
1. CMake 3.14
1. Googletest

## Goals
Looking into the future it seems like there will be demand for a privacy-centric smarthome implementation
giving users the ability to adapt the system to their taste. Just as linux provides users that flexibility
in the realm of the operating system I believe that similar desires will surface in the smarthome domain.
This project aims to provide that system along with the production-readiness that comes with a stable
proprietary implementation. I've seen systems that are heavily DIY-centric but this project aims to provide
simplicity so that users don't have to be experts to set the system up.

## Design Decisions
This section outlines some general design decisions and justifications.

### Separation of Component Projects
Each software component is separated into its own subproject for a couple of reasons. The main justification
for doing so is scalability across teams. In order to allow modification of each component without producing
merge conflicts or breaking dependent code each component codebase needs to be largely independent of the
others.

Achievement of this goal is accomplished by injection of concrete objects using the service factory. Each
component defines an abstract base class on which others can depend but the injection of a concrete implementation
in place of that abstract base class is determined within the component itself. For example, the logger
component defines the abstract base class ```cpp Logger``` on which the device CLI can depend. However,
the logger subproject includes the file apply_production_logger.hpp which actually performs the injection
of ```cpp ColoredLogger``` in place of the abstract base. This means that developers making modifications
to the logger subproject don't have to worry about changes to the ```cpp ColoredLogger``` breaking code
within the device CLI provided. Of course, removal of functions in the abstract base class can cause
breaks but the frailty of the codebase is significantly reduced.

Additionally, each subproject contains all of the files associated directly with that subproject. That includes
declaration of external dependencies, tests, CLIs, etc. This is done so that each component is largely self-contained.
External tests, for example, won't break due to a change in the Logger because all of the tests relating to direct
logger use are contained within the logger subproject. Therefore, developers working on the logger can make modifications
to the logger codebase, update necessary tests, etc without causing breaks that impact others developers.

These issues may seem menial but they actually result in a significant amount of time spent coordinating resolution
of breaks. Communication is a costly process in large projects.

### Dependency Injection and Inversion of Control
Use of Googletest, specifically Googlemock, is made significantly easier by use of abstract base classes.
It allows for easy declaration of mock objects which are required to ensure a fully mocked system and
to allow for increased test coverage. The service subproject was created to allow for easy injection
of mock objects in place of abstract base classes. Instead of depending directly on the ```cpp ColoredLogger```, for
example, an external component (i.e, the device CLI) depends on the abstract base ```cpp Logger```. Later on,
a file called apply_mock_logger.hpp will be introduced that applies mock objects. Inversion of control
will come when class objects use the service factory to gather all dependencies. So, for example, a class
defined as follows...
```cpp

// ... includes

class Foo {
    public:
        Foo(ServiceFactory serviceFactory = ServiceFactory()) :
            _logger( serviceFactory->Get<Logger>() ),
            _serviceFactory( serviceFactory ) { }

    // ... rest of the class

};

```
will have its _logger object populated with either the ColoredLogger or the MockLogger depending on
which objects are configured for injection. This allows the entire system to predictably pull in
exclusively mock objects or exclusively production objects which, in tern, allows all testing
objects to be excluded from the production code.
