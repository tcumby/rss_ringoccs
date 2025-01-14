"""
    License and Copyright:
        Copyright (C) 2019 Team Cassini

        This program is free software: you  can redistribute it and/or modify it
        under the  terms of the GNU  General Public License as  published by the
        Free Software Foundation,  either version 3 of the License,  or (at your
        option) any later version.

        This  program  is distributed  in  the  hope  that  it will  be  useful,
        but WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
        Public License for more details.

        You should have received a copy  of the GNU General Public License along
        with this program. If not, see http://www.gnu.org/licenses/.

        This program is part of the rss_ringoccs repository hosted at
        https://github.com/NASA-Planetary-Science/rss_ringoccs and developed
        with the financial support of NASA's Cassini Mission to Saturn.

    Purpose:
        Provide tools for analysis of ring occultation experiments,
        particularly those pertaining to the `Cassini Radio Science
        Experiment <https://pds-rings.seti.org/cassini/rss/>`_,
        based on methods from [MTR1986]_ and [CRSUG2018]_. This software
        package contains methods for reading and extracting RSR data,
        computing occultation geometry, calibrating RSR data, and
        performing diffraction reconstruction for calibrated data at
        different resolutions. Also included are tools for writing
        and reading the data products output by the software.

    Dependencies:
        #. numpy
        #. spiceypy
        #. scipy
        #. time
        #. sys
        #. subprocess
        #. pdb
        #. pandas
        #. matplotlib
        #. os
        #. platform

    References:
        ..  [MTR1986] Essam A. Marouf, G. Leonard Tyler, Paul A. Rosen,
            "Profiling Saturn's rings by radio occultation".
            Icarus, Volume 68, Issue 1, 1986, Pages 120-166,
            https://doi.org/10.1016/0019-1035(86)90078-3
        ..  [CRSUG2018] `Cassini Radio Science User's Guide
            <https://pds-rings.seti.org/cassini/rss/Cassini%20Radio
            %20Science%20Users%20Guide%20-%2030%20Sep%202018.pdf>`_.
        ..  [GRESH86] Gresh et al. (1986) "An analysis of bending waves
            in Saturn's rings using Voyager radio occultation data".
            Icarus 68, 481-502.
        ..  [NICH14] Philip D. Nicholson, Richard G. French, Colleen A.
            McGhee-French, Matthew M. Hedman, Essam A. Marouf, Joshua
            E. Colwell, Katherine Lonergan, Talia Sepersky.
            "Noncircular features in Saturn's rings II: The C ring".
            Icarus, Volume 241, 2014, Pages 373-396, ISSN 0019-1035.
            https://doi.org/10.1016/j.icarus.2014.06.024 or
            http://www.sciencedirect.com/science/article/pii/S0019103514003443
        .. [NAIF] NASA JPL/NAIF spice toolkit
            https://naif.jpl.nasa.gov/pub/naif/toolkit_docs/Tutorials/
            pdf/individual_docs/27_derived_quant.pdf
        ..  https://en.wikipedia.org/wiki/Window_function
        ..  https://en.wikipedia.org/wiki/Window_function
        ..  On approximating the Modified Bessel Function of the
            First Kind and Toader-Qi Mean, Yang, ZH. & Chu, YM.
            J Inequal Appl (2016): 40., Springer,
            https://doi.org/10.1186/s13660-016-0988-1
        ..  https://docs.python.org/3/library/subprocess.html
            https://stackoverflow.com/questions/
            3777301/how-to-call-a-shell-script-from-python-code
        ..  A. Savitzky, M. J. E. Golay, Smoothing and
            Differentiation of Data by Simplified Least Squares
            Procedures. Analytical Chemistry, 1964, 36 (8),
            pp 1627-1639.
        ..  Numerical Recipes 3rd Edition: The Art of
            Scientific Computing W.H. Press, S.A. Teukolsky,
            W.T. Vetterling, B.P. Flannery Cambridge University
            Press ISBN-13: 9780521880688
        ..  http://mathworld.wolfram.com/LambertW-Function.html
        ..  https://en.wikipedia.org/wiki/Lambert_W_function
        ..  https://en.wikipedia.org/wiki/Fresnel_integral
        ..  https://en.wikipedia.org/wiki/Error_function
        ..  http://mathworld.wolfram.com/FresnelIntegrals.html
        ..  http://mathworld.wolfram.com/Erf.html
"""

from . import tools
from . import rsr_reader
from . import occgeo
from . import calibration
from . import diffrec
from . import scatter

"""
History:
    Created: Team Cassini - 2018/06/14 2:20 P.M.
    Nov 26 2018 - sflury - doc strings updated to match sphinx formatting
"""
