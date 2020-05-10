#pragma once

#include <cstdio>

class matrix {

  private:
    float _m11, _m12, _m13, _m14;
    float _m21, _m22, _m23, _m24;
    float _m31, _m32, _m33, _m34;
    float _m41, _m42, _m43, _m44;

    std::size_t _dim_x, _dim_y;

  public:
    matrix(float m11, float m12, float m13, float m14, 
           float m21, float m22, float m23, float m24,
           float m31, float m32, float m33, float m34,
           float m41, float m42, float m43, float m44,
           std::size_t dim_x, std::size_t dim_y);

    float m11() const { check_dimension(1,1); return _m11; };
    float m12() const { check_dimension(1,2); return _m12; };
    float m13() const { check_dimension(1,3); return _m13; };
    float m14() const { check_dimension(1,4); return _m14; };

    float m21() const { check_dimension(2,1); return _m21; };
    float m22() const { check_dimension(2,2); return _m22; };
    float m23() const { check_dimension(2,3); return _m23; };
    float m24() const { check_dimension(2,4); return _m24; };

    float m31() const { check_dimension(3,1); return _m31; };
    float m32() const { check_dimension(3,2); return _m32; };
    float m33() const { check_dimension(3,3); return _m33; };
    float m34() const { check_dimension(3,4); return _m34; };

    float m41() const { check_dimension(4,1); return _m41; };
    float m42() const { check_dimension(4,2); return _m42; };
    float m43() const { check_dimension(4,3); return _m43; };
    float m44() const { check_dimension(4,4); return _m44; };

  private:
    void check_dimension(std::size_t x, std::size_t y) const;
};

matrix mat4(float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44);

matrix mat3(float m11, float m12, float m13,
            float m21, float m22, float m23,
            float m31, float m32, float m33);

matrix mat2(float m11, float m12,
            float m21, float m22);
