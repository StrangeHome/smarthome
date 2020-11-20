#pragma once

namespace smarthome {

	/**
	 * Abstract base interface into concrete smarthome clients.
	 */
	class Client {
		public:

			/**
			 * Discover the devices connected to the network.
			 */
			virtual void DiscoverDevices() const = 0;
	};

} // namespace smarthome