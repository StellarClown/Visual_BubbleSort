#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "SceneElements.h";

namespace Application {
	class APP : public SceneBase::Scene {
		private:
			SceneElements::Stick* ArrayStick;
			sf::Font font;
			sf::Text MainText;

			bool Sorted = false;

			size_t itera;
			size_t n;

			inline void PrintArrayStick(void) const;
			inline void PrintProgress(void);
			inline void RenderScene(void);

			inline void CheckEvent(void) const;
			inline void Render(void);
		public:
			APP(const size_t, const size_t, const char*);
			~APP() = default;

			int WindowLoop(void) override;
	};
}

#endif