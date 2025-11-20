#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 + ImGui");
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window)) {
        return -1;
    }

    sf::Clock clock;

    while (window.isOpen()) {
        // SFML 3 event loop
        while (auto optEvent = window.pollEvent()) {
            const sf::Event& event = *optEvent;

            ImGui::SFML::ProcessEvent(window, event);

            // ---- NEW SFML 3 way to detect Close event ----
            if (event.is<sf::Event::Closed>())
                window.close();
        }

        ImGui::SFML::Update(window, clock.restart());

        ImGui::Begin("Hello");
        ImGui::Text("This is ImGui + SFML 3!");
        ImGui::End();

        window.clear(sf::Color{20, 20, 20});
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
