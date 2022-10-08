import argparse
import logging
import pathlib
from pathlib import Path
from typing import List

from pipeline.utility import download_url_list


def main(kernel_list_file: Path, output_folder_path: Path):
    base_url = "https://naif.jpl.nasa.gov/pub/"

    if not output_folder_path.exists():
        logging.info(f"Creating {output_folder_path}")
        output_folder_path.mkdir(parents=True, exist_ok=True)

    if not kernel_list_file.exists():
        raise FileNotFoundError(f"'{kernel_list_file}' does not exist.")

    with kernel_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    download_url_list(base_url, sub_url_list, output_folder_path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Retrieve kernel files.")

    parser.add_argument(
        "kernel_list_file",
        action="store",
        help="The path to a text file containing a list of kernel files to retrieve. For example, "
        "this file could contain:\n"
        "naif/CASSINI/kernels/spk/061129R_SCPSE_06292_06307.bsp\n"
        "naif/CASSINI/kernels/spk/061213R_SCPSE_06308_06318.bsp",
    )

    parser.add_argument(
        "output_folder_path",
        action="store",
        help="The output folder path",
        required=False,
        default=pathlib.Path.cwd(),
    )

    args = parser.parse_args()

    logger = logging.getLogger()
    logger.setLevel(logging.INFO)

    main(
        kernel_list_file=Path(args.kernel_list_file),
        output_folder_path=Path(args.output_folder_path),
    )
