//
// Created by duke on 2022/7/10.
//

#ifndef MINI3DRENDER_GEOMETRY_H
#define MINI3DRENDER_GEOMETRY_H

#include <cmath>
#include <ostream>

template <class t> struct Vec2 {
    union {
        struct {t x,y;};
        struct {t u,v;};
        t raw[2];
    };
    Vec2(): x(0), y(0){}
    Vec2(t _x, t _y): x(_x), y(_y){}
    inline Vec2<t> operator+(const Vec2<t> &V){return Vec2<t>(x + V.x, y + V.y);}
    inline Vec2<t> operator-(const Vec2<t> &V){return Vec2<t>(x - V.x, y - V.y);}
    inline Vec2<t> operator*(float f){return Vec2<t>(x*f, y*f);}
    template<class > friend std::ostream& operator<<(std::ostream& s, Vec2<t>& V);
};

template <class t> struct Vec3 {
    union {
        struct {t x,y,z;};
        struct {t ivert, iuv, inorm;};
        t raw[3];
    };
    Vec3(): x(0), y(0), z(0){}
    Vec3(t _x, t _y,t _z): x(_x), y(_y), z(_z){}
    inline Vec3<t> operator+(const Vec3<t> &V){return Vec3<t>(x + V.x, y + V.y, z + V.z);}
    inline Vec3<t> operator-(const Vec3<t> &V){return Vec3<t>(x - V.x, y - V.y, z - V.z);}
    inline Vec3<t> operator*(float f){return Vec3<t>(x*f, y*f, z*f);}
    inline Vec3<t> operator*(const Vec3<t> &V){return Vec3<t>(x*V.x, y*V.y, z*V.z);}
    template<class > friend std::ostream& operator<<(std::ostream& s, Vec3<t>& V);
    float norm(){return std::sqrt(x*x+y*y+z*z);}
};

typedef Vec2<float> Vec2f;
typedef Vec2<int>   Vec2i;
typedef Vec3<float> Vec3f;
typedef Vec3<int>   Vec3i;

template<class t> std::ostream& operator<<(std::ostream& s, Vec2<t>& V){
    s << "(" << V.x << ", " << V.y << ")\n";
    return s;
}
template<class t> std::ostream& operator<<(std::ostream& s, Vec3<t>& V){
    s << "(" << V.x << ", " << V.y << ", " << V.z << ")\n";
    return s;
}

#endif //MINI3DRENDER_GEOMETRY_H
