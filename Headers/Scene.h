#ifndef Scene_H
#define Scene_H

#include <SFML/Graphics.hpp>

namespace SceneBase {
	class Scene {
		protected:
			sf::RenderWindow* WindowApp;

			const size_t width;
			const size_t height;
		public:
			Scene(const size_t, const size_t, const char*);
			~Scene() = default;

			virtual int WindowLoop(void) = 0;
	};
}

#endif