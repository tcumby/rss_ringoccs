import logging
from pathlib import Path
from typing import List

import requests


def download_url_list(base_url: str, sub_url_list: List[str], output_folder_path: Path):
    for sub_url in sub_url_list:
        url = base_url + sub_url

        path_elems = sub_url.split("/")
        output_file_path = Path(output_folder_path, *path_elems)

        if not output_file_path.exists():
            parent_folder = output_file_path.parent
            if not parent_folder.exists():
                parent_folder.mkdir(parents=True, exist_ok=True)

            logging.info(f"Downloading {url}")
            try:
                with requests.get(url=url) as r:
                    r.raise_for_status()
                    with output_file_path.open("wb") as f:
                        f.write(r.content)
            except requests.exceptions.HTTPError as err:
                logging.error(err)
        else:
            logging.info(f"Current file {output_file_path} already exists.")
