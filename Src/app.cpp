#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string_view>
#include "../Headers/Scene.h"
#include "../Headers/app.h"
#include "../Headers/SceneElements.h"

using namespace Application;
using namespace sf;
using namespace SceneElements;
using namespace SceneBase;

/*
	PUBLIC
*/
APP::APP(const size_t Width, const size_t Height, const char* Title) : Scene(Width, Height, Title), ArrayStick(new Stick[Width]), itera(Width), n(0) {
	srand(time(0));
	
	for (size_t i = 0; i < this->width; i++) 
		ArrayStick[i] = ((rand() % this->height) + 1);

	this->font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	this->MainText.setFont(this->font);
	this->MainText.setCharacterSize(18);
	this->MainText.setPosition(0, 0);
	this->MainText.setFillColor(Color::Blue);
}

int APP::WindowLoop(void) {
	while (WindowApp->isOpen()) {
		//Check event on the window of the app
		this->CheckEvent();

		//I render the scene
		this->Render();
	}

	return EXIT_SUCCESS;
}









/*
	PRIVATE
*/
inline void APP::CheckEvent(void) const {
	Event e;
	while (WindowApp->pollEvent(e))
		if (e.type == Event::Closed) WindowApp->close();
}

inline void APP::Render(void) {
	if (!this->Sorted) {
		//Swap the elements
		if (ArrayStick[this->n] > ArrayStick[this->n + 1])
			std::swap(ArrayStick[this->n], ArrayStick[this->n + 1]);

		this->RenderScene(); //I show the current sorting progress on the screen

		//Next sorting
		if (this->n > (this->width - 1)) {
			--this->itera;
			this->n = 0;
		}
		else {
			++this->n;
		}

		//Stop the sorting
		if (this->itera < 0) 
			this->Sorted = true;
	}
	else {
		this->RenderScene(); //I show the result of the sort on the screen
	}
}







inline void APP::PrintArrayStick(void) const {
	for (size_t i = 0; i < this->width; i++) 
		WindowApp->draw(this->ArrayStick[i].getStick(i, this->height, (i == this->n))); //I print the i-th stick on the screen highlighting the current one
}

inline void APP::PrintProgress(void) {
	if (this->Sorted)
		this->MainText.setString("Completed");
	else
		this->MainText.setString(static_cast<std::string>(std::to_string(this->width - this->itera)+"/") + std::to_string(this->width));

	WindowApp->draw(this->MainText);
}

inline void APP::RenderScene(void) {
	WindowApp->clear(Color::White);
	this->PrintArrayStick();
	this->PrintProgress();
	WindowApp->display();
}