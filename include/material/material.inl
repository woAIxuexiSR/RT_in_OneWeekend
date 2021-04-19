#include "material.hpp"

bool diffuse::scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const
{
    direction out = random_hemisphere(rec.normal);
    while(srm::dot(out, out) < srm::EPS)
        out = random_hemisphere(rec.normal);

    scattered = ray(rec.p, out);
    attenuation = albedo;
    return true;
}

bool specular::scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const
{
    direction rdir = r.get_dir().normalize();
    direction out = rdir - rec.normal * (srm::dot(rdir, rec.normal) * 2);

    scattered = ray(rec.p, out);
    attenuation = albedo;
    return srm::dot(out, rec.normal) > 0;
}

bool glossy::scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const
{
    direction rdir = r.get_dir();
    direction out = rdir - rec.normal * (srm::dot(rdir, rec.normal) * 2);
    out = out.normalize() + random_sphere() * radius;

    if(srm::dot(out, rec.normal) < 0)
        return false;
    
    scattered = ray(rec.p, out);
    attenuation = albedo;
    return true;
}

bool dielectric::scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const
{
    attenuation = color(1.0, 1.0, 1.0);
    double refract_ratio = rec.front_face ? (1.0 / index) : index;

    direction rdir = r.get_dir().normalize();
    double cosine_theta = -srm::dot(rdir, rec.normal);
    
    direction out_perpendicular = (rdir + rec.normal * cosine_theta) * refract_ratio;
    double sine_theta_prime = srm::dot(out_perpendicular, out_perpendicular);

    if(sine_theta_prime > 1.0 || reflectance(cosine_theta, refract_ratio) > random_double())          // reflect
        scattered = ray(rec.p, rdir + rec.normal * (cosine_theta * 2));
    else        // refract
    {
        direction out_parallel = rec.normal * (-sqrt(1.0 - sine_theta_prime));
        scattered = ray(rec.p, out_perpendicular + out_parallel);
    }

    return true;
}

double dielectric::reflectance(double cosine, double _i)
{
    double r0 = (1 - _i) / (1 + _i);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}