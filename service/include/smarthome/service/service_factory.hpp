#include <any>
#include <memory>
#include <unordered_map>
#include <typeinfo>

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
            const std::shared_ptr<AbstractBase> Get() {

                const auto key = typeid(AbstractBase).hash_code();
                const auto generalizedConstructor = _constructors.at(key);
                const auto constructor = std::any_cast< std::function<std::shared_ptr<AbstractBase>()> >(generalizedConstructor);
                return constructor();
            }

            /**
             * Register a type with the service factory.
             *
             * @tparam ConcreteImpl Concrete implementation to be injected.
             * @tparam AbstractBase Abstract base class for which a concrete implementation is registered.
             */
            template <typename ConcreteImpl, typename AbstractBase>
            void Inject() {

                const auto key = typeid(AbstractBase).hash_code();
                std::function< std::shared_ptr<AbstractBase>() > constructor = [] {

                    return std::shared_ptr<AbstractBase> (
                        new ConcreteImpl()
                    );
                };
                _constructors.insert({ key, constructor });
            }

        private:

            /**
             * A data structure used to store functions that construct concrete instances.
             *
             * The use of std::any here allows abstraction of function signature differences so that objects of different types can be created.
             */
            std::unordered_map<size_t, std::any> _constructors { };
    };

} // namespace smarthome