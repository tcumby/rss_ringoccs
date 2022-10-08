import logging
from pathlib import Path
from typing import List

from pipeline.utility import download_url_list


def main():
    base_url = "https://atmos.nmsu.edu/pdsd/archive/data/"

    output_folder_path = Path(__file__).parent.parent / "data"
    rsr_list_file = (
        Path(__file__).parent.parent
        / "tables"
        / "rsr_16kHz_files_before_USO_failure.txt"
    )

    if not output_folder_path.exists():
        logging.info(f"Creating {output_folder_path}")
        output_folder_path.mkdir(parents=True, exist_ok=True)

    if not rsr_list_file.exists():
        raise FileNotFoundError(f"'{rsr_list_file}' does not exist.")

    with rsr_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    download_url_list(base_url, sub_url_list, output_folder_path)


if __name__ == "__main__":
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    main()
