#pragma once

#include <any>
#include <iostream>
#include <memory>
#include <string>
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

                const auto key = std::string( typeid(AbstractBase).name() );

                std::cout << "Abstract base class: " << key << std::endl;

                // Ensure a concrete implementation is registered for the base
                assert( _constructors.find(key) != _constructors.end() );

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

                const auto key = std::string( typeid(AbstractBase).name() );

                std::cout << "Abstract base class: " << key << std::endl;

                std::function< std::shared_ptr<AbstractBase>() > constructor = [] {

                    return std::shared_ptr<AbstractBase> (
                        new ConcreteImpl()
                    );
                };
                _constructors.insert({ key, constructor });
            }

            /**
             * Get the singleton instance.
             *
             * @return Singleton instance of the service factory.
             */
            static ServiceFactory& Instance() {

                if (_instance == nullptr) {

                    _instance = std::shared_ptr<ServiceFactory>(
                        new ServiceFactory()
                    );
                }
                return *_instance;
            }

        private:
            ServiceFactory() { }

            /**
             * A data structure used to store functions that construct concrete instances.
             *
             * The use of std::any here allows abstraction of function signature differences so that objects of different types can be created.
             */
            std::unordered_map<std::string, std::any> _constructors { };

            /**
             * Singleton instance of the factory.
             */
            static inline std::shared_ptr<ServiceFactory> _instance = nullptr;
    };

} // namespace smarthome