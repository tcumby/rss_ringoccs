from contextlib import nullcontext as does_not_raise
from typing import List, Tuple, Optional, ContextManager

import pytest  # type: ignore

from rss_ringoccs.tools import date_to_rev

date_to_rev_inputs: List[Tuple[int, int, Optional[str], str, ContextManager]] = [
    (2005, 123, None, "007", does_not_raise()),
    (2012, 225, None, "170", does_not_raise()),
    (2017, 199, None, "284", does_not_raise()),
    (2004, 199, None, "", pytest.raises(ValueError)),
    (2018, 199, None, "", pytest.raises(ValueError)),
]


class TestToolsHistory:
    @pytest.mark.parametrize(
        "year,doy,rss_file,expected_result,expectation", date_to_rev_inputs
    )
    def test_date_to_rev(self, year, doy, rss_file, expected_result, expectation):
        with expectation:
            result = date_to_rev(year, doy, rss_file)
            assert result == expected_result
