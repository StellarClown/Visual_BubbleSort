#include "Headers/app.h"

int main(void) {
	Application::APP app(600, 400, "Visual Bubble Sorting");

	return app.WindowLoop();
}