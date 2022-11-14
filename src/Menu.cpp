#include <../Headers/GameProcess.h>
#include <../Headers/GameTextClass.h>
#include <../Headers/Menu.h>

void Menu(sf::RenderWindow& window) {
  Picture background;
  background.image.loadFromFile("../Images/BackgroundMenu.png");
  background.texture.loadFromImage(background.image);
  background.sprite.setTexture(background.texture);
  background.sprite.setPosition(0, 0);

  sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2);

  GameText title_pacman("../Images/Font.ttf");
  title_pacman.text.setString("P  c-man");
  title_pacman.text.setScale(4., 4.);
  title_pacman.text.setPosition(centerPos.x - title_pacman.text.getGlobalBounds().width / 2, centerPos.y - title_pacman.text.getGlobalBounds().height / 2 - kMapHeight / 4 * (kCellSize + 10) * kMultiplier);

  Picture title_pacman_image;
  title_pacman_image.image.loadFromFile("../Images/Pacman16.png");
  title_pacman_image.texture.loadFromImage(title_pacman_image.image);
  title_pacman_image.sprite.setTexture(title_pacman_image.texture);
  title_pacman_image.sprite.setTextureRect(sf::IntRect(kCellSize * 3, 0, kCellSize, kCellSize));
  title_pacman_image.sprite.setScale(6., 6.);
  title_pacman_image.sprite.setPosition(centerPos.x - title_pacman.text.getGlobalBounds().width / 2 + kCellSize * kMultiplier * 2.3, centerPos.y - title_pacman.text.getGlobalBounds().height / 2 - kMapHeight / 4 * (kCellSize + 5) * kMultiplier);

  GameText new_game("../Images/Font.ttf");
  new_game.text.setString("New game");
  new_game.text.setPosition(centerPos.x - new_game.text.getGlobalBounds().width / 2, centerPos.y - new_game.text.getGlobalBounds().height / 2 + kMapHeight / 4 * kCellSize * kMultiplier);

  GameText exit("../Images/Font.ttf");
  exit.text.setString("Exit");
  exit.text.setPosition(centerPos.x - exit.text.getGlobalBounds().width / 2, centerPos.y - exit.text.getGlobalBounds().height / 2 + kMapHeight / 4 * (kCellSize + 3) * kMultiplier);

  int menu_num = -1;

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (sf::IntRect(centerPos.x - new_game.text.getGlobalBounds().width / 2, centerPos.y - new_game.text.getGlobalBounds().height / 2 + kMapHeight / 4 * kCellSize * kMultiplier + 15,
                    new_game.text.getGlobalBounds().width + 4, new_game.text.getGlobalBounds().height).contains(sf::Mouse::getPosition(window))) {
      new_game.text.setColor(sf::Color(255, 250, 52));  //  Yellow
      menu_num = 1;
    } else if (sf::IntRect(centerPos.x - exit.text.getGlobalBounds().width / 2, centerPos.y - exit.text.getGlobalBounds().height / 2 + kMapHeight / 4 * (kCellSize + 3) * kMultiplier + 19,
                           exit.text.getGlobalBounds().width + 5, exit.text.getGlobalBounds().height + 5).contains(sf::Mouse::getPosition(window))) {
      exit.text.setColor(sf::Color(255, 250, 52));  //  Yellow
      menu_num = 2;
    } else if (sf::IntRect(centerPos.x - title_pacman.text.getGlobalBounds().width / 2 + kCellSize * kMultiplier * 2.3, centerPos.y - title_pacman.text.getGlobalBounds().height / 2 - kMapHeight / 4 * (kCellSize + 5) * kMultiplier,
                           kCellSize * 6., kCellSize * 6.).contains(sf::Mouse::getPosition(window))) {
      menu_num = 3;
    } else {
      new_game.text.setColor(sf::Color::White);
      exit.text.setColor(sf::Color::White);
      menu_num = -1;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if ((menu_num == 1) || (menu_num == 3)) {
        GameProcess(window);
      } else if (menu_num == 2) {
        window.close();
      }
    }

    window.clear();

    window.draw(background.sprite);
    window.draw(title_pacman.text);
    window.draw(title_pacman_image.sprite);
    window.draw(new_game.text);
    window.draw(exit.text);

    window.display();
  }
}