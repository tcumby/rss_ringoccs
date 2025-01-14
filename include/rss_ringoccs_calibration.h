/*  Include guard to avoid importing this file twice.                         */
#ifndef __RSS_RINGOCCS_CALIBRATION_H__
#define __RSS_RINGOCCS_CALIBRATION_H__

#include <rss_ringoccs/include/rss_ringoccs_bool.h>

/*  Structure that contains all of the necessary data.                        */
typedef struct rssringoccs_DLPObj {
    double *rho_km_vals;
    double *phi_rad_vals;
    double *B_rad_vals;
    double *D_km_vals;
    double *f_sky_hz_vals;
    double *rho_dot_kms_vals;
    double *t_oet_spm_vals;
    double *t_ret_spm_vals;
    double *t_set_spm_vals;
    double *rho_corr_pole_km_vals;
    double *rho_corr_timing_km_vals;
    double *phi_rl_rad_vals;
    double *p_norm_vals;
    double *phase_rad_vals;
    double *raw_tau_threshold_vals;
    double *rx_km_vals;
    double *ry_km_vals;
    double *rz_km_vals;
    unsigned long arr_size;
    rssringoccs_Bool error_occurred;
    char *error_message;
} rssringoccs_DLPObj;

#endif
