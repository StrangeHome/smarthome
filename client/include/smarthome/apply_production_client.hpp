#pragma once

#include <smarthome/apply_production_logger.hpp>
#include <smarthome/logger.hpp>

#include <smarthome/client.hpp>
#include <smarthome/client_impl.hpp>
#include <cppject/service_factory.hpp>

namespace smarthome {

    const struct ApplyProductionClient {
        public:
            ApplyProductionClient() {

                auto serviceFactory = cppject::ServiceFactory::Instance();

                serviceFactory->Inject<ClientImpl, Client>();

                auto& logger = serviceFactory->Get<Logger>();
                logger.debug("Applied production client.");
            }
    } applyProductionClient;

} // namespace smarthome