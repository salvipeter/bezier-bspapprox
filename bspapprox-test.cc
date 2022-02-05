#include <fstream>

#include "bspapprox.hh"

using namespace Geometry;

void writeCurve(const BSCurve &curve, size_t resolution, std::string filename) {
  std::ofstream f(filename + ".txt");
  for (size_t i = 0; i <= resolution; ++i) {
    double u = (double)i / resolution;
    f << curve.eval(u) << std::endl;
  }
  f.close();
  f.open(filename + "-cpts.txt");
  for (const auto &cp : curve.controlPoints())
    f << cp << std::endl;
}

int main(int argc, char **argv) {
  PointVector cpts = {
    {0,3,0},{1,6,0},{5,5,0},{4,8,0},{9,9,0},{13,7,0},
    {15,4,0},{10,2,0},{11,0,0},{4,0,0},{2,2,0},{0,0,0}
  };
  size_t degree = 7, continuity = 2;
  writeCurve(BSCurve(cpts), 100, "/tmp/bezier");
  for (size_t i = 1; i <= 4; ++i) {
    auto curve = approximate(cpts, degree, continuity, i);
    writeCurve(curve, 100, std::string("/tmp/approx") + std::to_string(i));
  }
  return 0;
}
