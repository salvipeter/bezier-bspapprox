#include <algorithm>

#include <Eigen/Dense>

#include <bezier-extractions.hh> // https://github.com/salvipeter/bezier-extractions
#include <geometry.hh>           // https://github.com/salvipeter/libgeom

extern "C" {
#include <reduction.h>           // https://github.com/salvipeter/bezier-reduction
}

using namespace Geometry;

BSCurve approximate(const PointVector &cpts, size_t degree, size_t continuity, size_t segments) {
  BSCurve curve(cpts);

  // Subdivide curve into segments (in Q)
  std::vector<PointVector> Q(segments);
  size_t n = cpts.size() - 1;
  for (size_t i = 1; i < segments; ++i)
    curve = curve.insertKnot((double)i / segments, n);
  for (size_t i = 0; i < segments; ++i)
    std::copy_n(curve.controlPoints().begin() + i * n, n + 1, std::back_inserter(Q[i]));

  // Compute best reduction for each segment (in Q1)
  std::vector<PointVector> Q1(segments);
  std::vector<double> M((degree + 1) * (n + 1));
  reduction_matrix(n, degree, continuity, continuity, &M[0]);
  for (size_t k = 0; k < segments; ++k) {
    for (size_t i = 0; i <= degree; ++i) {
      Point3D p(0, 0, 0);
      for (size_t j = 0; j <= n; ++j)
        p += Q[k][j] * M[i*(n+1)+j];
      Q1[k].push_back(p);
    }
  }

  if (segments == 1)
    return Q1[0];

  // Compute B-spline from segments
  DoubleVector knots;
  std::fill_n(std::back_inserter(knots), degree + 1, 0.0);
  for (size_t i = 1; i < segments; ++i)
    std::fill_n(std::back_inserter(knots), degree - continuity, (double)i / segments);
  std::fill_n(std::back_inserter(knots), degree + 1, 1.0);
  auto C = bezierExtractionMatrices(degree, knots);
  PointVector bs_cpts;
  for (size_t k = 0; k < knots.size() - degree - 1; ++k) {
    Point3D p(0, 0, 0);
    size_t i = k <= degree ? 0 : (k - degree - 1) / (degree - continuity) + 1;
    auto Cinv = C[i].inverse();
    for (size_t j = 0; j <= degree; ++j)
      p += Q1[i][j] * Cinv(j, k - i * (degree - continuity));
    bs_cpts.push_back(p);
  }
  return { degree, knots, bs_cpts };
}
