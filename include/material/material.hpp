#pragma once

#include "geometry/geometry.hpp"
#include "texture.hpp"

class material
{
public:
    virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

class diffuse : public material
{
private:
    std::shared_ptr<texture> albedo;

public:
    diffuse() {}
    diffuse(const color& _a) : albedo(std::make_shared<solid_color>(_a)) {}
    diffuse(std::shared_ptr<texture> _a) : albedo(_a) {}

    virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const override;
};

class specular : public material
{
private:
    std::shared_ptr<texture> albedo;

public:
    specular() {}
    specular(const color& _a) : albedo(std::make_shared<solid_color>(_a)) {}
    specular(std::shared_ptr<texture> _a) : albedo(_a) {}

    virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const override;
};

class glossy : public material
{
    // sample from a distant sphere, distance is set to 1
private:
    std::shared_ptr<texture> albedo;
    double radius;

public:
    glossy() {}
    glossy(const color& _a, double _r) : albedo(std::make_shared<solid_color>(_a)), radius(_r) {}
    glossy(std::shared_ptr<texture> _a, double _r) : albedo(_a), radius(_r) {}

    virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const override;
};

class dielectric : public material
{
private:
    double index;   // outside / inside

public:
    dielectric() {}
    dielectric(double _i): index(_i) {}

    virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    static double reflectance(double cosine, double _i);      // Schlic Approximation
};

#include "material.inl"