import logging
from pathlib import Path
from typing import List

from pipeline.utility import download_url_list


def main():
    base_url = "https://naif.jpl.nasa.gov/pub/"

    output_folder_path = Path(__file__).parent.parent / "kernels"
    kernel_list_file = (
        Path(__file__).parent.parent / "tables" / "complete_list_of_kernels.txt"
    )

    if not output_folder_path.exists():
        logging.info(f"Creating {output_folder_path}")
        output_folder_path.mkdir(parents=True, exist_ok=True)

    if not kernel_list_file.exists():
        raise FileNotFoundError(f"'{kernel_list_file}' does not exist.")

    with kernel_list_file.open() as f:
        sub_url_list: List[str] = f.read().split()

    download_url_list(base_url, sub_url_list, output_folder_path)


if __name__ == "__main__":
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    main()
