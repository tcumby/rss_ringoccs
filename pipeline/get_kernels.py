import argparse
import pathlib
from pathlib import Path
from typing import List

import requests


def main(kernel_list_file: Path, output_folder_path: Path):
    if not output_folder_path.exists():
        output_folder_path.mkdir(parents=True)

    if not kernel_list_file.exists():
        raise FileNotFoundError(f"'{kernel_list_file}' does not exist.")

    with kernel_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    base_url = "https://naif.jpl.nasa.gov/pub/"

    for sub_url in sub_url_list:
        url = base_url + sub_url

        path_elems = sub_url.split("/")
        output_file_path = Path(output_folder_path, *path_elems)

        if not output_file_path.exists():
            if not output_file_path.parent.exists():
                output_folder_path.parent.mkdir(parents=True)

            with requests.get(url=url) as r:
                r.raise_for_status()
                with output_file_path.open("wb") as f:
                    f.write(r.content)
        else:
            print(f"Current file {output_file_path} already exists.")


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

    main(
        kernel_list_file=Path(args.kernel_list_file),
        output_folder_path=Path(args.output_folder_path),
    )
