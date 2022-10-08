"""
:Purpose:
    Functions relating to writing an output file.

:Dependencies:
    #. sys
    #. pds3_geo_series
    #. pds3_cal_series
    #. pds3_dlp_series
    #. pds3_tau_series
    #. time
    #. os

"""

# from .pds3_spectro_image import write_spectro_image
from .filepath_tools import construct_output_filename
from ..calibration import Calibration, DiffractionLimitedProfile
from rss_ringoccs.diffrec import DiffractionCorrection
from ..occgeo import Geometry


#'SPECTRO': write_spectro_image}


def write_output_files(inst, add_text=None):
    """
    Write output (geo, cal, dlp, tau) *.TAB and *.LBL files, depending on
    instance given.

    Arguments
        :inst (*object*): Instance of either Geometry, Calibration,
                         DiffractionLimitedProfile, or
                         DiffractionCorrection

    Keyword Arguments
        :add_text (*str*): Additional string to be added to filename.

    """
    if add_text is not None:
        add = add_text
    else:
        add = ""

    # Check for instance type and write that specific file
    if isinstance(inst, Geometry):
        filtyp = "GEO" + add

    elif isinstance(inst, Calibration):
        filtyp = "CAL" + add

    elif isinstance(inst, DiffractionLimitedProfile):
        filtyp = "DLP_" + str(int(inst.dr_km * 1000 * 2)).zfill(4) + "M" + add

    elif isinstance(inst, DiffractionCorrection):
        filtyp = "TAU_" + str(int(inst.input_res * 1000)).zfill(5) + "M" + add
    # elif isinstance(inst, rss.scatter.Scatter):
    #    filtyp = 'SCATTER_' + inst.band + (inst.dsn).split('-')[1] + add
    else:
        raise TypeError("invalid instance for write_output_files.")

    rev_info = inst.rev_info
    outfiles = construct_output_filename(rev_info, inst, filtyp)
    return outfiles


"""
Revisions:
"""
