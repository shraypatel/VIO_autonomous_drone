# Copyright 2024 Group 7
#
# Licensed under the BSD 3-Clause License.

from ament_copyright.main import main
import pytest


@pytest.mark.copyright
@pytest.mark.linter
def test_copyright():
    rc = main(argv=[".", "test"])
    assert rc == 0, "Found errors"
