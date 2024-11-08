#include "gtest/gtest.h"
#include "raytracer.h"

TEST(CanvasTest, CreateCanvas) {
    Canvas c(10, 20);
    EXPECT_EQ(c.width(), 10);
    EXPECT_EQ(c.height(), 20);

    for (int y = 0; y < c.height(); ++y) {
        for (int x = 0; x < c.width(); ++x) {
            Color pixel = c.pixelAt(x, y);
            EXPECT_EQ(c.getIntValue(pixel.r()), 0);
            EXPECT_EQ(c.getIntValue(pixel.g()), 0);
            EXPECT_EQ(c.getIntValue(pixel.b()), 0);
        }
    }
}

TEST(CanvasTest, WritePixelToCanvas) {
    Canvas c(10, 20);
    Color red(1, 0, 0);
    c.writePixel(red, 2, 3);

    Color pixel = c.pixelAt(2, 3);
    EXPECT_EQ(c.getIntValue(pixel.r()), 255);
    EXPECT_EQ(c.getIntValue(pixel.g()), 0);
    EXPECT_EQ(c.getIntValue(pixel.b()), 0);
}

