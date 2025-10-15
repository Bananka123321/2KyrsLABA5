#include "dust.h"

void Dust::update(double dt){
    position__ = position__ + velocity__ * dt;
    life__ -= dt;
}

bool Dust::isAlive() const { return life__ > 0; }

void Dust::draw(Painter& painter) const {
    if (isAlive()) {
        double alpha = std::max(0.0, life__ / maxLife);
        painter.draw(position__, radius__ * alpha, color__);
    }
}

