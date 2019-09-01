#ifndef RSS_RINGOCCS_MATH_CONSTANTS_H
#define RSS_RINGOCCS_MATH_CONSTANTS_H

/* Define Miscellaneous Constants. */
#define SQRT_ONE_BY_2_PI    0.3989422804014326779399461
#define SQRT_PI_BY_8        0.6266570686577501256039413
#define SQRT_PI_BY_2        1.2533141373155002512078830
#define SQRT_2_BY_PI        0.7978845608028653558798921
#define PI_BY_TWO           1.570796326794896619231321691639751440
#define PI_BY_FOUR          0.785398163397448309615660845819875721
#define ONE_PI              3.1415926535897932384626430
#define TWO_PI              6.2831853071795864769252870
#define SQRT_2              1.4142135623730950488016890
#define RCPR_EULER_E        0.3678794411714423215955238
#define SPEED_OF_LIGHT_KM   299792.4580

/*******************************************************************************
 *  Coefficients for Fresnel Sine and Fresnel Cosine.                          *
 ******************************************************************************/

/* Define Coefficients for the Fresnel Sine Taylor Expansion.                 */
#define FRESNEL_SINE_TAYLOR_00  0.33333333333333333333333333333
#define FRESNEL_SINE_TAYLOR_01 -2.38095238095238095238095238095e-2
#define FRESNEL_SINE_TAYLOR_02  7.57575757575757575757575757576e-4
#define FRESNEL_SINE_TAYLOR_03 -1.32275132275132275132275132275e-5
#define FRESNEL_SINE_TAYLOR_04  1.45038522231504687645038522232e-7
#define FRESNEL_SINE_TAYLOR_05 -1.08922210371485733804574384285e-9
#define FRESNEL_SINE_TAYLOR_06  5.94779401363763503681199154450e-12
#define FRESNEL_SINE_TAYLOR_07 -2.46682701026445692771004257606e-14
#define FRESNEL_SINE_TAYLOR_08  8.03273501241577360913984452289e-17
#define FRESNEL_SINE_TAYLOR_09 -2.10785519144213582486050800945e-19
#define FRESNEL_SINE_TAYLOR_10  4.55184675892820028624362194733e-22
#define FRESNEL_SINE_TAYLOR_11 -8.23014929921422135684449347133e-25
#define FRESNEL_SINE_TAYLOR_12  1.26410789889891635219506925867e-27
#define FRESNEL_SINE_TAYLOR_13 -1.66976179341737202698649397027e-30
#define FRESNEL_SINE_TAYLOR_14  1.91694286210978253077267196219e-33
#define FRESNEL_SINE_TAYLOR_15 -1.93035720881510785655551537411e-36
#define FRESNEL_SINE_TAYLOR_16  1.71885606280178362396819126766e-39
#define FRESNEL_SINE_TAYLOR_17 -1.36304126177913957635067836351e-42
#define FRESNEL_SINE_TAYLOR_18  9.68728023887076175384366004096e-46
#define FRESNEL_SINE_TAYLOR_19 -6.20565791963739670594197460729e-49
#define FRESNEL_SINE_TAYLOR_20  3.60157930981012591661339989697e-52
#define FRESNEL_SINE_TAYLOR_21 -1.90254122728987952723942026864e-55
#define FRESNEL_SINE_TAYLOR_22  9.18642950239868569596123672835e-59
#define FRESNEL_SINE_TAYLOR_23 -4.07013527785325672297810283986e-62
#define FRESNEL_SINE_TAYLOR_24  1.66058051345108993284425792700e-65
#define FRESNEL_SINE_TAYLOR_25 -6.25918411694871134024677459636e-69
#define FRESNEL_SINE_TAYLOR_26  2.18621042295388572102809768805e-72
#define FRESNEL_SINE_TAYLOR_27 -7.09571739181805357327043566663e-76
#define FRESNEL_SINE_TAYLOR_28  2.14564844309633852738645079818e-79
#define FRESNEL_SINE_TAYLOR_29 -6.05939744697137480782877578571e-83
#define FRESNEL_SINE_TAYLOR_30  1.60173329821314496897157652161e-86

/* Define Coefficients for the Fresnel Sine Asymptotic Expansion.             */
#define FRESNEL_SINE_ASYM_00    -0.50
#define FRESNEL_SINE_ASYM_01    -0.250
#define FRESNEL_SINE_ASYM_02     0.3750
#define FRESNEL_SINE_ASYM_03     0.93750
#define FRESNEL_SINE_ASYM_04    -3.281250
#define FRESNEL_SINE_ASYM_05    -14.7656250
#define FRESNEL_SINE_ASYM_06     81.21093750
#define FRESNEL_SINE_ASYM_07     527.871093750
#define FRESNEL_SINE_ASYM_08    -3959.0332031250
#define FRESNEL_SINE_ASYM_09    -33651.78222656250
#define FRESNEL_SINE_ASYM_10     319691.931152343750
#define FRESNEL_SINE_ASYM_11     3356765.2770996093750
#define FRESNEL_SINE_ASYM_12    -38602800.68664550781250
#define FRESNEL_SINE_ASYM_13    -482535008.583068847656250
#define FRESNEL_SINE_ASYM_14     6514222615.8714294433593750

/* Define Coefficients for the Fresnel Cosine Taylor Expansion.               */
#define FRESNEL_COSINE_TAYLOR_00    1.00000000000000000000000000000
#define FRESNEL_COSINE_TAYLOR_01   -0.100000000000000000000000000000
#define FRESNEL_COSINE_TAYLOR_02    4.62962962962962962962962962963e-3
#define FRESNEL_COSINE_TAYLOR_03   -1.06837606837606837606837606838e-4
#define FRESNEL_COSINE_TAYLOR_04    1.45891690009337068160597572362e-6
#define FRESNEL_COSINE_TAYLOR_05   -1.31225329638028050726463424876e-8
#define FRESNEL_COSINE_TAYLOR_06    8.35070279514723959168403612848e-11
#define FRESNEL_COSINE_TAYLOR_07   -3.95542951645852576339713723403e-13
#define FRESNEL_COSINE_TAYLOR_08    1.44832646435981372649642651246e-15
#define FRESNEL_COSINE_TAYLOR_09   -4.22140728880708823303144982434e-18
#define FRESNEL_COSINE_TAYLOR_10    1.00251649349077191670194893133e-20
#define FRESNEL_COSINE_TAYLOR_11   -1.97706475387790517483308832056e-23
#define FRESNEL_COSINE_TAYLOR_12    3.28926034917575173275247613225e-26
#define FRESNEL_COSINE_TAYLOR_13   -4.67848351551848577372630857707e-29
#define FRESNEL_COSINE_TAYLOR_14    5.75419164398217177219656443388e-32
#define FRESNEL_COSINE_TAYLOR_15   -6.18030758822279613746380577975e-35
#define FRESNEL_COSINE_TAYLOR_16    5.84675500746883629629795521967e-38
#define FRESNEL_COSINE_TAYLOR_17   -4.90892396452342296700208077293e-41
#define FRESNEL_COSINE_TAYLOR_18    3.68249351546114573519399405667e-44
#define FRESNEL_COSINE_TAYLOR_19   -2.48306909745491159103989919027e-47
#define FRESNEL_COSINE_TAYLOR_20    1.51310794954121709805375306783e-50
#define FRESNEL_COSINE_TAYLOR_21   -8.37341968387228154282667202938e-54
#define FRESNEL_COSINE_TAYLOR_22    4.22678975419355257583834431490e-57
#define FRESNEL_COSINE_TAYLOR_23   -1.95410258232417110409647625591e-60
#define FRESNEL_COSINE_TAYLOR_24    8.30461450592911058167783010711e-64
#define FRESNEL_COSINE_TAYLOR_25   -3.25539546201302778914022841136e-67
#define FRESNEL_COSINE_TAYLOR_26    1.18076183891157008799527066561e-70
#define FRESNEL_COSINE_TAYLOR_27   -3.97425272266506578576293667383e-74
#define FRESNEL_COSINE_TAYLOR_28    1.24466597738907071212550309576e-77
#define FRESNEL_COSINE_TAYLOR_29   -3.63615636540051474579195169158e-81
#define FRESNEL_COSINE_TAYLOR_30    9.93207019544894768776342036501e-85

/* Define Coefficients for the Fresnel Cosine Asymptotic Expansion.           */
#define FRESNEL_COSINE_ASYM_00     0.50
#define FRESNEL_COSINE_ASYM_01    -0.250
#define FRESNEL_COSINE_ASYM_02    -0.3750
#define FRESNEL_COSINE_ASYM_03     0.93750
#define FRESNEL_COSINE_ASYM_04     3.281250
#define FRESNEL_COSINE_ASYM_05    -14.7656250
#define FRESNEL_COSINE_ASYM_06    -81.21093750
#define FRESNEL_COSINE_ASYM_07     527.871093750
#define FRESNEL_COSINE_ASYM_08     3959.0332031250
#define FRESNEL_COSINE_ASYM_09    -33651.78222656250
#define FRESNEL_COSINE_ASYM_10    -319691.931152343750
#define FRESNEL_COSINE_ASYM_11     3356765.2770996093750
#define FRESNEL_COSINE_ASYM_12     38602800.68664550781250
#define FRESNEL_COSINE_ASYM_13    -482535008.583068847656250
#define FRESNEL_COSINE_ASYM_14    -6514222615.8714294433593750

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
#define FRESNEL_HEALD_RATIONAL_EPS_3_A00 1.0

#define FRESNEL_HEALD_RATIONAL_EPS_3_B00 2.0
#define FRESNEL_HEALD_RATIONAL_EPS_3_B01 2.524
#define FRESNEL_HEALD_RATIONAL_EPS_3_B02 1.886
#define FRESNEL_HEALD_RATIONAL_EPS_3_B03 0.803

#define FRESNEL_HEALD_RATIONAL_EPS_3_C00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_3_C01 0.506

#define FRESNEL_HEALD_RATIONAL_EPS_3_D00 SQRT_2
#define FRESNEL_HEALD_RATIONAL_EPS_3_D01 2.054
#define FRESNEL_HEALD_RATIONAL_EPS_3_D02 1.79

/* Coefficients for up to 4 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_4_A00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_4_A01 0.1765

#define FRESNEL_HEALD_RATIONAL_EPS_4_B00 2.0
#define FRESNEL_HEALD_RATIONAL_EPS_4_B01 2.915
#define FRESNEL_HEALD_RATIONAL_EPS_4_B02 2.079
#define FRESNEL_HEALD_RATIONAL_EPS_4_B03 1.519

#define FRESNEL_HEALD_RATIONAL_EPS_4_C00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_4_C01 0.5083
#define FRESNEL_HEALD_RATIONAL_EPS_4_C02 0.3569

#define FRESNEL_HEALD_RATIONAL_EPS_4_D00 SQRT_2
#define FRESNEL_HEALD_RATIONAL_EPS_4_D01 2.1416
#define FRESNEL_HEALD_RATIONAL_EPS_4_D02 1.8515
#define FRESNEL_HEALD_RATIONAL_EPS_4_D03 1.1021

/* Coefficients for up to 6 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_6_A00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_6_A01 0.08218
#define FRESNEL_HEALD_RATIONAL_EPS_6_A02 0.15108

#define FRESNEL_HEALD_RATIONAL_EPS_6_B00 2.0
#define FRESNEL_HEALD_RATIONAL_EPS_6_B01 2.7097
#define FRESNEL_HEALD_RATIONAL_EPS_6_B02 2.3185
#define FRESNEL_HEALD_RATIONAL_EPS_6_B03 1.2389
#define FRESNEL_HEALD_RATIONAL_EPS_6_B04 0.6561

#define FRESNEL_HEALD_RATIONAL_EPS_6_C00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_6_C01 0.60427
#define FRESNEL_HEALD_RATIONAL_EPS_6_C02 0.41159
#define FRESNEL_HEALD_RATIONAL_EPS_6_C03 0.19170

#define FRESNEL_HEALD_RATIONAL_EPS_6_D00 SQRT_2
#define FRESNEL_HEALD_RATIONAL_EPS_6_D01 2.26794
#define FRESNEL_HEALD_RATIONAL_EPS_6_D02 2.15594
#define FRESNEL_HEALD_RATIONAL_EPS_6_D03 1.26057
#define FRESNEL_HEALD_RATIONAL_EPS_6_D04 0.60353

/* Coefficients for up to 8 significant digits. */
#define FRESNEL_HEALD_RATIONAL_EPS_8_A00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_8_A01 0.1945161
#define FRESNEL_HEALD_RATIONAL_EPS_8_A02 0.2363641
#define FRESNEL_HEALD_RATIONAL_EPS_8_A03 0.0683240
#define FRESNEL_HEALD_RATIONAL_EPS_8_A04 0.0241212

#define FRESNEL_HEALD_RATIONAL_EPS_8_B00 2.0
#define FRESNEL_HEALD_RATIONAL_EPS_8_B01 2.9355041
#define FRESNEL_HEALD_RATIONAL_EPS_8_B02 2.7570460
#define FRESNEL_HEALD_RATIONAL_EPS_8_B03 1.8757210
#define FRESNEL_HEALD_RATIONAL_EPS_8_B04 0.9781130
#define FRESNEL_HEALD_RATIONAL_EPS_8_B05 0.3566810
#define FRESNEL_HEALD_RATIONAL_EPS_8_B06 0.1182470

#define FRESNEL_HEALD_RATIONAL_EPS_8_C00 1.0
#define FRESNEL_HEALD_RATIONAL_EPS_8_C01 0.7769507
#define FRESNEL_HEALD_RATIONAL_EPS_8_C02 0.6460117
#define FRESNEL_HEALD_RATIONAL_EPS_8_C03 0.3460509
#define FRESNEL_HEALD_RATIONAL_EPS_8_C04 0.1339259
#define FRESNEL_HEALD_RATIONAL_EPS_8_C05 0.0433995

#define FRESNEL_HEALD_RATIONAL_EPS_8_D00 SQRT_2
#define FRESNEL_HEALD_RATIONAL_EPS_8_D01 2.5129806
#define FRESNEL_HEALD_RATIONAL_EPS_8_D02 2.7196741
#define FRESNEL_HEALD_RATIONAL_EPS_8_D03 1.9840524
#define FRESNEL_HEALD_RATIONAL_EPS_8_D04 1.0917325
#define FRESNEL_HEALD_RATIONAL_EPS_8_D05 0.4205217
#define FRESNEL_HEALD_RATIONAL_EPS_8_D06 0.13634704

/*******************************************************************************
 *  Coefficients for Kaiser-Bessel and Modified Kaiser-Bessel Functions.       *
 ******************************************************************************/

/* Taylor Expansion of Kaiser-Bessel Function, alpha = 2.0 Pi           */
#define KAISER_BESSEL_2_0_A00 0.011479934537958649
#define KAISER_BESSEL_2_0_A01 0.1133024124400544
#define KAISER_BESSEL_2_0_A02 0.2795624971181006
#define KAISER_BESSEL_2_0_A03 0.3065745835484819
#define KAISER_BESSEL_2_0_A04 0.18911061619076458
#define KAISER_BESSEL_2_0_A05 0.07465787879396363
#define KAISER_BESSEL_2_0_A06 0.020467881364469424
#define KAISER_BESSEL_2_0_A07 0.0041226508570559655
#define KAISER_BESSEL_2_0_A08 0.000635764578796162
#define KAISER_BESSEL_2_0_A09 7.746598623386816e-05
#define KAISER_BESSEL_2_0_A10 7.645586386685128e-06
#define KAISER_BESSEL_2_0_A11 6.236273805862515e-07
#define KAISER_BESSEL_2_0_A12 4.274274680606872e-08
#define KAISER_BESSEL_2_0_A13 2.4961775265788396e-09
#define KAISER_BESSEL_2_0_A14 1.2569533011338195e-10
#define KAISER_BESSEL_2_0_A15 5.513614147926286e-12
#define KAISER_BESSEL_2_0_A16 2.1256715023547588e-13
#define KAISER_BESSEL_2_0_A17 7.259355299277078e-15
#define KAISER_BESSEL_2_0_A18 2.211326080580753e-16
#define KAISER_BESSEL_2_0_A19 6.0456824424220165e-18

/* Taylor Expansion of Kaiser-Bessel Function, alpha = 2.5 Pi           */
#define KAISER_BESSEL_2_5_A00 0.0026808168640244153
#define KAISER_BESSEL_2_5_A01 0.04134156549951553
#define KAISER_BESSEL_2_5_A02 0.15938472531325876
#define KAISER_BESSEL_2_5_A03 0.2731014212531523
#define KAISER_BESSEL_2_5_A04 0.26322294815858105
#define KAISER_BESSEL_2_5_A05 0.162369147975853
#define KAISER_BESSEL_2_5_A06 0.06955378721630241
#define KAISER_BESSEL_2_5_A07 0.021889935090001627
#define KAISER_BESSEL_2_5_A08 0.005274536125582042
#define KAISER_BESSEL_2_5_A09 0.0010041972407166151
#define KAISER_BESSEL_2_5_A10 0.000154859836039664
#define KAISER_BESSEL_2_5_A11 1.9736638937616786e-05
#define KAISER_BESSEL_2_5_A12 2.113637353747984e-06
#define KAISER_BESSEL_2_5_A13 1.9286949453455966e-07
#define KAISER_BESSEL_2_5_A14 1.5174949076005814e-08
#define KAISER_BESSEL_2_5_A15 1.0400746124087073e-09
#define KAISER_BESSEL_2_5_A16 6.265335065973076e-11
#define KAISER_BESSEL_2_5_A17 3.3432298086844375e-12
#define KAISER_BESSEL_2_5_A18 1.5912594344929138e-13
#define KAISER_BESSEL_2_5_A19 6.79756800465124e-15

/* Taylor Expansion of Kaiser-Bessel Function, alpha = 3.5 Pi           */
#define KAISER_BESSEL_3_5_A00 0.00013778278419510894
#define KAISER_BESSEL_3_5_A01 0.004164576068189577
#define KAISER_BESSEL_3_5_A02 0.031469268691757625
#define KAISER_BESSEL_3_5_A03 0.10568661393182287
#define KAISER_BESSEL_3_5_A04 0.199653001679257
#define KAISER_BESSEL_3_5_A05 0.24138577764787625
#define KAISER_BESSEL_3_5_A06 0.20266792454558846
#define KAISER_BESSEL_3_5_A07 0.12501576500342412
#define KAISER_BESSEL_3_5_A08 0.05904194441375394
#define KAISER_BESSEL_3_5_A09 0.022031875838972297
#define KAISER_BESSEL_3_5_A10 0.006659280649052617
#define KAISER_BESSEL_3_5_A11 0.0016634807926120695
#define KAISER_BESSEL_3_5_A12 0.0003491653516678355
#define KAISER_BESSEL_3_5_A13 6.244825099294023e-05
#define KAISER_BESSEL_3_5_A14 9.630305200628995e-06
#define KAISER_BESSEL_3_5_A15 1.2936993963905893e-06
#define KAISER_BESSEL_3_5_A16 1.5274579139620535e-07
#define KAISER_BESSEL_3_5_A17 1.5975234908213973e-08
#define KAISER_BESSEL_3_5_A18 1.4903150442069255e-09
#define KAISER_BESSEL_3_5_A19 1.2478050139307538e-10
#define KAISER_BESSEL_3_5_A20 9.42893360941288e-12
#define KAISER_BESSEL_3_5_A21 6.462489211738939e-13
#define KAISER_BESSEL_3_5_A22 4.0358062840165105e-14
#define KAISER_BESSEL_3_5_A23 2.305953168325849e-15
#define KAISER_BESSEL_3_5_A24 1.2100514663649333e-16

/* Taylor Expansion of Modified Kaiser-Bessel Function, alpha = 2.0 Pi */
#define MODIFIED_KAISER_BESSEL_2_0_A00 0.0
#define MODIFIED_KAISER_BESSEL_2_0_A01 0.11461822212692875
#define MODIFIED_KAISER_BESSEL_2_0_A02 0.28280912738724334
#define MODIFIED_KAISER_BESSEL_2_0_A03 0.3101349120365976
#define MODIFIED_KAISER_BESSEL_2_0_A04 0.19130680579799147
#define MODIFIED_KAISER_BESSEL_2_0_A05 0.07552489969848816
#define MODIFIED_KAISER_BESSEL_2_0_A06 0.020705580068223085
#define MODIFIED_KAISER_BESSEL_2_0_A07 0.0041705282483355645
#define MODIFIED_KAISER_BESSEL_2_0_A08 0.0006431478742912528
#define MODIFIED_KAISER_BESSEL_2_0_A09 7.836561840316314e-05
#define MODIFIED_KAISER_BESSEL_2_0_A10 7.73437652285948e-06
#define MODIFIED_KAISER_BESSEL_2_0_A11 6.308697237164968e-07
#define MODIFIED_KAISER_BESSEL_2_0_A12 4.323912917851643e-08
#define MODIFIED_KAISER_BESSEL_2_0_A13 2.5251662700565502e-09
#define MODIFIED_KAISER_BESSEL_2_0_A14 1.2715506190016593e-10
#define MODIFIED_KAISER_BESSEL_2_0_A15 5.5776451491140785e-12
#define MODIFIED_KAISER_BESSEL_2_0_A16 2.150357465289493e-13
#define MODIFIED_KAISER_BESSEL_2_0_A17 7.343660035756585e-15
#define MODIFIED_KAISER_BESSEL_2_0_A18 2.2370067718829393e-16
#define MODIFIED_KAISER_BESSEL_2_0_A19 6.1158924878234225e-18

/*  Taylor Expansion of Modified Kaiser-Bessel Function, alpha = 2.5 Pi       */
#define MODIFIED_KAISER_BESSEL_2_5_A00 0.0
#define MODIFIED_KAISER_BESSEL_2_5_A01 0.041452692576834725
#define MODIFIED_KAISER_BESSEL_2_5_A02 0.15981315511458288
#define MODIFIED_KAISER_BESSEL_2_5_A03 0.27383552414424717
#define MODIFIED_KAISER_BESSEL_2_5_A04 0.26393049748717506
#define MODIFIED_KAISER_BESSEL_2_5_A05 0.16280559997382044
#define MODIFIED_KAISER_BESSEL_2_5_A06 0.06974074939338591
#define MODIFIED_KAISER_BESSEL_2_5_A07 0.021948775738145136
#define MODIFIED_KAISER_BESSEL_2_5_A08 0.005288714199797865
#define MODIFIED_KAISER_BESSEL_2_5_A09 0.00100689654595734557
#define MODIFIED_KAISER_BESSEL_2_5_A10 0.00015527610283472333
#define MODIFIED_KAISER_BESSEL_2_5_A11 1.9789691476260185e-05
#define MODIFIED_KAISER_BESSEL_2_5_A12 2.1193188594867412e-06
#define MODIFIED_KAISER_BESSEL_2_5_A13 1.9338793216440484e-07
#define MODIFIED_KAISER_BESSEL_2_5_A14 1.5215739687558827e-08
#define MODIFIED_KAISER_BESSEL_2_5_A15 1.0428703568483375e-09
#define MODIFIED_KAISER_BESSEL_2_5_A16 6.282176430490712e-11
#define MODIFIED_KAISER_BESSEL_2_5_A17 3.3522164871751176e-12
#define MODIFIED_KAISER_BESSEL_2_5_A18 1.5955367763902318e-13
#define MODIFIED_KAISER_BESSEL_2_5_A19 6.815840023528808e-15

/*  Taylor Expansion of Modified Kaiser-Bessel Function, alpha = 3.5 Pi       */
#define MODIFIED_KAISER_BESSEL_3_5_A00 0.0
#define MODIFIED_KAISER_BESSEL_3_5_A01 0.004168021758044031
#define MODIFIED_KAISER_BESSEL_3_5_A02 0.03149530575725549
#define MODIFIED_KAISER_BESSEL_3_5_A03 0.1057740569962342
#define MODIFIED_KAISER_BESSEL_3_5_A04 0.1998181907191577
#define MODIFIED_KAISER_BESSEL_3_5_A05 0.24158549558109016
#define MODIFIED_KAISER_BESSEL_3_5_A06 0.20283560807447493
#define MODIFIED_KAISER_BESSEL_3_5_A07 0.12511920063434212
#define MODIFIED_KAISER_BESSEL_3_5_A08 0.05909079457893826
#define MODIFIED_KAISER_BESSEL_3_5_A09 0.022050104587783687
#define MODIFIED_KAISER_BESSEL_3_5_A10 0.0066647904093246595
#define MODIFIED_KAISER_BESSEL_3_5_A11 0.001664857124511483
#define MODIFIED_KAISER_BESSEL_3_5_A12 0.00034945424434023947
#define MODIFIED_KAISER_BESSEL_3_5_A13 6.249991947043988e-05
#define MODIFIED_KAISER_BESSEL_3_5_A14 9.638273129268495e-06
#define MODIFIED_KAISER_BESSEL_3_5_A15 1.2947697783002646e-06
#define MODIFIED_KAISER_BESSEL_3_5_A16 1.5287217031571764e-07
#define MODIFIED_KAISER_BESSEL_3_5_A17 1.5988452509224124e-08
#define MODIFIED_KAISER_BESSEL_3_5_A18 1.4915481021085422e-09
#define MODIFIED_KAISER_BESSEL_3_5_A19 1.248837423714232e-10
#define MODIFIED_KAISER_BESSEL_3_5_A20 9.436734927084671e-12
#define MODIFIED_KAISER_BESSEL_3_5_A21 6.467836150574203e-13
#define MODIFIED_KAISER_BESSEL_3_5_A22 4.039145432237046e-14
#define MODIFIED_KAISER_BESSEL_3_5_A23 2.30786106946797e-15
#define MODIFIED_KAISER_BESSEL_3_5_A24 1.211052639591872e-16

/*  Taylor Expansion of Bessel J_0(x).                                        */
#define BESSEL_J0_TAYLOR_00  1.0
#define BESSEL_J0_TAYLOR_01 -0.25
#define BESSEL_J0_TAYLOR_02  1.56250e-2
#define BESSEL_J0_TAYLOR_03 -4.34027777777777777777777777778e-4
#define BESSEL_J0_TAYLOR_04  6.78168402777777777777777777778e-6
#define BESSEL_J0_TAYLOR_05 -6.78168402777777777777777777778e-8
#define BESSEL_J0_TAYLOR_06  4.70950279706790123456790123457e-10
#define BESSEL_J0_TAYLOR_07 -2.40280754952443940539178634417e-12
#define BESSEL_J0_TAYLOR_08  9.38596699032984142731166540690e-15
#define BESSEL_J0_TAYLOR_09 -2.89690339207711155163940290337e-17
#define BESSEL_J0_TAYLOR_10  7.24225848019277887909850725841e-20
#define BESSEL_J0_TAYLOR_11 -1.49633439673404522295423703686e-22
#define BESSEL_J0_TAYLOR_12  2.59780277210771740096221707789e-25
#define BESSEL_J0_TAYLOR_13 -3.84290350903508491266600159451e-28
#define BESSEL_J0_TAYLOR_14  4.90166263907536340901275713585e-31
#define BESSEL_J0_TAYLOR_15 -5.44629182119484823223639681761e-34
#define BESSEL_J0_TAYLOR_16  5.31864435663559397679335626720e-37
#define BESSEL_J0_TAYLOR_17 -4.60090342269515049895619054256e-40
#define BESSEL_J0_TAYLOR_18  3.55007980146230748376249270259e-43
#define BESSEL_J0_TAYLOR_19 -2.45850401763317692781336059736e-46
#define BESSEL_J0_TAYLOR_20  1.53656501102073557988335037335e-49
#define BESSEL_J0_TAYLOR_21 -8.71068600351890918301219032512e-53
#define BESSEL_J0_TAYLOR_22  4.49932128280935391684513963074e-56
#define BESSEL_J0_TAYLOR_23 -2.12633330945621640682662553438e-59
#define BESSEL_J0_TAYLOR_24  9.22887721118149482129611777074e-63
#define BESSEL_J0_TAYLOR_25 -3.69155088447259792851844710830e-66
#define BESSEL_J0_TAYLOR_26  1.36521852236412645285445529153e-69
#define BESSEL_J0_TAYLOR_27 -4.68181934967121554476836519729e-73
#define BESSEL_J0_TAYLOR_28  1.49292708854311720177562665730e-76
#define BESSEL_J0_TAYLOR_29 -4.43795210625183472584906854132e-80
#define BESSEL_J0_TAYLOR_30  1.23276447395884297940251903925e-83

/*  Asympotic Expansion of Bessel J_0(x).                                     */
#define BESSEL_J0_ASYM_00  1.0
#define BESSEL_J0_ASYM_01  0.1250
#define BESSEL_J0_ASYM_02 -0.07031250
#define BESSEL_J0_ASYM_03 -0.07324218750
#define BESSEL_J0_ASYM_04  0.1121520996093750
#define BESSEL_J0_ASYM_05  0.2271080017089843750
#define BESSEL_J0_ASYM_06 -0.57250142097473144531250
#define BESSEL_J0_ASYM_07 -1.72772750258445739746093750
#define BESSEL_J0_ASYM_08  6.07404200127348303794860839844
#define BESSEL_J0_ASYM_09  24.3805296995560638606548309326
#define BESSEL_J0_ASYM_10 -110.017140269246738171204924583
#define BESSEL_J0_ASYM_11 -551.335896122020585607970133424

#endif