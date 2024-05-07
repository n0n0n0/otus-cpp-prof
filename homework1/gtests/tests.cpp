#include <gtest/gtest.h>

#include "../lib.h"

TEST(TestPatchVersion, not_equal_1000) {
    ASSERT_TRUE(version() != 1000);
}

