import argparse
import pathlib
from pathlib import Path
from typing import List

import requests


def main(rsr_list_file: Path, output_folder_path: Path):
    if not output_folder_path.exists():
        output_folder_path.mkdir(parents=True)

    if not rsr_list_file.exists():
        raise FileNotFoundError(f"'{rsr_list_file}' does not exist.")

    with rsr_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    base_url = "https://atmos.nmsu.edu/pdsd/archive/data/"

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

    main(
        rsr_list_file=Path(args.rsr_list_file),
        output_folder_path=Path(args.output_folder_path),
    )
