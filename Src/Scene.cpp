#include <SFML/Graphics.hpp>
#include "../Headers/Scene.h"

using namespace SceneBase;
using namespace sf;

Scene::Scene(const size_t Width, const size_t Height, const char* Title) : WindowApp(new RenderWindow(VideoMode(Width, Height), Title, Style::Close)), width(Width), height(Height) {
	;
}