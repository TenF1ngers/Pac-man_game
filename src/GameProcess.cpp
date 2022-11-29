#include <../Headers/ConvertSketch.h>
#include <../Headers/DrawGameText.h>
#include <../Headers/DrawMap.h>
#include <../Headers/ListOfCharacters.h>
#include <../Headers/Menu.h>
#include <../Headers/RestartGame.h>

void GameProcess(sf::RenderWindow& window) {
  ListOfCreators creators;
  ListOfCharacters characters(creators);

  auto map_sketch = kMapSketch;
  Map map;
  ConvertSketch(map_sketch, map);

  sf::Clock clock;
  double current_frame = 0.;

  GameText g_text("../Images/Font.ttf");
  GameText level_text("../Images/Font.ttf");

  bool is_game_going = true;

  while (window.isOpen() && is_game_going) {

    double time = static_cast<double>(clock.getElapsedTime().asMicroseconds());
    clock.restart();
    time /= kSmoothnessFactor;

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    characters.Update(map, current_frame, time);
    DrawMap(map, window);
    DrawGameText(window, *characters.pacman, g_text, level_text);
    window.draw(characters.pacman->GetSprite());

    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      is_game_going = false;
      RestartGame(map, characters);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
      RestartGame(map, characters);
    }
  }
  creators.~ListOfCreators();
  characters.~ListOfCharacters();
}