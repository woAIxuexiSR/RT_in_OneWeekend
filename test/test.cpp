#include <iostream>
#include "math/vector.hpp"
#include "math/matrix.hpp"
#include "framebuffer.hpp"
#include "geometry/geometry.hpp"

using namespace std;
using namespace srm;

void math_test()
{
    mat3<float> a(vec3<float>(3, 4, 5), vec3<float>(1, 2, 4), vec3<float>(4, 3, 1));
    mat3<float> b(vec3<float>(3, 1, 5), vec3<float>(4, 2, 4), vec3<float>(1, 3, 1));
    vec3<float> c(1.1, 2.2, 3.3);

    mat4<float> d(vec4<float>(3, 4, 5, 6), vec4<float>(1, 2, 3, 3), vec4<float>(4, 3, 1, 2), vec4<float>(2, 3, 3, 5));
    mat4<float> e(vec4<float>(3, 4, 5, 6), vec4<float>(1, 2, 3, 3), vec4<float>(4, 3, 1, 2), vec4<float>(2, 4, 3, 5));
    vec4<float> f(1.1, 2.2, 3.3, 4.4);
    cout << d * f << endl;
}

void framebuffer_test()
{
    const int height = 256, width = 256;
    FrameBuffer fb(width, height);

    for (int j = height - 1; j >= 0; --j)
        for (int i = 0; i < width; ++i)
            fb.set_pixel(i, j, vec3<double>(255, 255, 255));

    fb.output("../images/test.ppm");
}

void geometry_test()
{
    sphere ball1(point(10.1, 10.1, 10.1), 10);
    ray r(point(0, 0, 0), direction(-1, -1, -1));

    hit_record rec;

    cout << (ball1.hit(r, rec) ? "YES" : "NO") << endl;
}

void draw_pic()
{
    const int height = 1024, width = 1024;
    FrameBuffer fb(width, height);

    point origin(0, 0, 0);
    direction horizontal(2.0, 0, 0);
    direction vertical(0, 2.0, 0);
    double focal_length = 1.0;
    point low_left = origin - horizontal / 2 - vertical / 2 - direction(0, 0, focal_length); 

    sphere ball(point(0, 0, -1), 0.5);

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
        {
            double u = (double) i / (width - 1);
            double v = (double) j / (height - 1);

            ray r(origin, low_left + horizontal * u + vertical * v);
            color result;

            hit_record rec;
            if(ball.hit(r, rec))
                result = (rec.normal + color(1.0)) / 2;
            else
            {
                double t = 0.5 * (r.get_dir().y + 1.0);
                result = color(1.0) * (1 - t) + color(0.5, 0.7, 1.0) * t;
            }

            fb.set_pixel(i, j, result);
        }

    fb.output("../images/test.ppm");
}

int main()
{
    //math_test();
    //framebuffer_test();
    //geometry_test();
    draw_pic();
    return 0;
}