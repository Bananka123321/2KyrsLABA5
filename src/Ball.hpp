#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
private:
    Point position__;
    double radius__;
    Color color__;
    Velocity velocity__;
    bool Collidable__;
    
public:
    Ball() : position__(0,0), radius__(20), color__(255, 0, 0) {}
    Ball(Point position, Velocity velocity, double radius, Color color, bool bColliadable) {
        position__ = position;
        velocity__ = velocity;
        radius__ = radius;
        color__ = color;
        Collidable__ = bColliadable;
    }
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getCollidable() const;
    Color getColor() const;
};
