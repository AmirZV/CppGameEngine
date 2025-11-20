#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "CG Engine");
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window))
    {
        return -1;
    }

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional optEvent = window.pollEvent())
        {
            const sf::Event& event = *optEvent;

            ImGui::SFML::ProcessEvent(window, event);

            // "close requested" event: we close the window
            if (event.is<sf::Event::Closed>())
                window.close();
        }

        ImGui::SFML::Update(window, clock.restart());

        ImGui::Begin("Menu");
        ImGui::Text("Play with the Engine!");
        ImGui::End();


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        //window.draw(...);
        ImGui::SFML::Render(window);

        // end the current frame
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
