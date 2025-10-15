#pragma once
#include <iostream>

class Color {
public:
  Color();
  Color(double red, double green, double blue);
  double red() const;
  double green() const;
  double blue() const;

  friend std::istream& operator>>(std::istream& in, Color& c) {
      double r, g, b;
      in >> r >> g >> b;
      c = Color(r, g, b);
      return in;
  }

private:
  double r{};
  double g{};
  double b{};
};

