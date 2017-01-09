#pragma once
#ifndef im3d_math_h
#define im3d_math_h

#include "im3d.h"

#include <cmath>

namespace Im3d {

inline Vec2  operator+(const Vec2& _lhs, const Vec2& _rhs) { return Vec2(_lhs.x + _rhs.x, _lhs.y + _rhs.y); }
inline Vec2  operator-(const Vec2& _lhs, const Vec2& _rhs) { return Vec2(_lhs.x - _rhs.x, _lhs.y - _rhs.y); }
inline Vec2  operator*(const Vec2& _lhs, const Vec2& _rhs) { return Vec2(_lhs.x * _rhs.x, _lhs.y * _rhs.y); }
inline Vec2  operator/(const Vec2& _lhs, const Vec2& _rhs) { return Vec2(_lhs.x / _rhs.x, _lhs.y / _rhs.y); }
inline Vec2  operator*(const Vec2& _lhs, float _rhs)       { return Vec2(_lhs.x * _rhs, _lhs.y * _rhs);     }
inline Vec2  operator/(const Vec2& _lhs, float _rhs)       { return Vec2(_lhs.x / _rhs, _lhs.y / _rhs);     }
inline Vec2  operator-(const Vec2& _v)                     { return Vec2(-_v.x, -_v.y);                     }
inline float Dot(const Vec2& _lhs, const Vec2& _rhs)       { return _lhs.x * _rhs.x + _lhs.y * _rhs.y;      }
inline float Length(const Vec2& _v)                        { return sqrtf(Dot(_v, _v));                     }
inline float Length2(const Vec2& _v)                       { return Dot(_v, _v);                            }
inline Vec2  Abs(const Vec2& _v)                           { return Vec2(fabs(_v.x), fabs(_v.y));           }
inline Vec2  Normalize(const Vec2& _v)                     { return _v / Length(_v);                        }

inline Vec3  operator+(const Vec3& _lhs, const Vec3& _rhs) { return Vec3(_lhs.x + _rhs.x, _lhs.y + _rhs.y, _lhs.z + _rhs.z); }
inline Vec3  operator-(const Vec3& _lhs, const Vec3& _rhs) { return Vec3(_lhs.x - _rhs.x, _lhs.y - _rhs.y, _lhs.z - _rhs.z); }
inline Vec3  operator*(const Vec3& _lhs, const Vec3& _rhs) { return Vec3(_lhs.x * _rhs.x, _lhs.y * _rhs.y, _lhs.z * _rhs.z); }
inline Vec3  operator/(const Vec3& _lhs, const Vec3& _rhs) { return Vec3(_lhs.x / _rhs.x, _lhs.y / _rhs.y, _lhs.z / _rhs.z); }
inline Vec3  operator*(const Vec3& _lhs, float _rhs)       { return Vec3(_lhs.x * _rhs, _lhs.y * _rhs, _lhs.z * _rhs);       }
inline Vec3  operator/(const Vec3& _lhs, float _rhs)       { return Vec3(_lhs.x / _rhs, _lhs.y / _rhs, _lhs.z / _rhs);       }
inline Vec3  operator-(const Vec3& _v)                     { return Vec3(-_v.x, -_v.y, -_v.z);                               } 
inline float Dot(const Vec3& _lhs, const Vec3& _rhs)       { return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;     }
inline float Length(const Vec3& _v)                        { return sqrtf(Dot(_v, _v));                                      }
inline float Length2(const Vec3& _v)                       { return Dot(_v, _v);                                             }
inline Vec3  Abs(const Vec3& _v)                           { return Vec3(fabs(_v.x), fabs(_v.y), fabs(_v.z));                }
inline Vec3  Normalize(const Vec3& _v)                     { return _v / Length(_v);                        }
inline Vec3  Cross(const Vec3& _a, const Vec3& _b)         
{
	return Vec3(
		_a.y * _b.z - _b.y * _a.z,
		_a.z * _b.x - _b.z * _a.x,
		_a.x * _b.y - _b.x * _a.y
		);
}

inline Vec4  operator+(const Vec4& _lhs, const Vec4& _rhs) { return Vec4(_lhs.x + _rhs.x, _lhs.y + _rhs.y, _lhs.z + _rhs.z, _lhs.w + _rhs.w); }
inline Vec4  operator-(const Vec4& _lhs, const Vec4& _rhs) { return Vec4(_lhs.x - _rhs.x, _lhs.y - _rhs.y, _lhs.z - _rhs.z, _lhs.w - _rhs.w); }
inline Vec4  operator*(const Vec4& _lhs, const Vec4& _rhs) { return Vec4(_lhs.x * _rhs.x, _lhs.y * _rhs.y, _lhs.z * _rhs.z, _lhs.w * _rhs.w); }
inline Vec4  operator/(const Vec4& _lhs, const Vec4& _rhs) { return Vec4(_lhs.x / _rhs.x, _lhs.y / _rhs.y, _lhs.z / _rhs.z, _lhs.w / _rhs.w); }
inline Vec4  operator*(const Vec4& _lhs, float _rhs)       { return Vec4(_lhs.x * _rhs, _lhs.y * _rhs, _lhs.z * _rhs, _lhs.w * _rhs);         }
inline Vec4  operator/(const Vec4& _lhs, float _rhs)       { return Vec4(_lhs.x / _rhs, _lhs.y / _rhs, _lhs.z / _rhs, _lhs.w / _rhs);         }
inline Vec4  operator-(const Vec4& _v)                     { return Vec4(-_v.x, -_v.y, -_v.z, -_v.w);                                         }
inline float Dot(const Vec4& _lhs, const Vec4& _rhs)       { return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;    }
inline float Length(const Vec4& _v)                        { return sqrtf(Dot(_v, _v));                                                       }
inline float Length2(const Vec4& _v)                       { return Dot(_v, _v);                                                              }
inline Vec4  Abs(const Vec4& _v)                           { return Vec4(fabs(_v.x), fabs(_v.y), fabs(_v.z), fabs(_v.w));                     }
inline Vec4  Normalize(const Vec4& _v)                     { return _v / Length(_v);                        }

inline Mat4 operator*(const Mat4& _lhs, const Mat4& _rhs)
{
	// \todo expand, remove Dot calls
	Mat4 ret;
	ret(0, 0) = Dot(_lhs.getRow(0), _rhs.getCol(0));
	ret(0, 1) = Dot(_lhs.getRow(0), _rhs.getCol(1));
	ret(0, 2) = Dot(_lhs.getRow(0), _rhs.getCol(2));
	ret(0, 3) = Dot(_lhs.getRow(0), _rhs.getCol(3));

	ret(1, 0) = Dot(_lhs.getRow(1), _rhs.getCol(0));
	ret(1, 1) = Dot(_lhs.getRow(1), _rhs.getCol(1));
	ret(1, 2) = Dot(_lhs.getRow(1), _rhs.getCol(2));
	ret(1, 3) = Dot(_lhs.getRow(1), _rhs.getCol(3));

	ret(2, 0) = Dot(_lhs.getRow(2), _rhs.getCol(0));
	ret(2, 1) = Dot(_lhs.getRow(2), _rhs.getCol(1));
	ret(2, 2) = Dot(_lhs.getRow(2), _rhs.getCol(2));
	ret(2, 3) = Dot(_lhs.getRow(2), _rhs.getCol(3));

	ret(3, 0) = Dot(_lhs.getRow(3), _rhs.getCol(0));
	ret(3, 1) = Dot(_lhs.getRow(3), _rhs.getCol(1));
	ret(3, 2) = Dot(_lhs.getRow(3), _rhs.getCol(2));
	ret(3, 3) = Dot(_lhs.getRow(3), _rhs.getCol(3));

	return ret;
}

inline Vec3 operator*(const Mat4& _m, const Vec3& _pos)
{
	return Vec3(
		_m(0, 0) * _pos.x + _m(0, 1) * _pos.y + _m(0, 2) * _pos.z + _m(0, 3),
		_m(1, 0) * _pos.x + _m(1, 1) * _pos.y + _m(1, 2) * _pos.z + _m(1, 3),
		_m(2, 0) * _pos.x + _m(2, 1) * _pos.y + _m(2, 2) * _pos.z + _m(2, 3)
		);
}
inline Vec4 operator*(const Mat4& _m, const Vec4& _v)
{
	return Vec4(
		_m(0, 0) * _v.x + _m(0, 1) * _v.y + _m(0, 2) * _v.z + _m(0, 3) * _v.w,
		_m(1, 0) * _v.x + _m(1, 1) * _v.y + _m(1, 2) * _v.z + _m(1, 3) * _v.w,
		_m(2, 0) * _v.x + _m(2, 1) * _v.y + _m(2, 2) * _v.z + _m(2, 3) * _v.w,
		_m(3, 0) * _v.x + _m(3, 1) * _v.y + _m(3, 2) * _v.z + _m(3, 3) * _v.w
		);
}

// defined in im3d.cpp
Mat4  Inverse(const Mat4& _m);
Mat4  Transpose(const Mat4& _m);
Mat4  Translate(const Mat4& _m, const Vec3& _t);
Mat4  Rotate(const Mat4& _m, const Vec3& _axis, float _rads); // _angle must be unit length
Mat4  LookAt(const Vec3& _from, const Vec3& _to, const Vec3& _up = Vec3(0.0f, 1.0f, 0.0f)); // aligns +z with (_to - _from)
} // namespace Im3d

#endif // im3d_math_h
