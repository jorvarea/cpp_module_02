#include <iostream>
#include "Point.hpp"

void test(Point const& a, Point const& b, Point const& c, Point const& p, const std::string& name) {
    std::cout << name << ": ";
    if (bsp(a, b, c, p))
        std::cout << "✅ Inside\n";
    else
        std::cout << "❌ Outside\n";
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point inside(1.0f, 1.0f);
    Point outside(5.0f, 5.0f);
    Point edgePoint(2.5f, 0.0f);
    Point vertexA(0.0f, 0.0f);

    test(a, b, c, inside, "Test 1: Inside");
    test(a, b, c, outside, "Test 2: Outside");
    test(a, b, c, edgePoint, "Test 3: On Edge");
    test(a, b, c, vertexA, "Test 4: At Vertex");

    return 0;
}
