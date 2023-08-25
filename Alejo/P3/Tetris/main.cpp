#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Clase para representar una palabra en el juego
class Word {
public:
    Word(const std::string& text, const sf::Vector2f& position)
        : text(text), position(position) {
        font.loadFromFile("Action_Man.ttf"); // Cambia a la ruta de tu fuente
        textObj.setFont(font);
        textObj.setString(text);
        textObj.setCharacterSize(24);
        textObj.setPosition(position);
    }

    void move(float offsetX, float offsetY) {
        position.x += offsetX;
        position.y += offsetY;
        textObj.setPosition(position);
    }

    sf::FloatRect getBounds() const {
        return textObj.getGlobalBounds();
    }

    void draw(sf::RenderWindow& window) {
        window.draw(textObj);
    }

    void setString(const std::string& text) {
        this->text = text;
        textObj.setString(text);
    }

private:
    std::string text;
    sf::Font font;
    sf::Text textObj;
    sf::Vector2f position;
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    float moveSpeed = 10.0f;

    sf::RenderWindow window(sf::VideoMode(400, 600), "Tetris de palabras");
    window.setFramerateLimit(60);

    std::vector<std::string> wordList = {"Hola", "Mundo", "Cola", "Pepsi"};
    std::vector<Word> fallingWords;
    // int rI = rand() % 4;
    // Word fallingWord(word, sf::Vector2f(200 - 10*(word.length()/2), 10));
    float fallSpeed = 2.5f;
    bool canSpawnWord = true;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Spawn a new word if possible
        if (canSpawnWord) {
            int randomIndex = rand() % 4;
            std::string word = wordList[randomIndex];
            fallingWords.emplace_back(word, sf::Vector2f(200 - 11.5*(word.length()/2), 10));
            canSpawnWord = false;
        }

        // Move falling words and handle collisions
        Word& word = fallingWords.back();

            if (word.getBounds().top + word.getBounds().height >= 500) {
                word.move(0, -fallSpeed);
                canSpawnWord = true;
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if(word.getBounds().left <= 50){
                    word.move(0, fallSpeed);
                } else {
                    word.move(-moveSpeed, fallSpeed);
                }
                window.clear();
                word.draw(window);
                window.display();
            } else {
                word.move(0, fallSpeed);
                window.clear();
                word.draw(window);
                window.display();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if(word.getBounds().left >= 300){
                    word.move(0, fallSpeed);
                } else {
                    word.move(moveSpeed, fallSpeed);
                }
                window.clear();
                word.draw(window);
                window.display();
            } else {
                word.move(0, fallSpeed);
                window.clear();
                word.draw(window);
                window.display();
            }

        // Check for word collisions and remove duplicates
        // for (auto it = fallingWords.begin(); it != fallingWords.end(); ) {
        //     bool removed = false;
        //     for (auto it2 = it + 1; it2 != fallingWords.end(); ++it2) {
        //         if (it->getBounds().intersects(it2->getBounds()) && it->getBounds() != it2->getBounds()) {
        //             it = fallingWords.erase(it);
        //             it2 = fallingWords.erase(it2);
        //             removed = true;
        //             break;
        //         }
        //     }
        //     if (!removed) ++it;
        // }

        // window.clear();

        // // Draw falling words
        // for (auto& word : fallingWords) {
        //     word.draw(window);
        // }
    
        // window.display();
    }

    return 0;
}
