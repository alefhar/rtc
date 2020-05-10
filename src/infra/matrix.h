#pragma once

#include "util.h"

#include <cstdio>
#include <cmath>

class matrix {

  private:
    float _m11, _m12, _m13, _m14;
    float _m21, _m22, _m23, _m24;
    float _m31, _m32, _m33, _m34;
    float _m41, _m42, _m43, _m44;

    std::size_t _dim;

  public:
    matrix(float m11, float m12, float m13, float m14, 
           float m21, float m22, float m23, float m24,
           float m31, float m32, float m33, float m34,
           float m41, float m42, float m43, float m44,
           std::size_t dim);

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

    friend bool operator==(const matrix& lhs, const matrix& rhs)
    {
      if (lhs._dim != rhs._dim)
        return false;

      bool eq11 = are_close(lhs.m11(), rhs.m11());
      bool eq12 = are_close(lhs.m12(), rhs.m12());
      bool eq21 = are_close(lhs.m21(), rhs.m21());
      bool eq22 = are_close(lhs.m22(), rhs.m22());
      
      bool sub22_eq = eq11 && eq12 && eq21 && eq22;
      if (lhs._dim == 2)
        return sub22_eq;

      bool eq13 = are_close(lhs.m13(), rhs.m13());
      bool eq23 = are_close(lhs.m23(), rhs.m23());
      bool eq31 = are_close(lhs.m31(), rhs.m31());
      bool eq32 = are_close(lhs.m32(), rhs.m32());
      bool eq33 = are_close(lhs.m33(), rhs.m33());

      bool sub33_eq = sub22_eq && eq13 && eq23 && eq31 && eq32 && eq33;
      if (lhs._dim == 3)
        return sub33_eq;

      bool eq14 = are_close(lhs.m14(), rhs.m14());
      bool eq24 = are_close(lhs.m24(), rhs.m24());
      bool eq34 = are_close(lhs.m34(), rhs.m34());
      bool eq41 = are_close(lhs.m41(), rhs.m41());
      bool eq42 = are_close(lhs.m42(), rhs.m42());
      bool eq43 = are_close(lhs.m43(), rhs.m43());
      bool eq44 = are_close(lhs.m44(), rhs.m44());

      return sub33_eq && eq14 && eq24 && eq34 && eq41 && eq42 && eq43 && eq44;
    }

    friend bool operator!=(const matrix& lhs, const matrix& rhs)
    {
      return !(lhs == rhs);
    }

    matrix operator*=(const matrix& rhs);
    friend matrix operator*(matrix lhs, const matrix& rhs)
    {
      return lhs *= rhs;
    }

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
