#pragma once

#include <smarthome/logger.hpp>
#include <smarthome/colored_logger.hpp>
#include <cppject/service_factory.hpp>

namespace smarthome {

    const struct ApplyProductionLogger {
        public:
            ApplyProductionLogger() {

                auto serviceFactory = ServiceFactory::Instance();

                serviceFactory->Inject<ColoredLogger, Logger>();

                auto logger = serviceFactory->Get<Logger>();
                logger->debug("Applied production logger.");
            }
    } applyProductionLogger;

} // namespace smarthome