#include "vector2.h"
const double pi = 3.1415;

int main()
{

    Vector3 a(0, 0, 0);
    std::cout << a << "\n";
    std::cout << "Input new vector a" << "\n";
    std::cin >> a;

    Vector3 b(1, 0, 0);
    std::cout << b << std::endl;
    std::cout << "Input new vector b" << "\n";
    std::cin >> b;

    std::cout << "a = " << a << "\n";
    std::cout << "a.squareLen() = " << a.squareLen() << "\n";
    std::cout << "a.len() = " << a.len() << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "3 * b = " << 3 * b << "\n";
    std::cout << "a * 2 = " << a * 2 << "\n";
    std::cout << "-a = " << -a << "\n" << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a ^ b = " << (a ^ b) << "\n";

    Vector3 c = a;
    std::cout << "(c = a) = " << c << "\n";
    c += b;
    std::cout << "(c += b) = " << c << "\n";
    c -= b;
    std::cout << "(c -= b) = " << c << "\n" << "\n";

  
    std::cout << "c = " << c << "\n";
    c.norm();
    std::cout << "c.norm() = " << c << "\n";
    Vector3 d, axis;
    std::cout << "Input new vector d" << "\n";
    std::cin >> d;
    std::cout << "Input new vector axis" << "\n";
    std::cin >> axis;
    d.rotate(pi / 2, axis);
    std::cout << "d (angle = pi/2) = " << d << "\n";
    std::cout << "d (angle = -pi/2) = " << d.getRotated(-pi/2, axis) << "\n";
	
    return 0;
}
