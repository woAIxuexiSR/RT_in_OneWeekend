#include "pdf.hpp"

double cosine_pdf::value(const direction& dir) const
{
    double cosine = dot(normal, dir.normalize());
    return (cosine <= 0) ? 0 : cosine / PI;
}
    
direction cosine_pdf::generate() const
{
    direction dir = normal + random_sphere_surface();
    if(dir.length_square() < EPS) 
        dir = normal;
    return dir.normalize();
}

double geometry_pdf::value(const direction& dir) const
{
    return object->pdf_value(ray(pos, dir));
}

direction geometry_pdf::generate() const
{
    return object->random(pos);
}

double mixture_pdf::value(const direction& dir) const
{
    double ans = 0;
    for(const auto& p : pdf_list)
        ans += p->value(dir);

    int num = pdf_list.size();
    return (num == 0) ? 0 : ans / num;
}

direction mixture_pdf::generate() const
{
    int k = random_int(0, pdf_list.size() - 1);
    return pdf_list[k]->generate();
}

double gmm_pdf::value(const direction& dir) const
{
    return 0.0;
}

direction gmm_pdf::generate() const
{
    return direction();
}