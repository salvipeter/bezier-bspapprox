# bezier-bspapprox
Approximate a Bézier curve with a B-spline of lower degree.

Input:
- number of segments (`n`)
- degree (`d`)
- continuity between segments (`c`)

Note that `d > 2c` should hold.

The input curve is subdivided into the given number of segments, then each segment is degree-reduced optimally while retaining `c` derivatives at the endpoints.
The resulting Bézier curves are united into a single B-spline surface (with each inner knot having multiplicity `d-c`).

Uses [libgeom](https://github.com/salvipeter/libgeom), [bezier-extractions](https://github.com/salvipeter/bezier-extractions),
and [bezier-reduction](https://github.com/salvipeter/bezier-reduction).
