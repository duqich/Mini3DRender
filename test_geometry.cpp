//
// Created by duke on 2022/7/10.
//

#include "geometry.h"
#include <iostream>

void test_Vec2(){
    Vec2f a = {1., 1.};
    Vec2f b = {2., 2.};
    Vec2f c = a+b;
    Vec2f d = a-b;
    Vec2f e = a*.1;
    std::cout << a << b << c << d << e << std::endl;
}
void test_Vec3(){
    Vec3f a = {3., 3., 3.};
    Vec3f b = {4., 4., 4.};
    Vec3f c = a+b;
    Vec3f d = a-b;
    Vec3f e = a*.1;
    Vec3f f = a*b;
    float g = a.norm();
    std::cout << a << b << c << d << e << f << g << std::endl;
}


int main() {
    test_Vec2();
    test_Vec3();
    return 0;
}