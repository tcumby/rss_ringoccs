import argparse
import logging
import pathlib
from pathlib import Path
from typing import List

from pipeline.utility import download_url_list


def main(rsr_list_file: Path, output_folder_path: Path):
    if not output_folder_path.exists():
        logging.info(f"Creating {output_folder_path}")
        output_folder_path.mkdir(parents=True, exist_ok=True)

    if not rsr_list_file.exists():
        raise FileNotFoundError(f"'{rsr_list_file}' does not exist.")

    with rsr_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    base_url = "https://atmos.nmsu.edu/pdsd/archive/data/"

    download_url_list(base_url, sub_url_list, output_folder_path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Retrieve RSR files.")

    parser.add_argument(
        "rsr_list_file",
        action="store",
        help="The path to a text file containing a list of RSR files to retrieve",
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
        rsr_list_file=Path(args.rsr_list_file),
        output_folder_path=Path(args.output_folder_path),
    )
