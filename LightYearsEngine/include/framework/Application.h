#pragma once
#include <SFML/Graphics.hpp>
#include <framework/Core.h>

namespace ly {
	class World; // forward declare World class
	class Application {
	public:
		Application();
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

		shared<World> currentWorld;
	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld() {
		shared<WorldType> newWorld{ new WorldType(this) }; // this triggers the world constructor when <World>
														   // passed - it could trigger int construcotr if <int>
		currentWorld = newWorld;
		return newWorld;
	}
}