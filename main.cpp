#include "output.h"
#include "geometry.h"
#include "ray.h"
#include "triangle.h"

int main()
{
	output::aboutMe();
	output::taskOfProgram();

	Point ray_a(0, 0), ray_b(0, 0);
	Point trngl_a(0, 0), trngl_b(0, 0), trngl_c(0, 0);
	Ray ray(ray_a, ray_b);
	Triangle trngl(trngl_a, trngl_b, trngl_c);

	get_ray(ray);
	get_triangle(trngl);

	geometry::IsIntersect(ray, trngl);

	output::bye();
}
