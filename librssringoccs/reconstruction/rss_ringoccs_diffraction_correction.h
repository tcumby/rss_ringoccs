/*  Include guard to avoid importing this file twice.                         */
#ifndef RSS_RINGOCCS_DIFFRACTION_FUNCTIONS_H
#define RSS_RINGOCCS_DIFFRACTION_FUNCTIONS_H

/*  Various functions, complex variables, and more found here.                */
#include <complex.h>

/*  Structure that contains all of the necessary data.                        */
typedef struct _dlpdataobj {
    complex double *T_in;
    double *rho_km_vals;
    double *F_km_vals;
    double *phi_rad_vals;
    double *kd_vals;
    double *B_rad_vals;
    double *D_km_vals;
    double *w_km_vals;
    double *f_sky_hz_vals;
    double *rho_dot_kms_vals;
    double *t_oet_spm_vals;
    double *t_ret_spm_vals;
    double *t_set_spm_vals;
    double *rho_corr_pole_km_vals;
    double *rho_corr_timing_km_vals;
    double *raw_tau_threshold_vals;
    double *phi_rl_rad_vals;
    double *p_norm_vals;
    double *phase_rad_vals;
    double ecc;
    double peri;
    double perturb[5];
    long start;
    long n_used;
    long arr_size;
    _Bool use_norm;
    _Bool use_fwd;
    _Bool use_fft;
    char *wtype;
    char *psitype;
    unsigned char order;
    unsigned char interp;
    unsigned char status;
    complex double *T_out;
} DLPObj;

/******************************************************************************
 *  Functions defined in _diffraction_functions.c                             *
 ******************************************************************************/
extern complex double
Fresnel_Transform_Double(double *x_arr, complex double *T_in, double *w_func,
                         double F, double dx, long n_pts, long center);

extern complex double
Fresnel_Transform_Norm_Double(double *x_arr, complex double *T_in,
                              double *w_func, double F, double dx, long n_pts,
                              long center);

extern complex double
Fresnel_Transform_Legendre_Even_Double(double *x_arr, complex double *T_in,
                                      double *w_func, double D, double *coeffs,
                                      double dx, double F, double kd,
                                      long n_pts, unsigned char order,
                                      long center);

extern complex double
Fresnel_Transform_Legendre_Norm_Even_Double(double *x_arr, complex double *T_in,
                                            double *w_func, double D,
                                            double *coeffs, double dx, double F,
                                            double kd, long n_pts,
                                            unsigned char order, long center);

extern complex double
Fresnel_Transform_Legendre_Odd_Double(double *x_arr, complex double *T_in,
                                      double *w_func, double D, double *coeffs,
                                      double dx, double F, double kd,
                                      long n_pts, unsigned char order,
                                      long center);

extern complex double
Fresnel_Transform_Legendre_Norm_Odd_Double(double *x_arr, complex double *T_in,
                                           double *w_func, double D,
                                           double *coeffs, double dx, double F,
                                           double kd, long n_pts,
                                           unsigned char order, long center);

extern complex double
Fresnel_Transform_Newton_Double(double *x_arr, double *phi_arr,
                                complex double *T_in, double *w_func,
                                double kD, double r, double B, double D,
                                double EPS, long toler, double dx, double F,
                                long n_pts, long center);

extern complex double
Fresnel_Transform_Newton_Norm_Double(double *x_arr, double *phi_arr,
                                     complex double *T_in, double *w_func,
                                     double kD, double r, double B, double D,
                                     double EPS, long toler, double dx,
                                     double F, long n_pts, long center);

extern complex double
Fresnel_Transform_Quadratic_Double(double *x_arr, double *phi_arr,
                                   complex double *T_in, double *w_func,
                                   double kD, double r, double B, double D,
                                   double EPS, long toler, double dx, double F,
                                   long n_pts, long center);

extern complex double
Fresnel_Transform_Quadratic_Norm_Double(double *x_arr, double *phi_arr,
                                        complex double *T_in, double *w_func,
                                        double kD, double r, double B, double D,
                                        double EPS, long toler, double dx,
                                        double F, long n_pts, long center);

extern complex double
Fresnel_Transform_Cubic_Double(double *x_arr, double *phi_arr,
                               complex double *T_in, double *w_func,
                               double kD, double r, double B, double D,
                               double EPS, long toler, double dx, double F,
                               long n_pts, long center);

extern complex double
Fresnel_Transform_Cubic_Norm_Double(double *x_arr, double *phi_arr,
                                    complex double *T_in, double *w_func,
                                    double kD, double r, double B, double D,
                                    double EPS, long toler, double dx,
                                    double F, long n_pts, long center);

extern complex double
Fresnel_Transform_Quartic_Double(double *x_arr, double *phi_arr,
                                 complex double *T_in, double *w_func,
                                 double kD, double r, double B, double D,
                                 double EPS, long toler, double dx, double F,
                                 long n_pts, long center);

extern complex double
Fresnel_Transform_Quartic_Norm_Double(double *x_arr, double *phi_arr,
                                      complex double *T_in, double *w_func,
                                      double kD, double r, double B, double D,
                                      double EPS, long toler, double dx,
                                      double F, long n_pts, long center);

extern complex double
Fresnel_Transform_Perturbed_Newton_Double(double *x_arr, double *phi_arr,
                                          complex double *T_in, double *w_func,
                                          double kD, double r, double B,
                                          double D, double EPS, long toler,
                                          double dx, double F, long n_pts,
                                          long center, double perturb[5]);

extern complex double
Fresnel_Transform_Perturbed_Newton_Norm_Double(double *x_arr, double *phi_arr,
                                               complex double *T_in,
                                               double *w_func, double kD,
                                               double r, double B, double D,
                                               double EPS, long toler,
                                               double dx, double F, long n_pts,
                                               long center, double perturb[5]);

extern complex double
Fresnel_Transform_Ellipse_Double(double *x_arr, double *phi_arr,
                                 complex double *T_in, double *w_func,
                                 double kD, double r, double B, double D,
                                 double EPS, long toler, double dx, double F,
                                 long n_pts, long center, double ecc,
                                 double peri);

extern complex double
Fresnel_Transform_Ellipse_Norm_Double(double *x_arr, double *phi_arr,
                                      complex double *T_in, double *w_func,
                                      double kD, double r, double B, double D,
                                      double EPS, long toler, double dx,
                                      double F, long n_pts, long center,
                                      double ecc, double peri);

/*  Functions that compute the Fresnel Transform on a DLPObj instance.        */
extern void DiffractionCorrectionFresnel(DLPObj *dlp);
extern void DiffractionCorrectionLegendre(DLPObj *dlp);
extern void DiffractionCorrectionNewton(DLPObj *dlp);
extern void DiffractionCorrectionPerturbedNewton(DLPObj *dlp);
extern void DiffractionCorrectionEllipse(DLPObj *dlp);
extern void DiffractionCorrectionSimpleFFT(DLPObj *dlp);

#endif