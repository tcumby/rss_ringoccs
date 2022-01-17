/*  Header file where the prototypes for these functions are defined.         */
#include <rss_ringoccs/include/rss_ringoccs_config.h>
#include "rss_ringoccs_math_private.h"

/*  Only compile if the user requested these algorithms.                      */
#if __RSS_RINGOCCS_USE_TRIG_ALGORITHMS__ != 0

#define SIN_TAYLOR_0_F  1.00000000F
#define SIN_TAYLOR_1_F -1.66666666e-1F

#define SIN_TAYLOR_0  1.0000000000000000
#define SIN_TAYLOR_1 -1.6666666666666667e-1
#define SIN_TAYLOR_2  8.3333333333333333e-3
#define SIN_TAYLOR_3 -1.9841269841269841e-4

#define SIN_TAYLOR_0_L  1.00000000000000000000000L
#define SIN_TAYLOR_1_L -1.66666666666666666666667e-1L
#define SIN_TAYLOR_2_L  8.33333333333333333333333e-3L
#define SIN_TAYLOR_3_L -1.98412698412698412698413e-4L
#define SIN_TAYLOR_4_L  2.75573192239858906525573e-6L

#define COS_TAYLOR_0_F  1.00000000F
#define COS_TAYLOR_1_F -5.00000000e-1F
#define COS_TAYLOR_2_F  4.16666666e-2F
#define COS_TAYLOR_3_F -1.38888888e-3F
#define COS_TAYLOR_4_F  2.48015873e-5F
#define COS_TAYLOR_5_F -2.75573192e-7F

#define COS_TAYLOR_0  1.0000000000000000
#define COS_TAYLOR_1 -5.0000000000000000e-1
#define COS_TAYLOR_2  4.1666666666666666e-2
#define COS_TAYLOR_3 -1.3888888888888888e-3
#define COS_TAYLOR_4  2.4801587301587301e-5
#define COS_TAYLOR_5 -2.7557319223985890e-7

#define COS_TAYLOR_0_L  1.00000000000000000000000L
#define COS_TAYLOR_1_L -5.00000000000000000000000e-1L
#define COS_TAYLOR_2_L  4.16666666666666666666667e-2L
#define COS_TAYLOR_3_L -1.38888888888888888888889e-3L
#define COS_TAYLOR_4_L  2.48015873015873015873016e-5L
#define COS_TAYLOR_5_L -2.75573192239858906525573e-7L

static const float rssringoccs_sinf_lookup_table[80] = {
    0.0000000000F, 0.00999983333F, 0.0199986666F, 0.0299955002F, 0.0399893341F,
    0.0499791692F, 0.0599640064F,  0.0699428473F, 0.0799146939F, 0.0898785491F,
    0.0998334166F, 0.109778300F,   0.119712207F,  0.129634142F,  0.139543114F,
    0.149438132F,  0.159318206F,   0.169182349F,  0.179029573F,  0.188858894F,
    0.198669330F,  0.208459899F,   0.218229623F,  0.227977523F,  0.237702626F,
    0.247403959F,  0.257080551F,   0.266731436F,  0.276355648F,  0.285952225F,
    0.295520206F,  0.305058636F,   0.314566560F,  0.324043028F,  0.333487092F,
    0.342897807F,  0.352274233F,   0.361615431F,  0.370920469F,  0.380188415F,
    0.389418342F,  0.398609327F,   0.407760453F,  0.416870802F,  0.425939465F,
    0.434965534F,  0.443948106F,   0.452886285F,  0.461779175F,  0.470625888F,
    0.479425538F,  0.488177246F,   0.496880137F,  0.505533341F,  0.514135991F,
    0.522687228F,  0.531186197F,   0.539632048F,  0.548023936F,  0.556361022F,
    0.564642473F,  0.572867460F,   0.581035160F,  0.589144757F,  0.597195441F,
    0.605186405F,  0.613116851F,   0.620985987F,  0.628793024F,  0.636537182F,
    0.644217687F,  0.651833771F,   0.659384671F,  0.666869635F,  0.674287911F,
    0.681638760F,  0.688921445F,   0.696135238F,  0.703279419F,  0.710353272F
};

static const double rssringoccs_sin_lookup_table[80] = {
    0.000000000000000000, 0.0099998333341666646, 0.019998666693333079,
    0.029995500202495660, 0.039989334186634159,  0.049979169270678328,
    0.059964006479444599, 0.069942847337532763,  0.079914693969172687,
    0.089878549198011049, 0.099833416646828152,  0.10977830083717480,
    0.11971220728891935,  0.12963414261969485,   0.13954311464423648,
    0.14943813247359922,  0.15931820661424596,   0.16918234906699601,
    0.17902957342582417,  0.18885889497650057,   0.19866933079506121,
    0.20845989984609957,  0.21822962308086931,   0.22797752353518839,
    0.23770262642713458,  0.24740395925452292,   0.25708055189215509,
    0.26673143668883112,  0.27635564856411373,   0.28595222510483553,
    0.29552020666133957,  0.30505863644344350,   0.31456656061611776,
    0.32404302839486834,  0.33348709214081439,   0.34289780745545134,
    0.35227423327508997,  0.36161543196496197,   0.37092046941298267,
    0.38018841512316142,  0.38941834230865049,   0.39860932798442289,
    0.40776045305957018,  0.41687080242921076,   0.42593946506599960,
    0.43496553411123021,  0.44394810696551976,   0.45288628537906829,
    0.46177917554148288,  0.47062588817115803,   0.47942553860420300,
    0.48817724688290749,  0.49688013784373671,   0.50553334120484696,
    0.51413599165311310,  0.52268722893065916,   0.53118619792088340,
    0.53963204873396924,  0.54802393679187355,   0.55636102291278377,
    0.56464247339503535,  0.57286746010048126,   0.58103516053730507,
    0.58914475794226951,  0.59719544136239205,   0.60518640573603956,
    0.61311685197343378,  0.62098598703655968,   0.62879302401846851,
    0.63653718222196794,  0.64421768723769105,   0.65183377102153668,
    0.65938467197147315,  0.66686963500369787,   0.67428791162814506,
    0.68163876002333416,  0.68892144511055133,   0.69613523862735674,
    0.70327941920041018,  0.71035327241760780
};

static const long double rssringoccs_sinl_lookup_table[80] = {
    0.0000000000000000000000000L, 0.00999983333416666468254244L,
    0.0199986666933330793664903L, 0.0299955002024956607685263L,
    0.0399893341866341594525468L, 0.0499791692706783287948650L,
    0.0599640064794445991990911L, 0.0699428473375327639765473L,
    0.0799146939691726873068763L, 0.0898785491980110496912540L,
    0.0998334166468281523068142L, 0.109778300837174808664949L,
    0.119712207288919359967351L,  0.129634142619694859541206L,
    0.139543114644236481717988L,  0.149438132473599221497725L,
    0.159318206614245963311463L,  0.169182349066996010157624L,
    0.179029573425824178341803L,  0.188858894976500577992851L,
    0.198669330795061215459413L,  0.208459899846099570608712L,
    0.218229623080869319951791L,  0.227977523535188395404617L,
    0.237702626427134588360792L,  0.247403959254522929596849L,
    0.257080551892155097353388L,  0.266731436688831128732287L,
    0.276355648564113733319670L,  0.285952225104835532683940L,
    0.295520206661339575105321L,  0.305058636443443501565643L,
    0.314566560616117766661758L,  0.324043028394868346700196L,
    0.333487092140814396781771L,  0.342897807455451349189635L,
    0.352274233275089976849913L,  0.361615431964961978037292L,
    0.370920469412982671845485L,  0.380188415123161428231182L,
    0.389418342308650491666312L,  0.398609327984422893593798L,
    0.407760453059570185972787L,  0.416870802429210766216919L,
    0.425939465065999602769721L,  0.434965534111230210420844L,
    0.443948106965519765241514L,  0.452886285379068290703275L,
    0.461779175541482889136643L,  0.470625888171158036181358L,
    0.479425538604203000273288L,  0.488177246882907494500130L,
    0.496880137843736714334459L,  0.505533341204846961813661L,
    0.514135991653113104677281L,  0.522687228930659167788378L,
    0.531186197920883403851869L,  0.539632048733969240994463L,
    0.548023936791873556182696L,  0.556361022912783775722543L,
    0.564642473395035357200945L,  0.572867460100481261190976L,
    0.581035160537305075842963L,  0.589144757942269513118112L,
    0.597195441362392051883546L,  0.605186405736039560372522L,
    0.613116851973433788615145L,  0.620985987036559680357444L,
    0.628793024018468513704178L,  0.636537182221967940237429L,
    0.644217687237691053672614L,  0.651833771021536681210128L,
    0.659384671971473153618004L,  0.666869635003697873732594L,
    0.674287911628145067483881L,  0.681638760023334166733242L,
    0.688921445110551339147756L,  0.696135238627356747019884L,
    0.703279419200410184367897L,  0.710353272417607809814029L
};

static const float rssringoccs_cosf_lookup_table[80] = {
    1.000000000F, 0.999950000F, 0.999800006F, 0.999550033F, 0.999200106F,
    0.998750260F, 0.998200539F, 0.997551000F, 0.996801706F, 0.995952733F,
    0.995004165F, 0.993956097F, 0.992808635F, 0.991561893F, 0.990215996F,
    0.988771077F, 0.987227283F, 0.985584766F, 0.983843692F, 0.982004235F,
    0.980066577F, 0.978030914F, 0.975897449F, 0.973666395F, 0.971337974F,
    0.968912421F, 0.966389978F, 0.963770896F, 0.961055438F, 0.958243875F,
    0.955336489F, 0.952333569F, 0.949235418F, 0.946042343F, 0.942754665F,
    0.939372712F, 0.935896823F, 0.932327345F, 0.928664635F, 0.924909059F,
    0.921060994F, 0.917120822F, 0.913088940F, 0.908965749F, 0.904751663F,
    0.900447102F, 0.896052497F, 0.891568288F, 0.886994922F, 0.882332858F,
    0.877582561F, 0.872744507F, 0.867819179F, 0.862807070F, 0.857708681F,
    0.852524522F, 0.847255111F, 0.841900975F, 0.836462649F, 0.830940679F,
    0.825335614F, 0.819648017F, 0.813878456F, 0.808027508F, 0.802095757F,
    0.796083798F, 0.789992231F, 0.783821665F, 0.777572718F, 0.771246014F,
    0.764842187F, 0.758361875F, 0.751805729F, 0.745174402F, 0.738468558F,
    0.731688868F, 0.724836010F, 0.717910669F, 0.710913538F, 0.703845315F
};

static const double rssringoccs_cos_lookup_table[80] = {
    1.00000000000000000, 0.99995000041666527, 0.99980000666657777,
    0.99955003374898751, 0.99920010666097794, 0.99875026039496624,
    0.99820053993520416, 0.99755100025327957, 0.99680170630261938,
    0.99595273301199425, 0.99500416527802576, 0.99395609795669685,
    0.99280863585386625, 0.99156189371478803, 0.99021599621263717,
    0.98877107793604228, 0.98722728337562694, 0.98558476690956070,
    0.98384369278812141, 0.98200423511727031, 0.98006657784124163,
    0.97803091472414824, 0.97589744933060548, 0.97366639500537483,
    0.97133797485202960, 0.96891242171064478, 0.96638997813451322,
    0.96377089636589051, 0.96105543831077094, 0.95824387551269716,
    0.95533648912560601, 0.95233356988571339, 0.94923541808244086,
    0.94604234352838697, 0.94275466552834622, 0.93937271284737892,
    0.93589682367793485, 0.93232734560603442, 0.92866463557651024,
    0.92490905985731304, 0.92106099400288508, 0.91712082281660510,
    0.91308894031230827, 0.90896574967488512, 0.90475166321996341,
    0.90044710235267692, 0.89605249752552524, 0.89156828819532893,
    0.88699492277928419, 0.88233285861012149, 0.87758256189037271,
    0.87274450764575126, 0.86781917967764990, 0.86280707051476101,
    0.85770868136382414, 0.85252452205950574, 0.84725511101341612,
    0.84190097516226874, 0.83646264991518693, 0.83094067910016349,
    0.82533561490967829, 0.81964801784547951, 0.81387845666253392,
    0.80802750831215187, 0.80209575788429261, 0.79608379854905582,
    0.78999223149736509, 0.78382166588084928, 0.77757271875092793,
    0.77124601499710660, 0.76484218728448842, 0.75836187599050816,
    0.75180572914089497, 0.74517440234487038, 0.73846855872958790,
    0.73168886887382088, 0.72483601074090517, 0.71791066961094336,
    0.71091353801227735, 0.70384531565223609
};

static const long double rssringoccs_cosl_lookup_table[80] = {
    1.000000000000000000000000L, 0.999950000416665277780258L,
    0.999800006666577778412696L, 0.999550033748987516272159L,
    0.999200106660977940314571L, 0.998750260394966246562871L,
    0.998200539935204165547662L, 0.997551000253279574620908L,
    0.996801706302619384977707L, 0.995952733011994253092839L,
    0.995004165278025766095562L, 0.993956097956696850357840L,
    0.992808635853866252248098L, 0.991561893714788039594512L,
    0.990215996212637171898948L, 0.988771077936042286734981L,
    0.987227283375626949040953L, 0.985584766909560709171930L,
    0.983843692788121414592716L, 0.982004235117270318967878L,
    0.980066577841241631124197L, 0.978030914724148244916139L,
    0.975897449330605489406023L, 0.973666395005374836967731L,
    0.971337974852029604926175L, 0.968912421710644784144595L,
    0.966389978134513225558218L, 0.963770896365890513016233L,
    0.961055438310770947924590L, 0.958243875512697168070125L,
    0.955336489125606019642310L, 0.952333569885713397842805L,
    0.949235418082440867575307L, 0.946042343528386971529411L,
    0.942754665528346228502644L, 0.939372712847378920035032L,
    0.935896823677934858350912L, 0.932327345606034423203813L,
    0.928664635576510249492531L, 0.924909059857313041450677L,
    0.921060994002885082798527L, 0.917120822816605105475642L,
    0.913088940312308272436089L, 0.908965749674885122475910L,
    0.904751663219963417165537L, 0.900447102352676921668841L,
    0.896052497525525242536390L, 0.891568288195328936454019L,
    0.886994922779284194399955L, 0.882332858610121495705468L,
    0.877582561890372716116282L, 0.872744507645751263105808L,
    0.867819179677649900387848L, 0.862807070514761011806695L,
    0.857708681363824142537969L, 0.852524522059505742804982L,
    0.847255111013416126094526L, 0.841900975162268740133756L,
    0.836462649915186934657887L, 0.830940679100163495247997L,
    0.825335614909678297240952L, 0.819648017845479517900747L,
    0.813878456662533928684000L, 0.808027508312151872523709L,
    0.802095757884292613586111L, 0.796083798549055828917605L,
    0.789992231497365092783817L, 0.783821665880849285302942L,
    0.777572718750927937182394L, 0.771246014997106601973539L,
    0.764842187284488426255860L, 0.758361875990508166541458L,
    0.751805729140894979445487L, 0.745174402344870388790132L,
    0.738468558729587909791425L, 0.731688868873820886311839L,
    0.724836010740905172339688L, 0.717910669610943363371291L,
    0.710913538012277357216265L, 0.703845315652236096912781L
};

RSS_RINGOCCS_EXPORT float rssringoccs_sinf_table(unsigned int n)
{
    return rssringoccs_sinf_lookup_table[n];
}

RSS_RINGOCCS_EXPORT double rssringoccs_sin_table(unsigned int n)
{
    return rssringoccs_sin_lookup_table[n];
}

long double rssringoccs_sinl_table(unsigned int n)
{
    return rssringoccs_sinl_lookup_table[n];
}

RSS_RINGOCCS_EXPORT float rssringoccs_cosf_table(unsigned int n)
{
    return rssringoccs_cosf_lookup_table[n];
}

RSS_RINGOCCS_EXPORT double rssringoccs_cos_table(unsigned int n)
{
    return rssringoccs_cos_lookup_table[n];
}

long double rssringoccs_cosl_table(unsigned int n)
{
    return rssringoccs_cosl_lookup_table[n];
}

RSS_RINGOCCS_EXPORT float rssringoccs_do_sinf(float x)
{
    float x2, sin_x;
    x2 = x*x;

    sin_x = SIN_TAYLOR_1_F*x2 + SIN_TAYLOR_0_F;
    sin_x = x*sin_x;
    return sin_x;
}

RSS_RINGOCCS_EXPORT double rssringoccs_do_sin(double x)
{
    double x2, sin_x;

    x2 = x*x;

    sin_x = SIN_TAYLOR_3*x2 + SIN_TAYLOR_2;
    sin_x = x2*sin_x + SIN_TAYLOR_1;
    sin_x = x2*sin_x + SIN_TAYLOR_0;

    sin_x = x*sin_x;
    return sin_x;
}

long double rssringoccs_do_sinl(long double x)
{
    long double x2, sin_x;

    x2 = x*x;

    sin_x = SIN_TAYLOR_4_L*x2 + SIN_TAYLOR_3_L;
    sin_x = x2*sin_x + SIN_TAYLOR_2_L;
    sin_x = x2*sin_x + SIN_TAYLOR_1_L;
    sin_x = x2*sin_x + SIN_TAYLOR_0_L;

    sin_x = x*sin_x;
    return sin_x;
}

RSS_RINGOCCS_EXPORT float rssringoccs_do_cosf(float x)
{
    float x2, cos_x;
    x2 = x*x;

    cos_x = COS_TAYLOR_1_F*x2 + COS_TAYLOR_0_F;
    return cos_x;
}

RSS_RINGOCCS_EXPORT double rssringoccs_do_cos(double x)
{
    double x2, cos_x;

    x2 = x*x;

    cos_x = COS_TAYLOR_3*x2 + COS_TAYLOR_2;
    cos_x = x2*cos_x + COS_TAYLOR_1;
    cos_x = x2*cos_x + COS_TAYLOR_0;

    return cos_x;
}

long double rssringoccs_do_cosl(long double x)
{
    long double x2, cos_x;

    x2 = x*x;

    cos_x = COS_TAYLOR_4_L*x2 + COS_TAYLOR_3_L;
    cos_x = x2*cos_x + COS_TAYLOR_2_L;
    cos_x = x2*cos_x + COS_TAYLOR_1_L;
    cos_x = x2*cos_x + COS_TAYLOR_0_L;

    return cos_x;
}

#endif
/*  End of #if __RSS_RINGOCCS_USE_TRIG_ALGORITHMS__ != 0.                     */
