#pragma once

#include <array>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <../Headers/GameTextClass.h>
#include <../Headers/Global.h>
#include <../Headers/Pacman.h>

void DrawGameText(sf::RenderWindow& window, Pacman& pacman, GameText& g_text, GameText& level_text);