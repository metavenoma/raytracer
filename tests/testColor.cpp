#include <gtest/gtest.h>
#include "raytracer.h"

class ColorTest : public ::testing::Test {
protected:
    void SetUp() override {
        c1 = Color(0.9f, 0.6f, 0.75f);
        c2 = Color(0.7f, 0.1f, 0.25f);
        c3 = Color(1.0f, 0.2f, 0.4f);
        c4 = Color(0.9f, 1.0f, 0.1f);
    }

    Color c1, c2, c3, c4;
};

TEST_F(ColorTest, TestColorConstructor) {
    Color c(-0.5f, 0.4f, 1.7f);

    EXPECT_FLOAT_EQ(c.r(), -0.5f);
    EXPECT_FLOAT_EQ(c.g(), 0.4f);
    EXPECT_FLOAT_EQ(c.b(), 1.7f);
}

TEST_F(ColorTest, TestAddColors) {
    Color result = c1 + c2;
    EXPECT_FLOAT_EQ(result.r(), 1.6f);
    EXPECT_FLOAT_EQ(result.g(), 0.7f);
    EXPECT_FLOAT_EQ(result.b(), 1.0f);
}

TEST_F(ColorTest, TestSubtractColors) {
    Color result = c1 - c2;
    EXPECT_FLOAT_EQ(result.r(), 0.2f);
    EXPECT_FLOAT_EQ(result.g(), 0.5f);
    EXPECT_FLOAT_EQ(result.b(), 0.5f);
}

TEST_F(ColorTest, TestMultiplyColorByScalar) {
    Color result = c3 * 2.0f;
    EXPECT_FLOAT_EQ(result.r(), 2.0f);
    EXPECT_FLOAT_EQ(result.g(), 0.4f);
    EXPECT_FLOAT_EQ(result.b(), 0.8f);
}

TEST_F(ColorTest, TestMultiplyColors) {
    Color result = c3 * c4;
    EXPECT_FLOAT_EQ(result.r(), 0.9f);
    EXPECT_FLOAT_EQ(result.g(), 0.2f);
    EXPECT_FLOAT_EQ(result.b(), 0.04f);
}

