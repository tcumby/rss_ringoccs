/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of rss_ringoccs.                                        *
 *                                                                            *
 *  rss_ringoccs is free software: you can redistribute it and/or modify it   *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  rss_ringoccs is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with rss_ringoccs.  If not, see <https://www.gnu.org/licenses/>.    *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       December 31, 2020                                             *
 ******************************************************************************/

#include <stdlib.h>
#include <rss_ringoccs/include/rss_ringoccs_csv_tools.h>

/*  Macro for freeing and nullifying the members of the geo CSV structs.      */
#define DESTROY_DLP_VAR(var) if (var != NULL){free(var); var = NULL;}

/*  Free's all members of a rssringoccs_GeoCSV pointer except the             *
 *  error_message. Members are set to NULL after freeing.                     */
RSS_RINGOCCS_EXPORT void rssringoccs_Destroy_DLPCSV_Members(rssringoccs_DLPCSV *dlp)
{
    /*  If the pointer is NULL, there's nothing to do. Simply return.         */
    if (dlp == NULL)
        return;

    /*  Destroy every variable except the error_message.                      */
    DESTROY_DLP_VAR(dlp->rho_km_vals);
    DESTROY_DLP_VAR(dlp->rho_corr_pole_km_vals);
    DESTROY_DLP_VAR(dlp->rho_corr_timing_km_vals);
    DESTROY_DLP_VAR(dlp->phi_rl_deg_vals);
    DESTROY_DLP_VAR(dlp->phi_ora_deg_vals);
    DESTROY_DLP_VAR(dlp->p_norm_vals);
    DESTROY_DLP_VAR(dlp->raw_tau_vals);
    DESTROY_DLP_VAR(dlp->phase_deg_vals);
    DESTROY_DLP_VAR(dlp->raw_tau_threshold_vals);
    DESTROY_DLP_VAR(dlp->t_oet_spm_vals);
    DESTROY_DLP_VAR(dlp->t_ret_spm_vals);
    DESTROY_DLP_VAR(dlp->t_set_spm_vals);
    DESTROY_DLP_VAR(dlp->B_deg_vals);
}
/*  End of rssringoccs_Destroy_GeoCSV_Members.                                */
