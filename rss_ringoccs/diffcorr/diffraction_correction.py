# Import dependencies for the diffcorr module
import time
import numpy as np
from scipy.special import lambertw, iv
from rss_ringoccs.tools.write_history_dict import write_history_dict
from rss_ringoccs.tools.write_output_files import write_output_files

# Declare constant for the speed of light (km/s)
SPEED_OF_LIGHT_KM = 299792.4580

# Declare constants for multiples of pi.
TWO_PI = 6.283185307179586476925287
ONE_PI = 3.141592653589793238462643

# Declare constants for the reciprocal of e and the square root of 2.
RCPR_E = 0.3678794411714423215955238
SQRT_2 = 1.414213562373095048801689

# Declare constants for various Bessel function inputs (I_0(x)).
IV0_20 = 87.10850209627940
IV0_25 = 373.02058499037486
IV0_35 = 7257.7994923041760

# Dictionary containing regions of interest within the Saturnian Rings.
region_dict = {
    'all':             [1.0, 400000.0],
    'cringripples':    [77690.0, 77760.0],
    'encke':           [132900.0, 134200.0],
    'enckegap':        [132900.0, 134200.0],
    'janusepimetheus': [96200.0, 96800.0],
    'maxwell':         [87410.0, 87610.0],
    'maxwellringlet':  [87410.0, 87610.0],
    'titan':           [77870.0, 77930.0],
    'titanringlet':    [77870.0, 77930.0],
    'huygens':         [117650.0, 117950.0],
    'huygensringlet':  [117650.0, 117950.0]
}


class DiffractionCorrection(object):
    """
        Class:
            DiffractionCorrection
        Purpose:
            Perform diffraction correction for a ring occultation
            on a data set that is a near radially symmetric function
            of the ring radius, or ring intercept point (RIP).
        Arguments:
            NormDiff:
                The data set, usually an instance of the NormDiff
                class from the rss_ringoccs Calibration subpackage.
                This instance MUST contain the following attributes
                and MUST have the same names.
                    rho_km_vals:      Ring Radius (km)
                    phi_rad_vals:     Ring Azimuth Angle (Radians)
                    p_norm_vals:      Normalized Power
                    phase_rad_vals:   Phase (Radians)
                    B_rad_vals:       Elevation Angle (Radians)
                    D_km_vals:        RIP-Distance (km)
                    f_sky_hz_vals:    Sky Frequency (Hertz)
                    rho_dot_kms_vals: RIP-velocity (km/s)
                    history:          History dictionary
            res:
                Positive Float or Integer
                The requested resolution for processing (km). This
                must be a positive real number.
        Keywords:
            rng:
                List or String
                The requested range for diffraction correction.
                Preferred input is rng = [a,b]. Arrays are
                allowed and the range will be set as:
                    rng = [MIN(array), MAX(array)]
                Finally, certain strings containing a few of the
                regions of interests within the rings of Saturn
                are allowed. Permissable strings are:
                    'all'             [1.0, 400000.0]
                    'cringripples'    [77690.0, 77760.0]
                    'encke'           [132900.0, 134200.0]
                    'enckegap'        [132900.0, 134200.0]
                    'janusepimetheus' [96200.0, 96800.0]
                    'maxwell'         [87410.0, 87610.0]
                    'maxwellringlet'  [87410.0, 87610.0]
                    'titan'           [77870.0, 77930.0]
                    'titanringlet'    [77870.0, 77930.0]
                    'huygens'         [117650.0, 117950.0]
                    'huygensringlet'  [117650.0, 117950.0]
                Strings are neither case nor space sensitive.
                For other planets use rng = [a,b]. Default value
                is set to 'all' which processes [1, 400000]
                Values MUST be set in kilometers.
            wtype:
                String
                The requested tapering function for diffraction
                correction. A string with several allowed inputs:
                    'rect'      Rectangular Window.
                    'coss'      Squared Cosine Window.
                    'kb20'      Kaiser-Bessel 2.0 Window.
                    'kb25'      Kaiser-Bessel 2.5 Window.
                    'kb35'      Kaiser-Bessel 3.5 Window.
                    'kbmd20'    Modified kb20 Window.
                    'kbmd25'    Modified kb25 Window.
                The variable is neither case nor space sensitive.
                Default window is set to 'kb25'. See window_functions
                submodule for further documentation.
            fwd:
                Boolean
                A Boolean for determining whether or not
                forward modelling will be computed. This is good
                starting point for deciding if the diffraction
                correction is physically significant or valid. If
                the reconstruction is good, the forward model
                should reproduce the p_norm_vals attribute from
                the input NormDiff instance. Default is set to False.
            norm:
                Boolean
                A Boolean for determining whether or not the
                reconstructed complex transmittance is normalize
                by the window width. This normalization is the
                complex transmittance that is computed by using
                free space divided by the complex transmittance
                that is computed using free space weighted by the
                selected tapering function. Default is True.
            bfac:
                Boolean
                A Boolean for determining whether or not the
                'b' factor in the window width computation is
                used. This is equivalent to setting the Allen
                Deviation for the spacecraft to a positive value
                or to zero. If set to False, the Allen Deviation
                is assumed to be zero. If set to True the Allen
                Deviation is set to 2e-13, or whichever number you
                wish to specify in the sigma keyword (See below).
                Default is True.
            sigma:
                Positive Float
                The Allen deviation for the spacecraft. If the bfac
                keyword (See above) is set to False, this is ignored.
                If bfac is set to True, and sigma is NOT specified,
                then sigma=2e-13 will be used, which is the Allen
                deviation for Cassini with 1 second integration time.
                For spacecraft other than Cassini, you should provide
                the Allen deviation yourself. Default is sigma=2e-13
            fft:
                Boolean
                A Boolean for determining whether or not FFT's will
                be used for computing the complex transmittance. The
                use of FFT's assumes that the geometry of the system
                is such that the integral that is used to compute the
                complex transmittance is of the form of a
                convolution, and that the convolution theorem may be
                applied to it. Default is set to False.
            psitype:
                String
                A string for determining what approximation to the
                geometrical 'psi' function is used. Several strings
                are allowed:
                    'full'      No Approximation is applied.
                    'MTR2'      Second Order Series from MTR86.
                    'MTR3'      Third Order Series from MTR86.
                    'MTR4'      Fourth Order Series from MTR86.
                    'Fresnel'   Standard Fresnel approximation.
                The variable is neither case nor space sensitive.
                Default is set to 'full'.
            verbose:
                Boolean
                A Boolean for determining if various pieces of
                information are printed to the screen or not.
                Default is False.
        Attributes:
            bfac:
                Boolean for bfac (See keywords).
            dathist:
                History from NormDiff instance.
            dx_km:
                Radial spacing for the data points (km).
            f_sky_hz_vals:
                Recieved frequency from the spacecraft (Hz).
            fft:
                Boolean for fft (See keywords).
            finish:
                Final point that was reconstructed.
            fwd:
                Boolean for fwd (See keywords).
            history:
                History for the DiffractionCorrection class.
                This contains system info and user info, including
                what operating system was used, username, hostname,
                computer name, and the inputs provided.
            lambda_sky_km_vals:
                Wavelength of recieved signal from spacecraft (km).
            mu_vals:
                The sine of the ring opening angle (Unitless).
            n_used:
                Number of points that were reconstructed.
            norm:
                Boolean for norm (See keywords).
            norm_eq:
                Normalized equivalent width computed from window
                that was used during reconstruction. See the
                window_functions submodule for more information.
            p_norm_fwd_vals:
                Normalized power computer from the forward modelling
                of the reconstructed data. This will be a None type
                variable unless fwd=True is set. If the
                reconstruction went well, this should mimic the raw
                data, p_norm_vals.
            p_norm_vals:
                Normalized power from the diffracted signal. This is
                the square of the absolute value of the recieved
                complex transmittance.
            phase_fwd_vals:
                Phase computed from the forward model of the
                reconstructed data. This will be a None type
                variable unless fwd=True is set. If the
                reconstruction went well, this should mimic
                phase_rad_vals. This variable is in radians.
            phase_rad_vals:
                Phase from the diffracted signal (Radians).
            phase_vals:
                Reconstructed phase (Radians).
            phi_rad_vals:
                Ring azimuth angle of the ring intercept (Radians).
            phi_rl_rad_vals:
                Ring longitude angle. This will be a None type unless
                it was provided in the NormDiff class. Otherwise,
                this variable is in radians.
            power_vals:
                Normalized reconstructed power.
            psitype:
                String for psitype (See keywords).
            raw_tau_threshold_vals:
                Threshold optical depth for the diffracted data.
                This will be a None type unless provided for in the
                NormDiff class.
            res:
                Requested resolution (See arguments). In kilometers.
            rho_corr_pole_km_vals:
                Radial corrections from the Planet's pole. This will
                be a None type variable unless provided in the
                NormDiff class. Otherwise, this is in kilometers.
            rho_corr_timing_km_vals:
                Radial corrections from timing offsets. This will be
                a None type variable unless provided in the NormDiff
                class. Otherwise, this is in kilometers.
            rho_dot_kms_vals:
                Time derivative of the ring intercept point (km/s).
            rho_km_vals:
                Ring-intercept-point (RIP) in kilometers.
            rng:
                Range that was used for reconstruction, taking into
                the range that was requested by the user. The actual
                range takes into account limits in the available data
                and limits in the required window sizes.
            rngreq:
                Requested range (See keywords).
            sigma:
                Requested Allen deviation (See keywords).
            start:
                First point that was reconstructed.
            t_oet_spm_vals:
                Time the signal is measured on Earth. This is a
                None type unless provided for in the NormDiff class.
            t_ret_spm_vals:
                Time the signal passes through the diffracting
                medium. This is a None type unless provided for in
                the NormDiff class.
            t_set_spm_vals:
                Time the signal is emitted from the spacecraft. This
                is a None type unless provided in the NormDiff class.
            tau_threshold_vals:
                Threshold optical depth of the reconstructed data.
            tau_vals:
                Optical depth of the reconstructed data.
            verbose:
                Boolean for Verbose (See keywords).
            w_km_vals:
                Window width as a function of radius (km).
            wtype:
                String for wtype (See keywords).
        Dependencies:
            [1] numpy
            [2] scipy
            [3] rss_ringoccs
            [4] time
        Notes:
            [1]
        References:

        Examples:

        History:
            Created: RJM - 2018/05/16 5:40 P.M.
    """
    def __init__(self, NormDiff, res, rng="all", wtype="kb25", fwd=False,
                 norm=True, verbose=False, bfac=True, sigma=2.e-13,
                 fft=False, psitype="full", write_file=False):

        # Set a variable for the starting time of the computation.
        t1 = time.time()

        # Make sure that verbose is a boolean.
        if not isinstance(verbose, bool):
            raise TypeError(
                "\n\tverbose must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet verbose=True or verbose=False\n"
                % (type(verbose).__name__)
            )
        else:
            pass

        if verbose:
            print("Processing Diffraction Correction:")
            print("\tRunning Error Check on Input Arguments...")

        # Check that the input resolution is a positive floating point number.
        if (not isinstance(res, float)):
            try:
                res = float(res)
            except (TypeError, ValueError):
                raise TypeError(
                    "\n\tres must be a positive floating point number\n"
                    "\tYour input has type: %s\n"
                    "\tInput should have type: float\n"
                    % (type(res).__name__)
                )
        else:
            pass

        if (res <= 0.0):
            raise ValueError(
                "\n\tres must be a positive floating point number\n"
                "\tYour requested resolution (km): %f\n"
                % (res)
            )
        else:
            pass

        # Check that the requested window type is a legal input.
        if not isinstance(wtype, str):
            erm = ""
            for key in self.__func_dict:
                erm = "%s\t\t'%s'\n" % (erm, key)
            raise TypeError(
                "\n\twtype must be a string.\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: str\n"
                "\tAllowed string are:\n%s"
                % (type(wtype).__name__, erm)
            )
        else:
            # Remove spaces, quotes, and apostrophe's from the wtype variable.
            wtype = wtype.replace(" ", "").replace("'", "").replace('"', "")

            # Set wtype string to lower-case.
            wtype = wtype.lower()
            if not (wtype in self.__func_dict):
                erm = ""
                for key in self.__func_dict:
                    erm = "%s\t\t'%s'\n" % (erm, key)
                raise ValueError(
                    "\n\tIllegal string used for wtype.\n"
                    "\tYour string: '%s'\n"
                    "\tAllowed Strings:\n%s"
                    % (wtype, erm)
                )
            else:
                pass

        # Check that the forward boolean is valid.
        if not isinstance(fwd, bool):
            raise TypeError(
                "\n\tfwd must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet fwd=True or fwd=False\n"
                % (type(fwd).__name__)
            )
        else:
            pass

        # Ensure that the normalize boolean has a legal value.
        if not isinstance(norm, bool):
            raise TypeError(
                "\n\tnorm must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet norm=True or norm=False\n"
                % (type(norm).__name__)
            )
        else:
            pass

        # Make sure that bfac is a boolean.
        if not isinstance(bfac, bool):
            raise TypeError(
                "\n\tbfac must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet bfac=True or bfac=False\n"
                % (type(bfac).__name__)
            )
        else:
            pass

        # Check that the fft boolean is valid.
        if not isinstance(fft, bool):
            raise TypeError(
                "\n\tfft must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet fft=True or fft=False\n"
                % (type(fft).__name__)
            )
        else:
            pass

        # Check that the fft boolean is valid.
        if not isinstance(write_file, bool):
            raise TypeError(
                "\n\twrite_file must be Boolean: True/False\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: bool\n"
                "\tSet write_file=True or write_file=False\n"
                % (type(write_file).__name__)
            )
        else:
            pass

        # Cbeck that psitype is a valid string.
        if not isinstance(psitype, str):
            erm = ""
            for key in self.__psi_types:
                erm = "%s\t\t'%s'\n" % (erm, key)
            raise TypeError(
                "\n\tpsitype must be a string.\n"
                "\tYour input has type: %s\n"
                "\tInput should have type: str\n"
                "\tAllowed strings are:\n%s"
                % (type(psitype).__name__, erm)
            )
        else:
            # Remove spaces, quotes, and apostrophe's from the psitype.
            psitype = psitype.replace(" ", "").replace("'", "")
            psitype = psitype.replace('"', "").lower()

            # Perform error check, print legal inputs if needed.
            if not (psitype in self.__psi_types):
                erm = ""
                for key in self.__psi_types:
                    erm = "%s\t\t'%s'\n" % (erm, key)
                raise TypeError(
                    "\n\tInvalid string for psitype.\n"
                    "\tYour string: '%s'\n"
                    "\tAllowed strings are:\n%s"
                    % (psitype, erm)
                )
            else:
                pass

        # Check that the requested range is a legal input.
        if (not isinstance(rng, str)) and (not isinstance(rng, list)):
            try:
                if (np.size(rng) < 2):
                    erm = ""
                    for key in region_dict:
                        erm = "%s\t\t'%s'\n" % (erm, key)
                    raise TypeError(
                        "\n\trng must be a list or a valid string.\n"
                        "\tYour input has type: %s\n"
                        "\tSet range=[a,b], where a is the STARTING point\n"
                        "\tand b is the ENDING point of reconstruction, or\n"
                        "\tuse one of the following valid strings:\n%s"
                        % (type(rng).__name__, erm)
                    )
                elif (np.min(rng) < 0):
                    raise ValueError(
                        "\n\tMinimum requested range must be positive\n"
                        "\tYour minimum requested range: %f\n"
                        % (np.min(rng))
                    )
                else:
                    rng = [np.min(rng), np.max(rng)]
            except TypeError:
                erm = ""
                for key in region_dict:
                    erm = "%s\t\t'%s'\n" % (erm, key)
                raise TypeError(
                    "\n\trng must be a list of floating\n"
                    "\tpoint numbers or a valid string.\n"
                    "\tYour input has type: %s\n"
                    "\tSet range=[a,b], where a is the STARTING point\n"
                    "\tand b is the ENDING point of reconstruction, or\n"
                    "\tuse one of the following valid strings:\n%s"
                    % (type(rng).__name__, erm)
                )
        elif isinstance(rng, list):
            # Try converting all elements to floating point numbers.
            if (not all(isinstance(x, float) for x in rng)):
                try:
                    for i in np.arange(np.size(rng)):
                        rng[i] = float(rng[i])
                except (TypeError, ValueError):
                    erm = ""
                    for key in region_dict:
                        erm = "%s\t\t'%s'\n" % (erm, key)
                    raise TypeError(
                        "\n\trng must be a list of floating\n"
                        "\tpoint numbers or a valid string.\n"
                        "\tYour input has type: %s\n"
                        "\tSet range=[a,b], where a is the STARTING point\n"
                        "\tand b is the ENDING point of reconstruction, or\n"
                        "\tuse one of the following valid strings:\n%s"
                        % (type(rng).__name__, erm)
                    )
            else:
                pass

            # Check that there are at least two numbers.
            if (np.size(rng) < 2):
                erm = ""
                for key in region_dict:
                    erm = "%s\t\t'%s'\n" % (erm, key)
                raise TypeError(
                    "\n\trng must contain two numbers: rng=[a,b]\n"
                    "\tYou provided less than 2 numbers.\n"
                    "\tSet range=[a,b], where a is the STARTING point\n"
                    "\tand b is the ENDING point of reconstruction, or\n"
                    "\tuse one of the following valid strings:\n%s"
                    % (erm)
                )
            else:
                pass

            # Check that the smallest number is positive.
            if (np.min(rng) < 0.0):
                raise ValueError(
                    "\n\tMinimum requested range must be positive\n"
                    "\tYour minimum requested range: %f\n"
                    % (np.min(rng))
                )
            else:
                pass
        elif isinstance(rng, str):
            rng = rng.replace(" ", "").replace("'", "").replace('"', "")
            rng = rng.lower()
            if not (rng in region_dict):
                erm = ""
                for key in region_dict:
                    erm = "%s\t\t'%s'\n" % (erm, key)
                raise ValueError(
                    "\n\tIllegal string used for rng.\n"
                    "\tYour string: '%s'\n"
                    "\tAllowed Strings:\n%s"
                    % (rng, erm)
                )
        else:
            erm = ""
            for key in region_dict:
                erm = "%s\t\t'%s'\n" % (erm, key)
            raise TypeError(
                "\n\trng must be a list of floating\n"
                "\tpoint numbers or a valid string.\n"
                "\tYour input has type: %s\n"
                "\tSet range=[a,b], where a is the STARTING point\n"
                "\tand b is the ENDING point of reconstruction, or\n"
                "\tuse one of the following valid strings:\n%s"
                % (type(rng).__name__, erm)
            )

        # Check that the Allen Deviation is a legal value.
        if (not isinstance(sigma, float)):
            try:
                sigma = float(sigma)
            except (TypeError, ValueError):
                raise TypeError(
                    "\n\tsigma must be a positive floating point number.\n"
                    "\tYour input has type: %s\n"
                    % (type(sigma).__name__)
                )
        else:
            pass

        if (np.min(sigma) <= 0.0):
                raise ValueError(
                    "\n\tsigma must be a positive floating point number.\n"
                    "\tYour input: %f\n"
                    % (sigma)
                )
        else:
            pass

        if verbose:
            print("\tAssigning Inputs as Attributes...")

        # Set forward power variable to None in case it isn't defined later.
        self.p_norm_fwd_vals = None

        # Set forward phase and power to None as well.
        self.T_hat_fwd_vals = None
        self.phase_fwd_vals = None

        # Assign resolution, forward, and FFT variables as attributes.
        self.res = res
        self.fwd = fwd
        self.fft = fft

        # Assing window type and Allen deviation variables as attributes.
        self.wtype = wtype
        self.sigma = sigma

        # Assign normalization and b-factor variables as attributes.
        self.norm = norm
        self.bfac = bfac

        # Assign requested range variable as an attribute.
        self.rngreq = rng

        # Assign verbose and psi approximation variables as attributes.
        self.verbose = verbose
        self.psitype = psitype

        # Retrieve variables from the NormDiff class, setting as attributes.
        if verbose:
            print("\tRetrieving Variables from NormDiff Instance...")

        try:
            # Ring radius
            self.rho_km_vals = np.array(NormDiff.rho_km_vals)

            # Retrieve normalized power.
            self.p_norm_vals = np.array(NormDiff.p_norm_vals)

            # Phase of signal.
            self.phase_rad_vals = np.array(NormDiff.phase_rad_vals)

            # Ring opening angle.
            self.B_rad_vals = np.array(NormDiff.B_rad_vals)

            # Spacecraft-to-Ring Intercept Point (RIP) distance.
            self.D_km_vals = np.array(NormDiff.D_km_vals)

            # Ring azimuth angle.
            self.phi_rad_vals = np.array(NormDiff.phi_rad_vals)

            # Frequency from the recieved signal.
            self.f_sky_hz_vals = np.array(NormDiff.f_sky_hz_vals)

            # RIP velocity.
            self.rho_dot_kms_vals = np.array(NormDiff.rho_dot_kms_vals)

            # Retrieve time variables (Earth, Ring, and Spacecraft ET).
            self.t_oet_spm_vals = np.array(NormDiff.t_oet_spm_vals)
            self.t_ret_spm_vals = np.array(NormDiff.t_ret_spm_vals)
            self.t_set_spm_vals = np.array(NormDiff.t_set_spm_vals)

            # Pole corrections in ring radius.
            self.rho_corr_pole_km_vals = np.array(
                NormDiff.rho_corr_pole_km_vals
            )

            # Timing corrections in ring radius.
            self.rho_corr_timing_km_vals = np.array(
                NormDiff.rho_corr_timing_km_vals
            )

            # Ring longitude angle.
            self.phi_rl_rad_vals = np.array(NormDiff.phi_rl_rad_vals)

            # Optical depth of diffraction profile.
            self.raw_tau_threshold_vals = np.array(
                NormDiff.raw_tau_threshold_vals
            )

            # History from the NormDiff instance.
            self.dathist = NormDiff.history
        except (AttributeError, TypeError):
            try:
                # Ring radius
                self.rho_km_vals = np.array(NormDiff.rho_km_vals)

                # Retrieve normalized power.
                self.p_norm_vals = np.array(NormDiff.p_norm_vals)

                # Phase of signal.
                self.phase_rad_vals = np.array(NormDiff.phase_rad_vals)

                # Ring opening angle.
                self.B_rad_vals = np.array(NormDiff.B_rad_vals)

                # Spacecraft-to-Ring Intercept Point (RIP) distance.
                self.D_km_vals = np.array(NormDiff.D_km_vals)

                # Ring azimuth angle.
                self.phi_rad_vals = np.array(NormDiff.phi_rad_vals)

                # Frequency from the recieved signal.
                self.f_sky_hz_vals = np.array(NormDiff.f_sky_hz_vals)

                # RIP velocity.
                self.rho_dot_kms_vals = np.array(NormDiff.rho_dot_kms_vals)

                n_elements = np.size(self.rho_km_vals)

                # Retrieve time variables (Earth, Ring, and Spacecraft ET).
                self.t_oet_spm_vals = np.zeros(n_elements)
                self.t_ret_spm_vals = self.t_oet_spm_vals
                self.t_set_spm_vals = self.t_oet_spm_vals

                # Pole corrections in ring radius.
                self.rho_corr_pole_km_vals = self.t_oet_spm_vals

                # Timing corrections in ring radius.
                self.rho_corr_timing_km_vals = self.t_oet_spm_vals

                # Ring longitude angle.
                self.phi_rl_rad_vals = self.t_oet_spm_vals

                # Optical depth of diffraction profile.
                self.raw_tau_threshold_vals = self.t_oet_spm_vals

                # History from the NormDiff instance.
                self.dathist = NormDiff.history

                del n_elements
            except (AttributeError, TypeError) as errmes:
                raise AttributeError(
                    "\n\tEither your instance of Normdiff is missing\n"
                    "\tan attribute, or one of its attributes was\n"
                    "\tunable to be converted into a numpy array.\n"
                    "\tPlease check your input data.\n"
                    "\tOriginal Error Message:\n\t\t %s\n"
                    % (errmes)
                )

        try:
            # Make sure input data are arrays of floating point numbers.
            if not (np.all(np.isreal(self.rho_km_vals))):
                raise ValueError(
                    "\n\t\trho_km_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.rho_km_vals = self.rho_km_vals.astype(float)

            if not (np.all(np.isreal(self.p_norm_vals))):
                raise ValueError(
                    "\n\t\tp_norm_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.p_norm_vals = self.p_norm_vals.astype(float)

            if not (np.all(np.isreal(self.phase_rad_vals))):
                raise ValueError(
                    "\n\t\tphase_rad_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                # Negating phase from mathematical conventions.
                self.phase_rad_vals = -self.phase_rad_vals.astype(float)
        
            if not (np.all(np.isreal(self.B_rad_vals))):
                raise ValueError(
                    "\n\t\tB_rad_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.B_rad_vals = self.B_rad_vals.astype(float)
        
            if not (np.all(np.isreal(self.D_km_vals))):
                raise ValueError(
                    "\n\t\tD_km_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.D_km_vals = self.D_km_vals.astype(float)

            if not (np.all(np.isreal(self.phi_rad_vals))):
                raise ValueError(
                    "\n\t\tphi_rad_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.phi_rad_vals = self.phi_rad_vals.astype(float)

            if not (np.all(np.isreal(self.f_sky_hz_vals))):
                raise ValueError(
                    "\n\t\tf_sky_hz_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.f_sky_hz_vals = self.f_sky_hz_vals.astype(float)

            if not (np.all(np.isreal(self.rho_dot_kms_vals))):
                raise ValueError(
                    "\n\t\trho_dot_kms_vals is not an array of real\n"
                    "\t\tvalued floating point numbers. Please\n"
                    "\t\tcheck your NormDiff class for errors.\n"
                )
            else:
                self.rho_dot_kms_vals = self.rho_dot_kms_vals.astype(float)
        except (ValueError, TypeError) as errmes:
            raise TypeError(
                "\n\tOne of the attributes of the NormDiff class\n"
                "\tCould not be converted into an array of\n"
                "\tfloating point numbers. Please check the\n"
                "\tinput data for errors.\n"
                "\tOriginal Error Message: %s\n"
                % (errmes)
            )

        if (np.size(self.rho_km_vals) < 2):
            raise IndexError(
                "\n\trho_km_vals has less than 2 points.\n"
                "\tIt is impossible to do reconstruction.\n"
                "\tPlease check your input data.\n"
            )

        # Compute sampling distance (km)
        self.dx_km = self.rho_km_vals[1] - self.rho_km_vals[0]

        # Check that the data is well sampled for the requested resolution.
        # Create a 1e-6 buffer to account for floating point round-off error.
        if self.res < 1.999999*self.dx_km:
            raise ValueError(
                "\n\tRequested resolution is less than twice the\n"
                "\tsample spacing of the input data. This\n"
                "\tviolates the sampling theorem and will result\n"
                "\tin an inaccurate reconstruction.\n\n"
                "\tRequested Resolution (km): %f\n"
                "\tSample Spacing (km): %f\n\n"
                "\tTO CORRECT THIS:\n"
                "\t\tChoose a resolution GREATER than %f km\n" %
                (self.res, self.dx_km, 2.0*self.dx_km)
            )
        else:
            pass

        # Compute mu: Sin(|B|)
        self.mu_vals = np.sin(np.abs(self.B_rad_vals))

        if verbose:
            print("\tCheck Variables for Errors...")

        # Check that rho_km_vals is increasing and the rev isn't a chord occ.
        drho = [np.min(self.rho_dot_kms_vals), np.max(self.rho_dot_kms_vals)]

        if (drho[0] < 0) and (drho[1] > 0):
            raise ValueError(
                "\n\tdrho/dt has positive and negative values.\n"
                "\tYour input file is probably a chord occultation.\n"
                "\tDiffraction Correction can only be perform for\n"
                "\tone event at a time. That is, either an ingress\n"
                "\tor an egress event.\n\n"
                "\tTO CORRECT THIS:\n"
                "\t\tSplit the input into two parts: An egress\n"
                "\t\tportion and an ingress portion, and then run\n"
                "\t\tdiffraction correction on the individual pieces.\n"
            )
        elif (self.dx_km > 0) and (drho[1] < 0):
            self.rho_dot_kms_vals = np.abs(self.rho_dot_kms_vals)
        elif (self.dx_km < 0):
            self.rho_km_vals = self.rho_km_vals[::-1]
            self.phase_rad_vals = self.phase_rad_vals[::-1]
            self.p_norm_vals = self.p_norm_vals[::-1]
            self.phi_rad_vals = self.phi_rad_vals[::-1]
            self.B_rad_vals = self.B_rad_vals[::-1]
            self.f_sky_hz_vals = self.f_sky_hz_vals[::-1]
            self.D_km_vals = self.D_km_vals[::-1]
            self.rho_dot_kms_vals = np.abs(self.rho_dot_kms_vals[::-1])
        else:
            del drho

        # Check that all variables from NormDiff are the same size.
        n_rho = np.size(self.rho_km_vals)
        if (np.size(self.phase_rad_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(phase) != len(rho)\n"
                "\tThe number of data points in phase is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.p_norm_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(power) != len(rho)\n"
                "\tThe number of data points in power is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.phi_rad_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(phi) != len(rho)\n"
                "\tThe number of data points in angle is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.B_rad_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(B) != len(rho)\n"
                "\tThe number of data points in B is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.f_sky_hz_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(frequency) != len(rho)\n"
                "\tThe number of data points in frequency is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.D_km_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(D) != len(rho)\n"
                "\tThe number of data points in D is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        elif (np.size(self.rho_dot_kms_vals) != n_rho):
            raise IndexError(
                "\n\tBad NormDiff: len(rho_dot) != len(rho)\n"
                "\tThe number of data points in velocity is\n"
                "\tnot equal to the number of data points\n"
                "\tin radius. Check the input NormDiff\n"
                "\tinstance for any errors.\n"
            )
        else:
            del n_rho

        # Perform error checks on the NormDiff variables.
        if (np.min(self.p_norm_vals) < 0.0):
            raise ValueError(
                "\n\tThere are negative values in the normalized\n"
                "\tdiffracted power. Check the NormDiff instance\n"
                "\tfor errors.\n"
            )
        elif (np.max(np.abs(self.phase_rad_vals)) > TWO_PI+1e-8):
            raise ValueError(
                "\n\tThere are values of phase (in radians)\n"
                "\tthat are greater than 2pi. Check the NormDiff\n"
                "\tinstance for errors. Also check to make sure\n"
                "\tthe values in the NormDiff intance are in\n"
                "\tradians, and NOT degrees.\n"
            )
        elif (np.max(np.abs(self.B_rad_vals)) > TWO_PI+1e-8):
            raise ValueError(
                "\n\tThere are values of B (in radians)\n"
                "\tthat are greater than 2pi. Check the NormDiff\n"
                "\tinstance for errors. Also check to make sure\n"
                "\tthe values in the NormDiff intance are in\n"
                "\tradians, and NOT degrees.\n"
            )
        elif (np.min(self.D_km_vals) < 0.0):
            raise ValueError(
                "\n\tThere are negative values for the spacecraft\n"
                "\tto Ring-Intercept-Point distance, D. Check the\n"
                "\tNormDiff instance for errors.\n"
            )
        elif (np.min(self.D_km_vals == 0.0)):
            raise ValueError(
                "\n\tThere are zero-valued elements for the\n"
                "\tSpacecraft to Ring-Intercept-Point distance,\n"
                "\tD. Check the NormDiff instance for errors.\n"
            )
        elif (np.max(np.abs(self.phi_rad_vals)) > TWO_PI+1e-8):
            raise ValueError(
                "\n\tThere are values of phi (in radians)\n"
                "\tthat are greater than 2pi. Check the NormDiff\n"
                "\tinstance for errors. Also check to make sure\n"
                "\tthe values in the NormDiff intance are in\n"
                "\tradians, and NOT degrees.\n"
            )
        elif (np.min(self.f_sky_hz_vals < 0.0)):
            raise ValueError(
                "\n\tThere are negative values of the frequency.\n"
                "\tCheck the NormDiff instance for errors.\n"
            )
        elif (np.min(self.f_sky_hz_vals == 0.0)):
            raise ValueError(
                "\n\tThere are zero-valued elements for the\n"
                "\tfrequency. Check the NormDiff instance\n"
                "\tfor errors.\n"
            )
        else:
            pass

        if verbose:
            print("\tComputing Necessary Variables...")

        # Compute wavelength (km).
        self.lambda_sky_km_vals = SPEED_OF_LIGHT_KM / self.f_sky_hz_vals

        # Compute the complex transmittance.
        theta = 1j*self.phase_rad_vals
        abs_T = np.sqrt(self.p_norm_vals)
        self.T_hat_vals = abs_T*np.exp(theta)
        del theta, abs_T

        # Compute geometric qunatities for the Fresnel Scale.
        cb = np.cos(self.B_rad_vals)
        sb = np.sin(self.B_rad_vals)
        sp = np.sin(self.phi_rad_vals)

        # Compute the Fresnel Scale (km).
        self.F_km_vals = np.sqrt(0.5 * self.lambda_sky_km_vals *
                                 self.D_km_vals * (1 - cb*cb*sp*sp)/(sb*sb))
        del cb, sb, sp

        # Compute the Normalized Equaivalent Width (See MTR86 Equation 20)
        self.norm_eq = self.__func_dict[wtype]["normeq"]

        # Compute the window width. (See MTR86 Equations 19, 32, and 33).
        if bfac:
            omega = TWO_PI * self.f_sky_hz_vals
            alpha = omega*omega * sigma*sigma / (2.0 * self.rho_dot_kms_vals)
            P = res / (alpha * (self.F_km_vals*self.F_km_vals))
            # The inverse exists only if P>1.
            if (np.min(P) <= 1.0):
                raise ValueError(
                    "\n\tWarning: Bad Points!\n"
                    "\tEither rho_dot_kms_vals, F_km_vals, or res_km is\n"
                    "\ttoo small, or sigma is too large. It is also\n"
                    "\tpossible that the frequency is too large.\n"
                    "\tRequest coarser resolution, check your input\n"
                    "\tdata, or set bfac=False as a keyword.\n"
                )
            else:
                pass

            P1 = P/(1-P)
            P2 = P1*np.exp(P1)
            crange1 = ((RCPR_E + P2) < 1.0e-16).nonzero()
            crange2 = ((RCPR_E + P2) >= 1.0e-16).nonzero()
            self.w_km_vals = np.zeros(np.size(self.rho_km_vals))
            if (np.size(crange1) > 0):
                self.w_km_vals[crange1] = 2.0*self.F_km_vals*self.F_km_vals/res
            else:
                pass

            if (np.size(crange2) > 0):
                self.w_km_vals[crange2] = np.abs(lambertw(P2)-P1)/alpha
            else:
                pass

            del omega, alpha, P, P1, P2, crange1, crange2
        else:
            self.w_km_vals = 2.0*self.F_km_vals*self.F_km_vals/res
        
        self.w_km_vals *= self.norm_eq

        # From the requested range, extract array of the form [a,b]
        if (isinstance(rng, str)):
            self.rng = np.array(region_dict[rng])
        else:
            self.rng = np.array([np.min(rng), np.max(rng)])

        # Compute the starting point and the number of points used.
        rho = self.rho_km_vals
        w_max = np.max(self.w_km_vals)

        # Compute the smallest and largest allowed radii for reconstruction.
        rho_min_lim = np.min(rho)+np.ceil(w_max/2.0)
        rho_max_lim = np.max(rho)-np.ceil(w_max/2.0)

        # Check that there is enough data for reconstruction.
        if rho_min_lim > np.max(rho):
            raise ValueError(
                "\n\tThe window size needed for reconstruction is\n"
                "\tis larger than the available range of data.\n\n"
                "\tMinimum Available Radius in Data: %f\n"
                "\tMaximum Available Radius in Data: %f\n"
                "\tMinimum Reconstructed Radius: %f\n\n"
                "\tThe minimum reconstructed radius is the minimum\n"
                "\tavailable radius in data plus half of a window. This is\n"
                "\tgreater than the maximum available data point, meaning\n"
                "\tthere is insufficient data for the reconstruction.\n\n"
                "\tTO CORRECT THIS:\n"
                "\t\tRequest a coarser resolution or\n"
                "\t\tselect a different window function.\n"
                % (np.min(rho), np.max(rho), rho_min_lim)
            )
        elif rho_max_lim < np.min(rho):
            raise ValueError(
                "\n\tThe window size needed for reconstruction is\n"
                "\tis larger than the available range of data.\n\n"
                "\tMinimum Available Radius in Data: %f\n"
                "\tMaximum Available Radius in Data: %f\n"
                "\tMaximum Reconstructed Radius: %f\n\n"
                "\tThe maximum reconstructed radius is the maximum\n"
                "\tavailable radius in data minus half of a window.\n"
                "\tThis is less than the minimum available data\n"
                "\tpoint, meaning there is insufficient data for\n"
                "\tthe reconstruction.\n\n"
                "\tTO CORRECT THIS:\n"
                "\t\tRequest a coarser resolution or\n"
                "\t\tselect a different window function.\n"
                % (np.min(rho), np.max(rho), rho_max_lim)
            )
        elif (np.max(rho) < np.min(self.rng)):
            raise ValueError(
                "\n\tMinimum requested range is greater\n"
                "\tthan the maximum available data point.\n\n"
                "\tYour Requested Minimum (km): %f\n"
                "\tYour Requested Maximum (km): %f\n"
                "\tMaximum Available Data (km): %f\n\n"
                "\tSelect a smaller range for reconstruction\n"
                % (np.min(rng), np.max(rng), np.max(rho))
            )
        elif (np.min(rho) > np.max(self.rng)):
            raise ValueError(
                "\n\tMaximum requested range is less\n"
                "\tthan the maximum available data point.\n\n"
                "\tYour Requested Minimum (km): %f\n"
                "\tYour Requested Maximum (km): %f\n"
                "\tMinimum Available Data (km): %f\n\n"
                "\tTO CORRECT THIS:\n"
                "\t\tSelect a larger range for reconstruction\n"
                % (np.min(rng), np.max(rng), np.min(rho))
            )
        else:
            pass

        # Compute the smallest and largest values within requested range.
        rho_start = rho[np.min((rho >= np.min(self.rng)).nonzero())]
        rho_end = rho[np.max((rho <= np.max(self.rng)).nonzero())]

        # Compute the start and end point for reconstruction.
        rho_min = np.max([rho_min_lim, rho_start])
        rho_max = np.min([rho_max_lim, rho_end])

        if (rho_min > rho_max):
            if (rho_min_lim > rho_end) and (rho_max_lim > rho_min):
                raise ValueError(
                    "\n\tThe minimum possible radius is greater\n"
                    "\tthan the maximum available data point\n"
                    "\twithin your requested range.\n\n"
                    "\tMaximum Available Data Point: %f\n"
                    "\tMinimum Radius Needed: %f\n\n"
                    "\tThis is because your requested\n"
                    "\trange is outside of the scope of the\n"
                    "\tavailable data (Or near the edge of it).\n\n"
                    "\tTO CORRECT THIS:\n"
                    "\t\tRequest a larger range that includes\n"
                    "\t\tthis minimum data point.\n"
                    % (rho_max, rho_min_lim)
                )
            elif ((rho_max_lim < rho_min) and (rho_min_lim < rho_end)):
                raise ValueError(
                    "\n\tThe maximum possible radius is less\n"
                    "\tthan the minimum available data point\n"
                    "\twithin your requested range.\n\n"
                    "\tMinimum Available Data Point: %f\n"
                    "\tMaximum Radius Needed: %f\n\n"
                    "\tThis is because your requested\n"
                    "\trange is outside of the scope of the\n"
                    "\tavailable data (Or near the edge of it).\n\n"
                    "\tTO CORRECT THIS:\n"
                    "\t\tRequest a larger range that includes\n"
                    "\t\tthis maximum data point.\n"
                    % (rho_min, rho_max_lim)
                )
            elif ((rho_min_lim > rho_end) and (rho_max_lim < rho_min)):
                raise ValueError(
                    "\n\tThe minimum possible radius is less\n"
                    "\tthan the maximum possible radius.\n\n"
                    "\tMinimum Radius Needed: %f\n"
                    "\tMaximum Radius Needed: %f\n\n"
                    "\tThis is because the windows needed for\n"
                    "\treconstruction are greater than the range\n"
                    "\tthat is available in the data.\n\n"
                    "\tTO CORRECT THIS:\n"
                    "\t\tRequest a coarser resolution or choose\n"
                    "\t\ta different window function.\n"
                    % (rho_min_lim, rho_max_lim)
                )
            else:
                raise ValueError(
                    "\n\tThe required window widths for your\n"
                    "\trequested resolution is greater than\n"
                    "\tthe data that is available. No\n"
                    "\tpoints can be processed as a result\n\n"
                    "\tTO CORRECT THIS:\n"
                    "\t\tChose a coarser resolution or choose\n"
                    "\t\ta different window function."
                )
        else:
            pass

        self.start = int(np.min((rho >= rho_min).nonzero()))
        self.finish = int(np.max((rho <= rho_max).nonzero()))
        self.n_used = 1 + (self.finish - self.start)

        # Delete unnecessary variables for clarity.
        del rho, w_max, rho_min_lim, rho_max_lim, rho_start, rho_end
        del rho_min, rho_max, rng, norm, fwd, fft, bfac, psitype, verbose

        if self.verbose:
            print("\tRunning Fresnel Inversion...")
        self.T_vals = self.__ftrans(fwd=False)

        # Compute power and phase.
        if self.verbose:
            print("\tComputing Power and Phase...")
        self.power_vals = np.abs(self.T_vals*self.T_vals)
        self.phase_vals = -np.arctan2(np.imag(self.T_vals),
                                      np.real(self.T_vals))

        if self.verbose:
            print("\tInversion Complete.")
        if self.fwd:
            if self.verbose:
                print("\tComputing Forward Transform...")
            self.T_hat_fwd_vals = self.__ftrans(fwd=True)
            self.p_norm_fwd_vals = np.abs(self.T_hat_fwd_vals*
                                          self.T_hat_fwd_vals)
            self.phase_fwd_vals = -np.arctan2(np.imag(self.T_hat_fwd_vals),
                                              np.real(self.T_hat_fwd_vals))
            if self.verbose:
                print("\tForward Transform Complete.")

        # Compute regions of non-zero power.
        crange = (self.power_vals > 0.0).nonzero()

        # Create empty array for normalized optical depth.
        tau = np.zeros(np.size(self.power_vals))

        # Compute the normalized optical depth.
        tau[crange] = -self.mu_vals[crange]*np.log(
            np.abs(self.power_vals[crange]))
        self.tau_vals = tau

        self.tau_threshold_vals = np.zeros(np.size(self.rho_km_vals))

        self.__trim_attributes(self.fwd)

        if self.verbose:
            print("\tWriting History...")
        input_vars = {
            "Diffraction Data": NormDiff,
            "Resolution (km)":  self.res,
        }

        input_kwds = {
            "Requested Range":      self.rngreq,
            "Requested Window":     self.wtype,
            "Use of Forward Model": self.fwd,
            "Use of Normalization": self.norm,
            "Use of Verbose":       self.verbose,
            "Use of b-factor":      self.bfac,
            "sigma value":          self.sigma,
            "Use of FFT":           self.fft,
            "Psi Approximation":    self.psitype
        }

        self.history = write_history_dict(input_vars, input_kwds, __file__)


        # Set rev_info attribute from NormDiff instance.
        self.rev_info = NormDiff.rev_info
        if write_file:
            write_output_files(self)

        t2 = time.time()
        if self.verbose:
            print("\tDiffraction Correction Complete.")
        print("Computation Time: %f" % (t2-t1), end="\r")

    def __rect(w_in, dx):
        """
            Method:
                __rect
            Purpose:
                Compute the rectangular window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The rectangular window function of width
                    w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute window function
        w_func = np.zeros(nw_pts) + 1.0
        return w_func

    def __coss(w_in, dx):
        """
            Method:
                __coss
            Purpose:
                Compute the squared cosine window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The squared cosine window function of width
                    w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = ONE_PI*(np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Compute window function.
        w_func = np.cos(x)*np.cos(x)
        return w_func

    def __kb20(w_in, dx):
        """
            Method:
                __kb20
            Purpose:
                Compute the Kaiser-Bessel 2.0 window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The Kaiser-Bessel 2.0 window function of width
                    w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = (np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Compute window function.
        w_func = iv(0.0, TWO_PI * np.sqrt((1.0 - 4.0*x*x))) / IV0_20
        return w_func

    def __kb25(w_in, dx):
        """
            Method:
                __kb25
            Purpose:
                Compute the Kaiser-Bessel 2.5 window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The Kaiser-Bessel 2.5 window function of width
                    w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = (np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Alpha value for kb25 is 2.5.
        alpha = 2.5 * ONE_PI

        # Compute window function.
        w_func = iv(0.0, alpha * np.sqrt((1.0 - 4.0*x*x))) / IV0_25
        return w_func

    def __kb35(w_in, dx):
        """
            Method:
                __kb35
            Purpose:
                Compute the Kaiser-Bessel 3.5 window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The Kaiser-Bessel 3.5 window function of width
                    w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = (np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Alpha value for kb35 is 3.5.
        alpha = 3.5 * ONE_PI

        # Compute window function.
        w_func = iv(0.0, alpha * np.sqrt((1.0 - 4.0*x*x))) / IV0_35
        return w_func

    def __kbmd20(w_in, dx):
        """
            Method:
                __kbmd20
            Purpose:
                Compute the Modifed Kaiser-Bessel 2.0
                window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The Modified Kaiser-Bessel 2.0 window function
                    of width w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = (np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Compute window function.
        w_func = (iv(0.0, TWO_PI*np.sqrt(1.0 - 4.0*x*x)) - 1.0)/(IV0_20 - 1.0)
        return w_func

    def __kbmd25(w_in, dx):
        """
            Method:
                __kbmd25
            Purpose:
                Compute the Modifed Kaiser-Bessel 2.5
                window function.
            Arguments:
                w_in:
                    Positive Float
                    The width of the window function to be computed.
                    This value is in kilometers.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
            Outputs:
                w_func:
                    Numpy Array
                    The Modified Kaiser-Bessel 2.5 window function
                    of width w_in and with sample spacing dx.
            Dependencies:
                [1] numpy
        """
        # Window functions have an odd number of points.
        nw_pts = int(2 * np.floor(w_in / (2.0 * dx)) + 1)

        # Compute argument of window function.
        x = (np.arange(nw_pts) - ((nw_pts - 1) / 2.0)) * dx / w_in

        # Alpha value for kbmd25 is 2.5.
        alpha = 2.5 * ONE_PI

        # Compute window function.
        w_func = (iv(0.0, alpha*np.sqrt(1.0 - 4.0*x*x)) - 1.0) / (IV0_25 - 1.0)
        return w_func

    # Function dictionary with normalized equivalent widths.
    __func_dict = {
        "rect":   {"func": __rect,     "normeq": 1.00000000},
        "coss":   {"func": __coss,     "normeq": 1.50000000},
        "kb20":   {"func": __kb20,     "normeq": 1.49634231},
        "kb25":   {"func": __kb25,     "normeq": 1.65191895},
        "kb35":   {"func": __kb35,     "normeq": 1.92844639},
        "kbmd20": {"func": __kbmd20,   "normeq": 1.52048174},
        "kbmd25": {"func": __kbmd25,   "normeq": 1.65994218}
        }

    __psi_types = ["fresnel", "full", "mtr2", "mtr3", "mtr4"]

    def __trim_attributes(self, fwd):
        """
            Method:
                __trim_attributes
            Purpose:
                Trim the attributes in the DiffractionCorrection
                class so that only reconstructed points will be
                returned to the user. All other unused points are
                discarded.
            Arguments:
                self:
                    DiffractionCorrection instance.
                fwd:
                    Boolean
                    Boolean for the forward calculation.
                    If set to True, the forward variables
                    will also be trimmed.
            Dependencies:
                [1] numpy
        """
        # Get rid of uncomputed values and keep only what was processed.
        start = self.start
        n_used = self.n_used
        crange = np.arange(n_used)+start

        # Ring radius, azimuth angle, diffracted power, and phase.
        self.rho_km_vals = self.rho_km_vals[crange]
        self.p_norm_vals = self.p_norm_vals[crange]
        self.phi_rad_vals = self.phi_rad_vals[crange]
        self.phase_rad_vals = self.phase_rad_vals[crange]

        # Ring opening angle, normalized power, phase, and transmittance.
        self.B_rad_vals = self.B_rad_vals[crange]
        self.power_vals = self.power_vals[crange]
        self.phase_vals = self.phase_vals[crange]
        self.T_hat_vals = self.T_hat_vals[crange]
        self.T_vals = self.T_vals[crange]

        # Fresnel scale, window width, and RIP-Spacecraft distance.
        self.F_km_vals = self.F_km_vals[crange]
        self.w_km_vals = self.w_km_vals[crange]
        self.D_km_vals = self.D_km_vals[crange]

        # Ring radius corrections.
        self.rho_corr_pole_km_vals = self.rho_corr_pole_km_vals[crange]
        self.rho_corr_timing_km_vals = self.rho_corr_timing_km_vals[crange]

        # Various time attributes.
        self.t_oet_spm_vals = self.t_oet_spm_vals[crange]
        self.t_ret_spm_vals = self.t_ret_spm_vals[crange]
        self.t_set_spm_vals = self.t_set_spm_vals[crange]

        # All other attributes.
        self.mu_vals = self.mu_vals[crange]
        self.tau_vals = self.tau_vals[crange]
        self.f_sky_hz_vals = self.f_sky_hz_vals[crange]
        self.phi_rl_rad_vals = self.phi_rl_rad_vals[crange]
        self.rho_dot_kms_vals = self.rho_dot_kms_vals[crange]
        self.lambda_sky_km_vals = self.lambda_sky_km_vals[crange]
        self.raw_tau_threshold_vals = self.raw_tau_threshold_vals[crange]

        # If the forward model was run, trim those attributes as well.
        if fwd:
            # Forward power
            self.p_norm_fwd_vals = self.p_norm_fwd_vals[crange]

            # Forward Transmittance and phase.
            self.T_hat_fwd_vals = self.T_hat_fwd_vals[crange]
            self.phase_fwd_vals = self.phase_fwd_vals[crange]

    def __fresinv(self, T_hat, ker, dx, f_scale):
        """
            Method:
                __fresinv
            Purpose:
                Compute the approximation Fresnel
                Inverse (MTR86 Equation 15)
            Arguments:
                T_hat:
                    Complex Numpy Array
                    The complex transmittance of the
                    normalized diffraction data.
                ker:
                    Complex Numpy Array
                    The Fresnel Kernel.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
                f_scale
                    Real Numpy Array
                    The Fresnel Scale as a function of
                    ring radius (km).
            Outputs:
                T:
                    Complex Number
                    The fresnel inversion about the center
                    of the Fresnel Kernel.
            Dependencies:
                [1] numpy
        """
        T = np.sum(ker * T_hat) * dx * (1.0+1.0j) / (2.0 * f_scale)
        return T

    def __fresinvfft(self, T_hat, ker, dx, f_scale):
        """
            Method:
                __fresinvfft
            Purpose:
                Compute the approximation Fresnel Inverse
                (MTR86 Equation 15) using FFTs.
            Arguments:
                T_hat:
                    Complex Numpy Array
                    The complex transmittance of the
                    normalized diffraction data.
                ker:
                    Complex Numpy Array
                    The Fresnel Kernel.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
                f_scale
                    Real Numpy Array
                    The Fresnel Scale as a function of
                    ring radius (km).
            Outputs:
                T:
                    Complex Number
                    The fresnel inversion about the center
                    of the Fresnel Kernel.
            Dependencies:
                [1] numpy
        """

        # Number of points in window.
        nw = np.size(T_hat)

        # FFT of data.
        fft_t_hat = np.fft.fft(T_hat)

        # FFT of weight Fresnel Kernel.
        fft_conv = np.fft.fft(ker)

        # Inverse FFT, assuming the convolution theorem is valid.
        inv_t_hat = np.fft.ifftshift(np.fft.ifft(fft_t_hat*fft_conv))

        # Scale factor outside of integral.
        inv_t_hat *= dx*(1.0+1.0j)/(2.0*f_scale)

        # Return midpoint value.
        T = inv_t_hat[int((nw-1)/2)]
        return T

    def __normalize(self, dx, ker, f_scale):
        """
            Method:
                __normalize
            Purpose:
                Compute the window normalization
            Arguments:
                ker:
                    Complex Numpy Array
                    The Fresnel Kernel.
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
                f_scale
                    Real Numpy Array
                    The Fresnel Scale as a function of
                    ring radius (km).
            Outputs:
                norm_fact:
                    Floating Point Number
                    The normalization of the input
                    Fresnel Kernel.
            Dependencies:
                [1] numpy
        """
        # Freespace Integral
        T1 = np.abs(np.sum(ker) * dx)

        # Normalization Factor
        norm_fact = SQRT_2 * f_scale / T1
        return norm_fact

    def __psi_func(self, kD, r, r0, cbd, d2, cp0, sp0, cp, sp, w, nw):
        """
            Method:
                __psi_func
            Purpose:
                Compute psi (MTR Equation 4)
            Arguments:
                kD:
                    Float
                    Wavenumber
                dx:
                    Positive Float
                    The spacing between points in the window.
                    This is equivalent to the sample spacing.
                    This value is in kilometers.
                f_scale
                    Real Numpy Array
                    The Fresnel Scale as a function of
                    ring radius (km).
            Outputs:
                psi:
                    Real Numpy Array
                    Geometric Function from Fresnel Kernel.
            Dependencies:
                [1] numpy
        """
        # Compute Xi variable (MTR86 Equation 4b).
        xi = cbd * (r0 * cp0 - r * cp)

        # Compute Eta variable (MTR86 Equation 4c).
        eta = (r0*r0 + r*r - 2.0*r*r0*(sp*sp0 + cp*cp0)) / d2

        psi_vals = kD * (np.sqrt(1.0 + 2.0 * xi + eta) - (1.0 + xi))
        return psi_vals

    def __psi_quartic(self, kD, r, r0, cbd, d2, cp0, sp0, cp, sp, w, nw):
        # Compute psi.
        psi_full = self.__psi_func(kD, r, r0, cbd, d2, cp0, sp0, cp, sp, w, nw)

        # Compute shifted ring radius and window width.
        x = (r-r0)
        w = np.max(x)-np.min(x)

        # Compute midpoints and endpoints.
        n1 = 0
        n2 = np.min((r0 - w/4 <= r).nonzero())
        n3 = np.max((r0 + w/4 >= r).nonzero())
        n4 = nw-1

        # Compute variables for psi polynomials.
        d_psi_half = psi_full[n3]-psi_full[n2]
        d_psi_full = psi_full[n4] - psi_full[n1]
        a_psi_half = (psi_full[n3]+psi_full[n2])/2
        a_psi_full = (psi_full[n1]+psi_full[n4])/2

        # Compute coefficients for the polynomial expansion.
        c1 = (8.0*d_psi_half-d_psi_full)/(3.0*w)
        c2 = 4.0*(16.0*a_psi_half-a_psi_full)/(3.0*w*w)
        c3 = 16.0*(d_psi_full-2.0*d_psi_half)/(3.0*w*w*w)
        c4 = 64.0*(a_psi_full-4.0*a_psi_half)/(3.0*w*w*w*w)

        # Compute quartic psi approximation.
        psi_vals = (c1 + c2*x)*x + (c3+c4*x)*x*x*x
        return psi_vals

    def __ftrans(self, fwd):
        # Retrieve Ring Radius.
        rho_km_vals = self.rho_km_vals

        # Retrieve ring azimuth angle.
        phi_rad_vals = self.phi_rad_vals

        # Retrieve window width, RIP distance, and Fresnel scale.
        w_km_vals = self.w_km_vals
        d_km_vals = self.D_km_vals
        F_km_vals = self.F_km_vals

        # Retrieve opening angle.
        B_rad_vals = self.B_rad_vals

        # Retrieve wavelength of transmitted signal
        lambda_km_vals = self.lambda_sky_km_vals

        # Retrieve FFT Boolean
        fft = self.fft

        # Retrieve psi approximation and verbose Boolean
        psitype = self.psitype
        verbose = self.verbose

        # Retrieve norm Boolean.
        norm = self.norm

        # Retrieve requested window type, starting point, and sample spacing.
        wtype = self.wtype
        start = self.start
        dx_km = self.dx_km

        # Retrieve number of points used.
        n_used = self.n_used

        # Compute product of wavenumber and RIP distance.
        kD_vals = TWO_PI * d_km_vals / lambda_km_vals

        # Compute Cosine of opening angle.
        cosb = np.cos(B_rad_vals)

        # Precompute variables for speed.
        cosbD = cosb/d_km_vals
        cosb2 = cosb*cosb

        # Compute cosine and sine of ring azimuth angle.
        cosphi0 = np.cos(phi_rad_vals)
        sinphi0 = np.sin(phi_rad_vals)

        # Precompute squares of variables for speed.
        dsq = d_km_vals*d_km_vals
        rsq = rho_km_vals*rho_km_vals

        # Define window function.
        fw = self.__func_dict[wtype]["func"]

        # Define normalization function and verbose message.
        nrm = self.__normalize
        mes = "\t\tPt: %d  Tot: %d  Width: %d  Psi Iters: %d"

        # Set inverse function to FFT or Integration.
        if fft:
            finv = self.__fresinvfft
        else:
            finv = self.__fresinv
        # Set psi approximation.
        if (psitype == 'full'):
            psif = self.__psi_func
        elif (psitype == 'mtr4'):
            psif = self.__psi_quartic
        else:
            psif = self.__psi_func
        # If forward transform, adjust starting point by half a window.
        if fwd:
            T_in = self.T_vals
            w_max = np.max(w_km_vals[start:start + n_used])
            nw_fwd = int(np.ceil(w_max / (2.0 * dx_km)))
            start_fwd = int(start + nw_fwd)
            n_fwd = int(n_used - 2 * nw_fwd)
            start = start_fwd
            n_used = n_fwd
        else:
            T_in = self.T_hat_vals
        
        # Create empty array for reconstruction / forward transform.
        T_out = T_in * 0.0

        # Set the first computed point to the 'start' variable.
        center = start

        # Compute first window width and window function.
        w_init = w_km_vals[center]
        w_func = fw(w_init, dx_km)

        # Compute number of points in window function
        nw = np.size(w_func)

        # Computed range about the first point
        crange = np.arange(int(center-(nw-1)/2), int(1+center+(nw-1)/2))-1

        # Compute first approximation for stationary phase.
        phi_s_rad = phi_rad_vals[center]

        # Compute Cosines and Sines of first approximation.
        cp = np.cos(phi_s_rad)
        sp = np.sin(phi_s_rad)

        # Factor used for first Newton-Raphson iteration
        dphi_fac = (cosb2*cosphi0*sinphi0/(1.0-cosb2*sinphi0*sinphi0))
        if (psitype == 'fresnel'):
            r0 = rho_km_vals[center]
            r = rho_km_vals[crange]
            F2 = F_km_vals*F_km_vals
            x = (r-r0)
            psi_vals = (ONE_PI / 2.0) * x * x
            loop = 0
            for i in np.arange(n_used):
                # Current point being computed.
                center = start+i

                # Window width and Frensel scale for current point.
                w = w_km_vals[center]

                if (np.abs(w_init - w) >= 2.0 * dx_km):
                    # Reset w_init and recompute window function.
                    w_init = w
                    w_func = fw(w, dx_km)

                    # Reset number of window points
                    nw = np.size(w_func)

                    # Computed range for current point
                    crange = np.arange(int(center-(nw-1)/2),
                                       int(1+center+(nw-1)/2))

                    # Ajdust ring radius by dx_km.
                    r = rho_km_vals[crange]
                    r0 = rho_km_vals[center]

                    # Compute psi for with stationary phase value
                    x = r-r0
                    psi_vals = (ONE_PI / 2.0) * x * x / F2[center]
                else:
                    crange += 1
                    psi_vals = (ONE_PI / 2.0) * x * x / F2[center]

                # Compute kernel function for Fresnel inverse
                if fwd:
                    ker = w_func*np.exp(1j*psi_vals)
                else:
                    ker = w_func*np.exp(-1j*psi_vals)

                # Range of diffracted data that falls inside the window
                T = T_in[crange]

                # Compute 'approximate' Fresnel Inversion for current point
                T_out[center] = finv(T, ker, dx_km, F)

                # If normalization has been set, normalize the reconstruction
                if norm:
                    T_out[center] *= nrm(dx_km, ker, F)
                if verbose:
                    print(mes % (i, n_used, nw, loop), end="\r")
            if verbose:
                print("\n", end="\r")
        else:
            for i in np.arange(n_used):
                # Current point being computed.
                center = start+i

                # Compute current radius and RIP distance.
                r0 = rho_km_vals[center]
                d2 = dsq[center]

                # Compute square of ring radius.
                r02 = rsq[center]

                # Precomputed variables for speed.
                cbd = cosbD[center]
                cb2 = cosb2[center]
                cp0 = cosphi0[center]
                sp0 = sinphi0[center]

                # Compute product of wavenumber and RIP Distance.
                kD = kD_vals[center]

                # Current window width and Fresnel scale.
                w = w_km_vals[center]
                F = F_km_vals[center]

                # If the window width has changed, recompute variables.
                if (np.abs(w_init - w) >= 2.0 * dx_km):
                    # Reset w_init and recompute window function.
                    w_init = w
                    w_func = fw(w, dx_km)

                    # Reset number of window points
                    nw = np.size(w_func)

                    # Computed range for current point
                    crange = np.arange(int(center-(nw-1)/2),
                                       int(1+center+(nw-1)/2))

                    # Ajdust ring radius by dx_km.
                    r = rho_km_vals[crange]

                    # Compute square of ring radius.
                    r2 = rsq[crange]

                    # First iteration of Newton-Raphson.
                    dphi_s_rad = dphi_fac[center] * (r - r0) / r0

                    # Compute new angle.
                    phi_s_rad = phi_rad_vals[center] - dphi_s_rad

                    # Compute Sines and Cosines of new angle.
                    cp = np.cos(phi_s_rad)
                    sp = np.sin(phi_s_rad)

                    # Compute r*cos(B)*D for efficiency
                    rcbd = r * cbd

                # If the window width has not changed, perform Newton-Raphson.
                else:
                    # Adjust computed range by dx_km.
                    crange += 1

                    # Ajdust ring radius by dx_km.
                    r = rho_km_vals[crange]

                    # Compute r*cos(B)*D for efficiency
                    rcbd = r * cbd

                    # Compute square of ring radius.
                    r2 = rsq[crange]

                    # Compute Xi variable (MTR86 Equation 4b).
                    xi = cbd * (r0 * cp0 - r * cp)

                    # Compute Eta variable (MTR86 Equation 4c).
                    eta = (r02 + r2 - 2.0*r*r0*(sp*sp0 + cp*cp0)) / d2

                    # Compute Xi variable (MTR86 Equation 4b).
                    xi = cbd * (r0 * cp0 - r * cp)

                    # Compute Eta variable (MTR86 Equation 4c).
                    eta = (r02 + r2 - 2.0*r*r0*(sp*sp0 + cp*cp0)) / d2

                    # Compute intermediate variables for partial derivatives.
                    v1 = rcbd * sp
                    v2 = 2.0 * r * r0 * (sp*cp0 - sp0*cp) / d2
                    v3 = np.sqrt(1.0 + 2.0*xi + eta)
                    v4 = rcbd * cp
                    v5 = 2.0 * r * r0 * (sp*sp0 + cp*cp0) / d2

                    # Compute variables used for second partial derivative.
                    dphia = (2.0*v4 + v5)/(2.0 * v3)
                    dphib = v4 + (2.0*v1 + v2)*(2.0*v1 + v2)/(4.0*(v3*v3*v3))

                    # Compute First and Second Partial Derivatives of psi
                    psi_d1 = (2.0*v1 + v2) / (2.0 * v3) - v1
                    psi_d2 = dphia - dphib

                    # Compute Newton-Raphson perturbation
                    dphi_s_rad = -psi_d1 / psi_d2
                    phi_s_rad += dphi_s_rad

                    # Compute Cosines and Sines new angle
                    cp = np.cos(phi_s_rad)
                    sp = np.sin(phi_s_rad)

                loop = 0
                # Perform Newton-Raphson on phi.
                while (np.max(np.abs(dphi_s_rad)) > 1.e-10):
                    # Compute Xi variable (MTR86 Equation 4b).
                    xi = cbd * (r0 * cp0 - r * cp)

                    # Compute Eta variable (MTR86 Equation 4c).
                    eta = (r02 + r2 - 2.0*r*r0*(sp*sp0 + cp*cp0)) / d2

                    # Compute intermediate variables for partial derivatives.
                    v1 = rcbd * sp
                    v2 = 2.0 * r * r0 * (sp*cp0 - sp0*cp) / d2
                    v3 = np.sqrt(1.0 + 2.0*xi + eta)
                    v4 = rcbd * cp
                    v5 = 2.0 * r * r0 * (sp*sp0 + cp*cp0) / d2

                    # Compute variables used for second partial derivative.
                    dphia = (2.0*v4 + v5)/(2.0 * v3)
                    dphib = v4 + (2.0*v1 + v2)*(2.0*v1 + v2)/(4.0*(v3*v3*v3))

                    # Compute First and Second Partial Derivatives of psi
                    psi_d1 = (2.0*v1 + v2) / (2.0 * v3) - v1
                    psi_d2 = dphia - dphib

                    # Compute Newton-Raphson perturbation
                    dphi_s_rad = -psi_d1 / psi_d2
                    phi_s_rad += dphi_s_rad

                    # Compute Cosines and Sines new angle
                    cp = np.cos(phi_s_rad)
                    sp = np.sin(phi_s_rad)

                    # Add one to loop variable for each iteration
                    loop += 1
                    if loop > 5:
                        break

                # Compute psi for with stationary phase value
                psi_vals = psif(kD, r, r0, cbd, d2, cp0, sp0, cp, sp, w, nw)

                # Compute kernel function for Fresnel inverse
                if fwd:
                    ker = w_func*np.exp(1j*psi_vals)
                else:
                    ker = w_func*np.exp(-1j*psi_vals)

                # Range of diffracted data that falls inside the window
                T = T_in[crange]

                # Compute 'approximate' Fresnel Inversion for current point
                T_out[center] = finv(T, ker, dx_km, F)

                # If normalization has been set, normalize the reconstruction
                if norm:
                    T_out[center] *= nrm(dx_km, ker, F)
                if verbose:
                    print(mes % (i, n_used-1, nw, loop), end="\r")
            if verbose:
                print("\n", end="\r")

        return T_out
