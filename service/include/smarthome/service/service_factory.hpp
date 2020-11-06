
#include <memory>

namespace smarthome {

    /**
     * Service class used for injection of concrete objects.
     *
     * This provides for mockability of dependencies.
     */
    class ServiceFactory {
        public:

            /**
             * Get an instance of the specified service.
             *
             * @tparam AbstractBase Abstract base class for which an instance should be returned.
             * @return Shared pointer to the abstract base.
             */
            template <typename AbstractBase>
            const std::shared_ptr<AbstractBase> Get();

            /**
             * Register a type with the service factory.
             *
             * @tparam AbstractBase Abstract base class for which a concrete implementation is registered.
             * @tparam ConcreteImpl Concrete implementation to be injected.
             */
            template <typename AbstractBase, typename ConcreteImpl>
            void Register();
    };

} // namespace smarthome