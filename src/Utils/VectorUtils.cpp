#include "VectorUtils.h"

namespace VectorUtils {

    sf::Vector2f normalize(const sf::Vector2f& vector) {
        sf::Vector2f normalizedVector;
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

        if (magnitude != 0) {
            normalizedVector = {vector.x / magnitude, vector.y / magnitude};
        } else {
            normalizedVector = {0.f, 0.f};
        }

        return normalizedVector;
    }

}