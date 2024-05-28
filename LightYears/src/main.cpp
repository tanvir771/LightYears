#include <iostream>
#include <Memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main() {
	// store in the heap since stack has limited space, and application contains everything
	std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
	app->Run();
}

