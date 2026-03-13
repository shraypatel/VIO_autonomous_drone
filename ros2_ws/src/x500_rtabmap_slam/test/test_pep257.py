# Copyright 2024, All rights reserved.
#
# Licensed under the BSD-3-Clause License.

from ament_pep257.main import main
import pytest


@pytest.mark.pep257
@pytest.mark.linter
def test_pep257():
    rc = main(argv=['.', 'test'])
    assert rc == 0, 'Found code style errors / warnings'
