#include "VectorUtils.h"

namespace VectorUtils {
    sf::Vector2f normalize(const sf::Vector2f& vector) {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

        if (magnitude != 0) {
            return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
        } else {
            // Handle the case where the vector has zero magnitude to avoid division by zero.
            return sf::Vector2f(0.f, 0.f);
        }
    }
}