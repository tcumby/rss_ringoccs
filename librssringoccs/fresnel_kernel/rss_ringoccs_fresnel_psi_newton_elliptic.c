#include <rss_ringoccs/include/rss_ringoccs_math.h>
#include <rss_ringoccs/include/rss_ringoccs_fresnel_kernel.h>

RSS_RINGOCCS_EXPORT double
rssringoccs_Double_Newton_Raphson_Fresnel_Ellipse(double k, double r,
                                                  double r0, double phi,
                                                  double phi0, double B,
                                                  double ecc, double peri,
                                                  double EPS,
                                                  unsigned char toler,
                                                  double rx, double ry,
                                                  double rz)
{
    double dphi;
    double D, factor, ecc_cos_factor, rho;
    double x, y, dx, dy;
    long i = 0;
    x = r0 * cos(phi);
    y = r0 * sin(phi);
    dx = x-rx;
    dy = y-ry;
    D = sqrt(dx*dx + dy*dy + rz*rz);

    ecc_cos_factor = 1.0 + ecc * rssringoccs_Double_Cos(phi - peri);
    factor = r * ecc_cos_factor;
    rho = r;
    dphi = rssringoccs_Double_Fresnel_dPsi_dPhi_Ellipse(k, rho, r0, phi, phi0,
                                                        B, D, ecc, peri);

    while(fabs(dphi) > EPS)
    {
        dphi  = rssringoccs_Double_Fresnel_dPsi_dPhi_Ellipse(k, rho, r0, phi,
                                                             phi0, B, D, ecc,
                                                             peri);
        phi  -= dphi/rssringoccs_Double_Fresnel_d2Psi_dPhi2(k, rho, r0, phi,
                                                            phi0, B, D);
        ++i;
        if (i > toler)
            break;

        x = r0 * cos(phi);
        y = r0 * sin(phi);
        dx = x-rx;
        dy = y-ry;
        D = sqrt(dx*dx + dy*dy + rz*rz);
        ecc_cos_factor = 1.0 + ecc * rssringoccs_Double_Cos(phi - peri);
        rho = factor / ecc_cos_factor;
    }
    return phi;
}
