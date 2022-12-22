#ifndef SceneElements_H
#define SceneElements_H

#include <SFML/Graphics.hpp>

namespace SceneElements {
	class Stick {
		private:
			size_t height;
			const size_t width;
		public:
			Stick(const size_t ValueStick = 0);
			~Stick() = default;

			const sf::RectangleShape getStick(const uint16_t, const uint16_t, const bool) const;

			bool operator> (const Stick&) const;
			void operator= (const Stick&);
	};
}

#endif