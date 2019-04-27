#ifndef MATH_CONSTANTS_H
#define MATH_CONSTANTS_H

/* Define Miscellaneous Constants. */
#define SQRT_PI_BY_8 0.626657068657750125603941
#define SQRT_PI_BY_2 1.2533141373155001
#define SQRT_2_BY_PI 0.7978845608028654
#define PI_BY_TWO 1.5707963267948966
#define ONE_PI 3.141592653589793
#define SQRT_2 1.4142135623730951

/*******************************************************************************
 *  Coefficients for Fresnel Sine and Fresnel Cosine.                          *
 ******************************************************************************/

/* Define Coefficients for the Fresnel Sine Taylor Expansion. */
#define FRESNEL_SINE_TAYLOR_00 0.3333333333333333
#define FRESNEL_SINE_TAYLOR_01 -0.023809523809523808
#define FRESNEL_SINE_TAYLOR_02 0.0007575757575757576
#define FRESNEL_SINE_TAYLOR_03 -1.3227513227513228e-05
#define FRESNEL_SINE_TAYLOR_04 1.4503852223150468e-07
#define FRESNEL_SINE_TAYLOR_05 -1.0892221037148573e-09
#define FRESNEL_SINE_TAYLOR_06 5.9477940136376354e-12
#define FRESNEL_SINE_TAYLOR_07 -2.466827010264457e-14
#define FRESNEL_SINE_TAYLOR_08 8.032735012415773e-17
#define FRESNEL_SINE_TAYLOR_09 -2.107855191442136e-19
#define FRESNEL_SINE_TAYLOR_10 4.5518467589282e-22
#define FRESNEL_SINE_TAYLOR_11 -8.230149299214221e-25
#define FRESNEL_SINE_TAYLOR_12 1.2641078988989164e-27
#define FRESNEL_SINE_TAYLOR_13 -1.669761793417372e-30
#define FRESNEL_SINE_TAYLOR_14 1.9169428621097826e-33
#define FRESNEL_SINE_TAYLOR_15 -1.9303572088151077e-36
#define FRESNEL_SINE_TAYLOR_16 1.7188560628017835e-39
#define FRESNEL_SINE_TAYLOR_17 -1.3630412617791397e-42
#define FRESNEL_SINE_TAYLOR_18 9.687280238870763e-46
#define FRESNEL_SINE_TAYLOR_19 -6.205657919637396e-49
#define FRESNEL_SINE_TAYLOR_20 3.601579309810126e-52
#define FRESNEL_SINE_TAYLOR_21 -1.9025412272898796e-55
#define FRESNEL_SINE_TAYLOR_22 9.186429502398686e-59
#define FRESNEL_SINE_TAYLOR_23 -4.070135277853256e-62
#define FRESNEL_SINE_TAYLOR_24 1.66058051345109e-65
#define FRESNEL_SINE_TAYLOR_25 6.259184116948712e-69
#define FRESNEL_SINE_TAYLOR_26 2.1862104229538858e-72

/* Define Coefficients for the Fresnel Sine Asymptotic Expansion. */
#define FRESNEL_SINE_ASYM_00 -0.5
#define FRESNEL_SINE_ASYM_01 -0.25
#define FRESNEL_SINE_ASYM_02 0.375
#define FRESNEL_SINE_ASYM_03 0.9375
#define FRESNEL_SINE_ASYM_04 -3.281250
#define FRESNEL_SINE_ASYM_05 -14.765625
#define FRESNEL_SINE_ASYM_06 81.210938
#define FRESNEL_SINE_ASYM_07 527.87109375

/* Define Coefficients for the Fresnel Cosine Taylor Expansion. */
#define FRESNEL_COSINE_TAYLOR_00 1.0
#define FRESNEL_COSINE_TAYLOR_01 -0.1
#define FRESNEL_COSINE_TAYLOR_02 0.004629629629629629
#define FRESNEL_COSINE_TAYLOR_03 -0.00010683760683760684
#define FRESNEL_COSINE_TAYLOR_04 1.4589169000933706e-06
#define FRESNEL_COSINE_TAYLOR_05 -1.3122532963802806e-08
#define FRESNEL_COSINE_TAYLOR_06 8.35070279514724e-11
#define FRESNEL_COSINE_TAYLOR_07 -3.9554295164585257e-13
#define FRESNEL_COSINE_TAYLOR_08 1.4483264643598138e-15
#define FRESNEL_COSINE_TAYLOR_09 -4.221407288807088e-18
#define FRESNEL_COSINE_TAYLOR_10 1.0025164934907719e-20
#define FRESNEL_COSINE_TAYLOR_11 -1.977064753877905e-23
#define FRESNEL_COSINE_TAYLOR_12 3.289260349175752e-26
#define FRESNEL_COSINE_TAYLOR_13 -4.678483515518486e-29
#define FRESNEL_COSINE_TAYLOR_14 5.754191643982172e-32
#define FRESNEL_COSINE_TAYLOR_15 -6.180307588222796e-35
#define FRESNEL_COSINE_TAYLOR_16 5.846755007468836e-38
#define FRESNEL_COSINE_TAYLOR_17 -4.908923964523423e-41
#define FRESNEL_COSINE_TAYLOR_18 3.6824935154611457e-44
#define FRESNEL_COSINE_TAYLOR_19 -2.483069097454912e-47
#define FRESNEL_COSINE_TAYLOR_20 1.513107949541217e-50
#define FRESNEL_COSINE_TAYLOR_21 -8.373419683872281e-54
#define FRESNEL_COSINE_TAYLOR_22 4.2267897541935526e-57
#define FRESNEL_COSINE_TAYLOR_23 -1.954102582324171e-60
#define FRESNEL_COSINE_TAYLOR_24 8.30461450592911e-64
#define FRESNEL_COSINE_TAYLOR_25 -3.255395462013028e-67
#define FRESNEL_COSINE_TAYLOR_26 1.1807618389115701e-70

/* Define Coefficients for the Fresnel Coine Asymptotic Expansion. */
#define FRESNEL_COSINE_ASYM_00 0.5
#define FRESNEL_COSINE_ASYM_01 -0.25
#define FRESNEL_COSINE_ASYM_02 -0.375
#define FRESNEL_COSINE_ASYM_03 0.9375
#define FRESNEL_COSINE_ASYM_04 3.281250
#define FRESNEL_COSINE_ASYM_05 -14.765625
#define FRESNEL_COSINE_ASYM_06 -81.210938
#define FRESNEL_COSINE_ASYM_07 527.87109375

/*******************************************************************************
 * Define Coefficients Used for the Rational Approximation of the              *
 * Fresnel Integrals using approximations from Mark. A. Heald.                 *
 * See Rational Approximations for the Fresnel Integrals,                      *
 * Mathematics of Computation, Vol. 44, No. 170 (Apr., 1985), pp. 459-461      *
 *                                                                             *
 * Heald defines the Fresnel Integrals as the integral of                      *
 * sin(pi/2 x^2) and cos(pi/2 x^2), whereas we adopt the definition of         *
 * the integral of sin(x^2) and cos(x^2). As such, a scale factor of           *
 * sqrt(2/pi) is multiplied to our coefficients, and a scale factor of         *
 * sqrt(pi/2) is multiplied to the final output.                               *
 ******************************************************************************/

/* Coefficients for up to 3 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_3_A00 1.00000

#define FRESNEL_HEALD_RATIONAL_EPS_3_B00 2.000000
#define FRESNEL_HEALD_RATIONAL_EPS_3_B01 2.524
#define FRESNEL_HEALD_RATIONAL_EPS_3_B02 1.886
#define FRESNEL_HEALD_RATIONAL_EPS_3_B03 0.803

#define FRESNEL_HEALD_RATIONAL_EPS_3_C00 1.00000
#define FRESNEL_HEALD_RATIONAL_EPS_3_C01 0.506

#define FRESNEL_HEALD_RATIONAL_EPS_3_D00 1.4142135623730951
#define FRESNEL_HEALD_RATIONAL_EPS_3_D01 2.054
#define FRESNEL_HEALD_RATIONAL_EPS_3_D02 1.79

/* Coefficients for up to 4 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_4_A00 1.00000
#define FRESNEL_HEALD_RATIONAL_EPS_4_A01 0.1765

#define FRESNEL_HEALD_RATIONAL_EPS_4_B00 2.0000
#define FRESNEL_HEALD_RATIONAL_EPS_4_B01 2.915
#define FRESNEL_HEALD_RATIONAL_EPS_4_B02 2.079
#define FRESNEL_HEALD_RATIONAL_EPS_4_B03 1.519

#define FRESNEL_HEALD_RATIONAL_EPS_4_C00 1.00000
#define FRESNEL_HEALD_RATIONAL_EPS_4_C01 0.5083
#define FRESNEL_HEALD_RATIONAL_EPS_4_C02 0.3569

#define FRESNEL_HEALD_RATIONAL_EPS_4_D00 1.4142135623730951
#define FRESNEL_HEALD_RATIONAL_EPS_4_D01 2.1416
#define FRESNEL_HEALD_RATIONAL_EPS_4_D02 1.8515
#define FRESNEL_HEALD_RATIONAL_EPS_4_D03 1.1021

/* Coefficients for up to 6 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_6_A00 1.00000
#define FRESNEL_HEALD_RATIONAL_EPS_6_A01 0.08218
#define FRESNEL_HEALD_RATIONAL_EPS_6_A02 0.15108

#define FRESNEL_HEALD_RATIONAL_EPS_6_B00 2.0000
#define FRESNEL_HEALD_RATIONAL_EPS_6_B01 2.7097
#define FRESNEL_HEALD_RATIONAL_EPS_6_B02 2.3185
#define FRESNEL_HEALD_RATIONAL_EPS_6_B03 1.2389
#define FRESNEL_HEALD_RATIONAL_EPS_6_B04 0.6561

#define FRESNEL_HEALD_RATIONAL_EPS_6_C00 1.00000
#define FRESNEL_HEALD_RATIONAL_EPS_6_C01 0.60427
#define FRESNEL_HEALD_RATIONAL_EPS_6_C02 0.41159
#define FRESNEL_HEALD_RATIONAL_EPS_6_C03 0.19170

#define FRESNEL_HEALD_RATIONAL_EPS_6_D00 1.4142135623730951
#define FRESNEL_HEALD_RATIONAL_EPS_6_D01 2.26794
#define FRESNEL_HEALD_RATIONAL_EPS_6_D02 2.15594
#define FRESNEL_HEALD_RATIONAL_EPS_6_D03 1.26057
#define FRESNEL_HEALD_RATIONAL_EPS_6_D04 0.60353

/* Coefficients for up to 8 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_8_A00 1.0000000
#define FRESNEL_HEALD_RATIONAL_EPS_8_A01 0.1945161
#define FRESNEL_HEALD_RATIONAL_EPS_8_A02 0.2363641
#define FRESNEL_HEALD_RATIONAL_EPS_8_A03 0.0683240
#define FRESNEL_HEALD_RATIONAL_EPS_8_A04 0.0241212

#define FRESNEL_HEALD_RATIONAL_EPS_8_B00 2.0000000
#define FRESNEL_HEALD_RATIONAL_EPS_8_B01 2.9355041
#define FRESNEL_HEALD_RATIONAL_EPS_8_B02 2.7570460
#define FRESNEL_HEALD_RATIONAL_EPS_8_B03 1.8757210
#define FRESNEL_HEALD_RATIONAL_EPS_8_B04 0.9781130
#define FRESNEL_HEALD_RATIONAL_EPS_8_B05 0.3566810
#define FRESNEL_HEALD_RATIONAL_EPS_8_B06 0.1182470

#define FRESNEL_HEALD_RATIONAL_EPS_8_C00 1.0000000
#define FRESNEL_HEALD_RATIONAL_EPS_8_C01 0.7769507
#define FRESNEL_HEALD_RATIONAL_EPS_8_C02 0.6460117
#define FRESNEL_HEALD_RATIONAL_EPS_8_C03 0.3460509
#define FRESNEL_HEALD_RATIONAL_EPS_8_C04 0.1339259
#define FRESNEL_HEALD_RATIONAL_EPS_8_C05 0.0433995

#define FRESNEL_HEALD_RATIONAL_EPS_8_D00 1.4142135623730951
#define FRESNEL_HEALD_RATIONAL_EPS_8_D01 2.5129806
#define FRESNEL_HEALD_RATIONAL_EPS_8_D02 2.7196741
#define FRESNEL_HEALD_RATIONAL_EPS_8_D03 1.9840524
#define FRESNEL_HEALD_RATIONAL_EPS_8_D04 1.0917325
#define FRESNEL_HEALD_RATIONAL_EPS_8_D05 0.4205217
#define FRESNEL_HEALD_RATIONAL_EPS_8_D06 0.13634704

/*******************************************************************************
 *  Coefficients for Kaiser-Bessel and Modified Kaiser-Bessel Functions.       *
 ******************************************************************************/

/* Taylor Expansion of Modified Kaiser-Bessel Function, alpha = 2.0 Pi */

/* Taylor Expansion of Modified Kaiser-Bessel Function, alpha = 2.5 Pi */
#define MODIFIED_KAISER_BESSEL_2_5_A00 0.0
#define MODIFIED_KAISER_BESSEL_2_5_A01 0.04145269257683473
#define MODIFIED_KAISER_BESSEL_2_5_A02 0.1598131551145829
#define MODIFIED_KAISER_BESSEL_2_5_A03 0.27383552414424717
#define MODIFIED_KAISER_BESSEL_2_5_A04 0.26393049748717506
#define MODIFIED_KAISER_BESSEL_2_5_A05 0.16280559997382046
#define MODIFIED_KAISER_BESSEL_2_5_A06 0.06974074939338591
#define MODIFIED_KAISER_BESSEL_2_5_A07 0.02194877573814514
#define MODIFIED_KAISER_BESSEL_2_5_A08 0.005288714199797866
#define MODIFIED_KAISER_BESSEL_2_5_A09 0.0010068965459573457
#define MODIFIED_KAISER_BESSEL_2_5_A10 0.00015527610283472333
#define MODIFIED_KAISER_BESSEL_2_5_A11 1.978969147626019e-05
#define MODIFIED_KAISER_BESSEL_2_5_A12 2.1193188594867417e-06
#define MODIFIED_KAISER_BESSEL_2_5_A13 1.9338793216440484e-07
#define MODIFIED_KAISER_BESSEL_2_5_A14 1.521573968755883e-08
#define MODIFIED_KAISER_BESSEL_2_5_A15 1.0428703568483377e-09
#define MODIFIED_KAISER_BESSEL_2_5_A16 6.282176430490713e-11
#define MODIFIED_KAISER_BESSEL_2_5_A17 3.352216487175118e-12
#define MODIFIED_KAISER_BESSEL_2_5_A18 1.595536776390232e-13
#define MODIFIED_KAISER_BESSEL_2_5_A19 6.815840023528809e-15

#endif