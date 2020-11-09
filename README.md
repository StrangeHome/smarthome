# smarthome
A smart home implementation designed with privacy, security, simplicity and production-grade stability in mind.

## Dependencies
1. [Clang (C++17)](https://clang.llvm.org/)
1. [CMake 3.14](https://cmake.org/)
1. [Googletest](https://github.com/google/googletest)
1. [Doxygen 1.8.17](https://github.com/doxygen/doxygen)
1. [Qt 5.12.8](https://doc.qt.io/qt-5/gettingstarted.html)
1. [Python 3.8.5](https://www.python.org/downloads/)

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
component defines the abstract base class ```Logger``` on which the device CLI can depend. However,
the logger subproject includes the file apply_production_logger.hpp which actually performs the injection
of ```ColoredLogger``` in place of the abstract base. This means that developers making modifications
to the logger subproject don't have to worry about changes to the ```ColoredLogger``` breaking code
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
of mock objects in place of abstract base classes. Instead of depending directly on the ```ColoredLogger```, for
example, an external component (i.e, the device CLI) depends on the abstract base ```Logger```. Later on,
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

### Test-driven Development
The goal of following Test-driven Development (TDD) is to change the thought process when developing code
from one of developing software that just works to one of developing software that's algorithmically
complete. Employment of TDD forces developers to think of problems and components in terms of algorithmic
completeness. For example, what edge cases, error cases, exceptional circumstances, etc can arise from
use of a given component. If tests are written that ensure those cases are understood then the codebase
becomes significantly more stable. Furthermore, a metric exists that one can use to determine the health
of the overall system.

### Auto-generation of Documentation from JDoc
Doxygen allows one to generate documentation in both PDF and HTML form directly from the source code.
A notorious issue that surfaces in codebases comes from documentation becoming out of date when
changes in the code are introduced. By following the JDoc standard, those inconsistencies can be
better controlled by way of keeping standards-compliant comments within the codebase. Providing such
comments makes a lot of sense because it aids developers in understanding what each function or member
does. Therefore, it's a valuable addition to any program and a significant amount of work is saved
by automating documentation creation.

### Build Standards
When developing C++ applications a unique issue surfaces that higher-level languages don't experience;
namely, operating system differences cause compatibility issues. This is similar to that experienced
during web development when trying to create cross-browser-compatible applications. The way in which
this is controlled is by building the codebase of the primary operating systems requiring compatibility.
Being in the Internet of Things (IoT) space, I've focused primarily on CentOS and Ubuntu to cover the
two primary linux flavors. With the goal of cross-platform compatibility, each modification to the
codebase needs to be tested on, at least, CentOS and Ubuntu. Windows machines will be added to the mix
later on. This is the recommended practice for CMake as well.

### Minimization of Codebase Diversity
It's my intention to minimize introduction of different languages to the codebase. Each addition comes
with careful consideration. This is done because each new language introduced limits the potential
developers that can contribute to those who know all of the languages.

### Google C++ Style-guide Compliance
In general, following companies that have large codebases and ample experience maintaining systems
written in a particular language is a good idea. This ensures that new developers will be more
familiar with the system even if they haven't seen your specific codebase. It also provides the benefit
of learning from the large amount of experience those companies have. Therefore, I've decided to follow
Google's recommended practices with respect to C++. Currently, the recommendation is to use C++17.
