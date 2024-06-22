#include "framework/Application.h"
#include <framework/Core.h>
#include <framework/World.h>

ly::Application::Application() : 
	mWindow{ sf::VideoMode(512,720), "Light Years" },
	mTargetFrameRate{60.f},
	mTickClock{}, // defualt constructor,
	currentWorld{nullptr}
{
}

void ly::Application::Run()
{
	mTickClock.restart();
	float accumulatedTime = 0.f;
	float targetDeltaTime = 1.f / mTargetFrameRate;

	while (mWindow.isOpen()) {
		sf::Event windowEvent;
		while (mWindow.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::EventType::Closed) {
				mWindow.close();
			}
		}

		// refresh at fixed rate
		accumulatedTime += mTickClock.restart().asSeconds();
		while (accumulatedTime > targetDeltaTime) {
			accumulatedTime -= targetDeltaTime;
			TickInternal(targetDeltaTime);
			RenderInternal();
		}
	}
}

void ly::Application::TickInternal(float deltaTime)
{
	Tick(deltaTime);
	if (currentWorld) {
		currentWorld->BeginPlayInternal();
		currentWorld->TickInternal(deltaTime);
	}
}

void ly::Application::RenderInternal()
{
	mWindow.clear();

	Render();

	mWindow.display();
}

void ly::Application::Render()
{
	sf::RectangleShape rect{ sf::Vector2f{100,100} };
	rect.setFillColor(sf::Color::Green);
	rect.setOrigin(50, 50);
	rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

	mWindow.draw(rect);
}

void ly::Application::Tick(float deltaTime)
{
	 
}


