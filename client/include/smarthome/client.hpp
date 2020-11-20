#pragma once

namespace smarthome {

	/**
	 * Abstract base interface into concrete smarthome clients.
	 */
	class Client {
		public:

			/**
			 * Configure peripheral devices for use with the smarthome.
			 */
			virtual void ConfigureDevices() const = 0;

			/**
			 * Discover the devices connected to the network.
			 */
			virtual void DiscoverDevices() const = 0;
	};

} // namespace smarthome