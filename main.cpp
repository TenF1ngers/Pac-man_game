#include <../Headers/CharactersManager.h>
#include <../Headers/Menu.h>

int main() {
  sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Pac-man");

  Menu(window);

  return 0;
}
