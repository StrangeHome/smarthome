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

            // void ConfigureDevices(std::vector<borderland::Device>& devices) const override {
            void ConfigureDevices() const override {

                // borderland::configureDevices(devices, configurations);
                _logger->info("Devices configured.");
            }

            void DiscoverDevices() const override {

                // return borderland::discoverDevices();
                _logger->info("Devices found.");
            }

        private:

            const Logger::shared_ptr _logger;
            ServiceFactory::shared_ptr _serviceFactory;
    };

} // namespace smarthome