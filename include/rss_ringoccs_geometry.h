#ifndef _RSS_RINGOCCS_GEOMETRY_H_
#define _RSS_RINGOCCS_GEOMETRY_H_
#include "librssringoccs_exports.h"

/*  Data types for two and three dimensional points, respectively.            */
typedef struct rssringoccs_TwoVector {
    double dat[2];
} rssringoccs_TwoVector;

typedef struct rssringoccs_TwoByTwoMatrix {
    double dat[2][2];
} rssringoccs_TwoByTwoMatrix;

typedef struct rssringoccs_ThreeVector {
    double dat[3];
} rssringoccs_ThreeVector;

typedef struct rssringoccs_ThreeByThreeMatrix {
    double dat[3][3];
} rssringoccs_ThreeByThreeMatrix;

RSS_RINGOCCS_EXPORT extern double rssringoccs_TwoVector_X(rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern double rssringoccs_TwoVector_Y(rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector rssringoccs_TwoVector_Rect(double x, double y);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_TwoVector_Polar(double r, double theta);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_TwoByTwoMatrix_Component(rssringoccs_TwoByTwoMatrix A,
                                     unsigned int m, unsigned int n);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_TwoVector_Euclidean_Norm(rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_TwoVector_Euclidean_Norm_Squared(rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_TwoVector_Dot_Product(rssringoccs_TwoVector P,
                                  rssringoccs_TwoVector Q);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_TwoVector_Normalize(rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_TwoVector_Add(rssringoccs_TwoVector P, rssringoccs_TwoVector Q);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_TwoVector_Scale(double a, rssringoccs_TwoVector P);

RSS_RINGOCCS_EXPORT extern double rssringoccs_ThreeVector_X(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern double rssringoccs_ThreeVector_Y(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern double rssringoccs_ThreeVector_Z(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_ThreeByThreeMatrix_Component(rssringoccs_TwoByTwoMatrix A,
                                         unsigned int m, unsigned int n);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_ThreeVector_Rect(double x, double y, double z);

RSS_RINGOCCS_EXPORT extern double rssringoccs_ThreeVector_Euclidean_Norm(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern double
rssringoccs_ThreeVector_Dot_Product(rssringoccs_ThreeVector P,
                                    rssringoccs_ThreeVector Q);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_ThreeVector_Normalize(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_Cross_Product(rssringoccs_ThreeVector P, rssringoccs_ThreeVector Q);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_ThreeVector_Add(rssringoccs_ThreeVector P,
                            rssringoccs_ThreeVector Q);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_ThreeVector_Scale(double a, rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_Orthogonal_ThreeVector(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_Inverse_Orthographic_Projection(rssringoccs_TwoVector P,
                                            rssringoccs_ThreeVector u);

RSS_RINGOCCS_EXPORT extern rssringoccs_ThreeVector
rssringoccs_Inverse_Orthographic_Projection_Torus(rssringoccs_TwoVector P,
                                                  double r, double R);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_Stereographic_Projection(rssringoccs_ThreeVector P);

RSS_RINGOCCS_EXPORT extern rssringoccs_TwoVector
rssringoccs_Stereographic_Projection_Torus(double u, double v,
                                           double r, double R);

#endif
/*  End of include guard: #ifndef _RSS_RINGOCCS_GEOMETRY_H_                   */
