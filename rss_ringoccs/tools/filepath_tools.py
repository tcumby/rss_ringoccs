import os
from time import strftime

from rss_ringoccs.tools.pds3_cal_series import write_cal_series
from rss_ringoccs.tools.pds3_dlp_series import write_dlp_series
from rss_ringoccs.tools.pds3_geo_series import write_geo_series
from rss_ringoccs.tools.pds3_tau_series import write_tau_series

func_typ = {
    "GEO": write_geo_series,
    "CAL": write_cal_series,
    "DLP": write_dlp_series,
    "TAU": write_tau_series,
}


def construct_filepath(rev_info, filtyp):
    """
    Construct output filepath

    Arguments
        :rev_info (*dict*): Dictionary with information related to ring
                            occultation.
        :filtyp (*str*): Type of file (e.g., 'GEO', 'CAL, 'DLP', 'TAU')

    Returns
        :title_out (*list*): List of strings of output file names
        :outdir_out (*list*): List of strings of output directory path
    """
    title_out = []
    outdir_out = []

    pd1 = (rev_info["prof_dir"].split('"')[1])[0]
    if pd1 == "B":
        pd1 = ["I", "E"]
        pd2 = "C"
    else:
        pd1 = [pd1]
        pd2 = ""

    doy = rev_info["doy"]
    band = rev_info["band"].split('"')[1]
    year = rev_info["year"]
    if int(year) > 2010:
        dsn = rev_info["dsn"].split("-")[-1] + rev_info["ul_dsn"].split("-")[-1]
    else:
        dsn = rev_info["dsn"].split("-")[-1]
    rev = rev_info["rev_num"]

    if "DIR" in rev_info:
        if "DLP" in filtyp or "TAU" in filtyp or "Summary" in filtyp:
            pd2 = "C"

    if "PER" in rev_info:
        pd2 = "P" + pd2

    for dd in pd1:
        filestr = (
            "RSS_" + str(year) + "_" + str(doy) + "_" + str(band) + str(dsn) + "_" + dd
        )

        dirstr = (
            "../output/Rev"
            + rev
            + "/Rev"
            + rev
            + pd2
            + dd
            + "/"
            + "Rev"
            + rev
            + pd2
            + dd
            + "_"
            + filestr
            + "/"
        )

        # Create output file name without file extension
        curday = strftime("%Y%m%d")
        out1 = dirstr + filestr + "_" + filtyp.upper() + "_" + curday

        if os.path.exists(dirstr):

            # Check for most recent file and order them by date
            dirfiles = [x for x in os.listdir(dirstr) if x.startswith(".") == False]

            if len(dirfiles) == 0:
                seq_num = "0001"
            else:
                sqn0 = [
                    x.split("_")[-2] + x.split("_")[-1][0:4]
                    for x in dirfiles
                    if (filtyp.upper() in x) and (x.split("_")[-2] == curday)
                ]
                if len(sqn0) == 0:
                    seq_num = "0001"
                else:
                    sqn1 = [int(x) for x in sqn0]

                    seq_num = (str(sqn1[-1] + 1))[-4:]

            out2 = out1 + "_" + seq_num

        else:
            os.system("[ ! -d " + dirstr + " ] && mkdir -p " + dirstr)

            seq_num = "0001"
            out2 = out1 + "_" + seq_num

        title = out2.split("/")[-1]
        outdir = "/".join(out2.split("/")[0:-1]) + "/"
        title_out.append(title)
        outdir_out.append(outdir)
    return title_out, outdir_out


def construct_output_filename(rev_info, inst, filtyp):
    """
    Construct output filepath

    Arguments
        :rev_info (*dict*): Dictionary with information related to ring
                            occultation.
        :inst (*object*): Instance of either Geometry, Calibration,
                         DiffractionLimitedProfile, or
                         DiffractionCorrection
        :filtyp (*str*): Type of file (e.g., 'GEO', 'CAL, 'DLP', 'TAU')

    Returns
        :outfiles (*list*): List of output filepaths
    """

    titles, outdirs = construct_filepath(rev_info, filtyp)
    ndirs = len(titles)
    outfiles = []
    for n in range(ndirs):
        title = titles[n]
        outdir = outdirs[n]
        outfiles.append(outdir + title)
        func_typ[filtyp[0:3]](rev_info, inst, title, outdir, rev_info["prof_dir"])

    return outfiles
