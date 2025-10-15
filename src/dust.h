#pragma once
#include "Painter.h"
#include "Point.h"
#include "Color.h"
#include "Velocity.h"
#include <cmath>
#include <random>

class Dust {
private:
    Point position__, velocity__;
    Color color__;
    double life__, maxLife = 0.5, radius__ = 40;
    
public:
    Dust(Point position, Point velocity, double life, Color color) {
        position__ = position;
        velocity__ = velocity;
        life__ = life;
        color__ = color;
    }
    void update(double dt);
    bool isAlive() const;
    void draw(Painter& painter) const;
    static Dust randomParticle(const Point& center, const Color& baseColor) {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> angleDist(0, 2 * M_PI);
        std::uniform_real_distribution<double> speedDist(20, 100);

        double angle = angleDist(rng);
        double speed = speedDist(rng);

        Point vel{ std::cos(angle) * speed, std::sin(angle) * speed };

        return Dust(center, vel, 0.5, baseColor);
    }
};
