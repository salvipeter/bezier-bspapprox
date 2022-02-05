#include <geometry.hh>           // https://github.com/salvipeter/libgeom

// Approximates a Bezier curve (given by cpts)
// with a B-spline of given degree and # of segments.
// The approximation works by first subdividing the original curve,
// then computing the optimal approximant on each segment
// with the given continuity at the endpoints,
// and finally uniting these in a single B-spline curve.
// Note that degree > 2 * continuity should hold.
Geometry::BSCurve approximate(const Geometry::PointVector &cpts, size_t degree,
                              size_t continuity, size_t segments);
