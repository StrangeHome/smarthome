#pragma once

#include <smarthome/client.hpp>

namespace smarthome {

    class ClientImpl : public Client {
        public:

            void DiscoverDevices() const override {
                // TODO
            }
    };

} // namespace smarthome