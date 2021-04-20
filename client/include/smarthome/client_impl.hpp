#pragma once

#include <smarthome/logger.hpp>
#include <smarthome/client.hpp>

#include <cppject/service_factory.hpp>

using namespace cppject;

namespace smarthome {

    class ClientImpl : public Client {
        public:
            ClientImpl(ServiceFactory::shared_ptr serviceFactory = ServiceFactory::Instance()) :
                _logger(serviceFactory->Get<Logger>()),
                _serviceFactory(serviceFactory) { }

            void ConfigureDevices() const override {

                _logger.info("Devices configured.");
            }

            void DiscoverDevices() const override {

                _logger.info("Devices found.");
            }

        private:

            const Logger&_logger;
            ServiceFactory::shared_ptr _serviceFactory;
    };

} // namespace smarthome