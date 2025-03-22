#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 455), "Calculator"); 

    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) {
        std::cerr << "Error loading font Roboto-Regular.ttf!" << std::endl;
        return 1;
    }
    else {
        std::cout << "Font loaded successfully!" << std::endl;
    }

    // Дисплей
    sf::RectangleShape displayRect(sf::Vector2f(280, 50));
    displayRect.setPosition(10, 10);
    displayRect.setFillColor(sf::Color(220, 220, 220));
    displayRect.setOutlineThickness(1);
    displayRect.setOutlineColor(sf::Color::Black);

    sf::Text displayText("", font, 24);
    displayText.setPosition(15, 20);
    displayText.setFillColor(sf::Color::Black);

    sf::RectangleShape buttons[17]; 
    sf::Text buttonTexts[17]; 
    std::string buttonLabels[17] = { 
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+", "C"
    };

    for (int i = 0; i < 17; ++i) { 
        buttons[i].setSize(sf::Vector2f(70, 50));
        buttons[i].setPosition(10 + (i % 4) * 75, 70 + (i / 4) * 55);
        buttons[i].setFillColor(sf::Color::White);
        buttons[i].setOutlineThickness(1);
        buttons[i].setOutlineColor(sf::Color::Black);

        buttonTexts[i].setFont(font);
        buttonTexts[i].setString(buttonLabels[i]);
        buttonTexts[i].setCharacterSize(24);
        buttonTexts[i].setPosition(buttons[i].getPosition().x + 25, buttons[i].getPosition().y + 15);
        buttonTexts[i].setFillColor(sf::Color::Black);
    }

    std::string input = "";
    double operand1 = 0;
    char operation = ' ';

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 17; ++i) { 
                        if (buttons[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            std::string label = buttonLabels[i];
                            if (label == "C") { 
                                input = "";
                                displayText.setString(input);
                            }
                            else if (label == "=") {
                                double operand2 = std::stod(input);
                                double result = 0;
                                switch (operation) {
                                case '+': result = operand1 + operand2; break;
                                case '-': result = operand1 - operand2; break;
                                case '*': result = operand1 * operand2; break;
                                case '/': result = operand1 / operand2; break;
                                }
                                input = std::to_string(result);
                                displayText.setString(input);
                            }
                            else if (label == "+" || label == "-" || label == "*" || label == "/") {
                                operand1 = std::stod(input);
                                operation = label[0];
                                input = "";
                            }
                            else {
                                input += label;
                                displayText.setString(input);
                            }
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(displayRect);
        window.draw(displayText);
        for (int i = 0; i < 17; ++i) { 
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }
        window.display();
    }

    return 0;
}