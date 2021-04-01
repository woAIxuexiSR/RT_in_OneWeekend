#include "vector.hpp"

namespace srm
{
    /* vector definition */
#pragma region vec

    template <class T>
    double vec2<T>::length() const
    {
        return sqrt(x * x + y * y);
    }

    template <class T>
    vec2<T> vec2<T>::normalize() const
    {
        return (*this) / length();
    }

    template <class T>
    vec2<T> vec2<T>::operator-() const
    {
        return vec2<T>(-x, -y);
    }

    template <class T>
    T vec2<T>::dot(const vec2<T>& _a) const
    {
        return x * _a.x + y * _a.y;
    }

    template <class T>
    T vec2<T>::cross(const vec2<T>& _a) const
    {
        return x * _a.y - y * _a.x;
    }

    template <class T>
    vec2<T> vec2<T>::operator+(const vec2<T>& _a) const
    {
        return vec2<T>(x + _a.x, y + _a.y);
    }

    template <class T>
    vec2<T> vec2<T>::operator-(const vec2<T>& _a) const
    {
        return vec2<T>(x - _a.x, y - _a.y);
    }

    template <class T>
    vec2<T> vec2<T>::operator*(T _a) const
    {
        return vec2<T>(x * _a, y * _a);
    }

    template <class T>
    vec2<T> vec2<T>::operator/(T _a) const
    {
        return vec2<T>(x / _a, y / _a);
    }

    // vec3
    template <class T>
    double vec3<T>::length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    template <class T>
    vec3<T> vec3<T>::normalize() const
    {
        return (*this) / length();
    }

    template <class T>
    vec3<T> vec3<T>::operator-() const
    {
        return vec3<T>(-x, -y, -z);
    }

    template <class T>
    T vec3<T>::dot(const vec3<T>& _a) const
    {
        return x * _a.x + y * _a.y + z * _a.z;
    }

    template <class T>
    vec3<T> vec3<T>::cross(const vec3<T>& _a) const
    {
        return vec3<T>(y * _a.z - z * _a.y, z * _a.x - x * _a.z, x * _a.y - y * _a.x);
    }

    template <class T>
    vec3<T> vec3<T>::operator+(const vec3<T>& _a) const
    {
        return vec3<T>(x + _a.x, y + _a.y, z + _a.z);
    }

    template <class T>
    vec3<T> vec3<T>::operator-(const vec3<T>& _a) const
    {
        return vec3<T>(x - _a.x, y - _a.y, z - _a.z);
    }

    template <class T>
    vec3<T> vec3<T>::operator*(T _a) const
    {
        return vec3<T>(x * _a, y * _a, z * _a);
    }

    template <class T>
    vec3<T> vec3<T>::operator/(T _a) const
    {
        return vec3<T>(x / _a, y / _a, z / _a);
    }

    // vec4
    template <class T>
    double vec4<T>::length() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    template <class T>
    vec4<T> vec4<T>::normalize() const
    {
        return (*this) / length();
    }

    template <class T>
    vec4<T> vec4<T>::operator-() const
    {
        return vec4<T>(-x, -y, -z, -w);
    }

    template <class T>
    T vec4<T>::dot(const vec4<T>& _a) const
    {
        return x * _a.x + y * _a.y + z * _a.z + w * _a.w;
    }

    template <class T>
    vec4<T> vec4<T>::operator+(const vec4<T>& _a) const
    {
        return vec4<T>(x + _a.x, y + _a.y, z + _a.z, w + _a.w);
    }

    template <class T>
    vec4<T> vec4<T>::operator-(const vec4<T>& _a) const
    {
        return vec4<T>(x - _a.x, y - _a.y, z - _a.z, w - _a.w);
    }

    template <class T>
    vec4<T> vec4<T>::operator*(T _a) const
    {
        return vec4<T>(x * _a, y * _a, z * _a, w * _a);
    }

    template <class T>
    vec4<T> vec4<T>::operator/(T _a) const
    {
        return vec4<T>(x / _a, y / _a, z / _a, w / _a);
    }

#pragma endregion vec


    /* useful funcitons */
#pragma region utils

    template<class V>
    auto dot(const V& _a, const V& _b)
    {
        return _a.dot(_b);
    }

    template<class V>
    auto cross(const V& _a, const V& _b)
    {
        return _a.cross(_b);
    }

    template <class T>
    std::ostream& operator<<(std::ostream& os, const vec2<T>& _a)
    {
        os << "vec2(" << _a.x << ", " << _a.y << ")";
        return os;
    }

    template <class T>
    std::ostream& operator<<(std::ostream& os, const vec3<T>& _a)
    {
        os << "vec3(" << _a.x << ", " << _a.y << ", " << _a.z << ")";
        return os;
    }

    template <class T>
    std::ostream& operator<<(std::ostream& os, const vec4<T>& _a)
    {
        os << "vec4(" << _a.x << ", " << _a.y << ", " << _a.z << ", " << _a.w << ")";
        return os;
    }

#pragma endregion utils

}