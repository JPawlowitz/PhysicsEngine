//
// Created by Jan Pawlowitz on 22.02.23.
//

#ifndef PHYSICSENGINE_COLORPALETTE_H
#define PHYSICSENGINE_COLORPALETTE_H

#include <SFML/Graphics.hpp>
#include <array>

namespace Colors {
    inline const std::array<sf::Color, 10> pastelPalette {
            sf::Color{251, 248, 204},
            sf::Color{253, 228, 207},
            sf::Color{255, 207, 210},
            sf::Color{241, 192, 232},
            sf::Color{163, 196, 243},
            sf::Color{144, 219, 244},
            sf::Color{142, 236, 245},
            sf::Color{152, 245, 225},
            sf::Color{185, 251, 192},
            sf::Color{207, 186, 240},
    };
}

#endif //PHYSICSENGINE_COLORPALETTE_H
