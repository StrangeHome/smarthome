
#include <smarthome/service/service_factory.hpp>

namespace smarthome {

    template <typename AbstractBase>
    const std::shared_ptr<AbstractBase> ServiceFactory::Get() {
        // TODO:
    }

    template <typename AbstractBase, typename ConcreteImpl>
    void ServiceFactory::Register() {
        // TODO
    }

} // namespace smarthome