#include <gtest/gtest.h>
#include "Matrix.hpp"
#include "Tuple.hpp"

TEST(MatrixTest, ConstructingAndInspecting4x4Matrix) {
    Matrix M(4);
    M.set(1, 0, 0); M.set(2, 0, 1); M.set(3, 0, 2); M.set(4, 0, 3);
    M.set(5.5, 1, 0); M.set(6.5, 1, 1); M.set(7.5, 1, 2); M.set(8.5, 1, 3);
    M.set(9, 2, 0); M.set(10, 2, 1); M.set(11, 2, 2); M.set(12, 2, 3);
    M.set(13.5, 3, 0); M.set(14.5, 3, 1); M.set(15.5, 3, 2); M.set(16.5, 3, 3);
    EXPECT_EQ(M(0, 0), 1); EXPECT_EQ(M(0, 3), 4); EXPECT_EQ(M(1, 0), 5.5);
    EXPECT_EQ(M(1, 2), 7.5); EXPECT_EQ(M(2, 2), 11); EXPECT_EQ(M(3, 0), 13.5);
    EXPECT_EQ(M(3, 2), 15.5);
}

TEST(MatrixTest, Representing2x2Matrix) {
    Matrix M(2);
    M.set(-3, 0, 0); M.set(5, 0, 1); M.set(1, 1, 0); M.set(-2, 1, 1);
    EXPECT_EQ(M(0, 0), -3); EXPECT_EQ(M(0, 1), 5); EXPECT_EQ(M(1, 0), 1);
    EXPECT_EQ(M(1, 1), -2);
}

TEST(MatrixTest, Representing3x3Matrix) {
    Matrix M(3);
    M.set(-3, 0, 0); M.set(5, 0, 1); M.set(0, 0, 2); M.set(1, 1, 0);
    M.set(-2, 1, 1); M.set(-7, 1, 2); M.set(0, 2, 0); M.set(1, 2, 1); M.set(1, 2, 2);
    EXPECT_EQ(M(0, 0), -3); EXPECT_EQ(M(1, 1), -2); EXPECT_EQ(M(2, 2), 1);
}

TEST(MatrixTest, EqualityWithIdenticalMatrices) {
    Matrix A(4), B(4);
    A.set(1, 0, 0); A.set(2, 0, 1); A.set(3, 0, 2); A.set(4, 0, 3);
    A.set(5, 1, 0); A.set(6, 1, 1); A.set(7, 1, 2); A.set(8, 1, 3);
    A.set(9, 2, 0); A.set(8, 2, 1); A.set(7, 2, 2); A.set(6, 2, 3);
    A.set(5, 3, 0); A.set(4, 3, 1); A.set(3, 3, 2); A.set(2, 3, 3);
    B = A;
    EXPECT_TRUE(A == B);
}

TEST(MatrixTest, EqualityWithDifferentMatrices) {
    Matrix A(4), B(4);
    A.set(1, 0, 0); A.set(2, 0, 1); A.set(3, 0, 2); A.set(4, 0, 3);
    A.set(5, 1, 0); A.set(6, 1, 1); A.set(7, 1, 2); A.set(8, 1, 3);
    A.set(9, 2, 0); A.set(8, 2, 1); A.set(7, 2, 2); A.set(6, 2, 3);
    A.set(5, 3, 0); A.set(4, 3, 1); A.set(3, 3, 2); A.set(2, 3, 3);
    B.set(2, 0, 0); B.set(3, 0, 1); B.set(4, 0, 2); B.set(5, 0, 3);
    B.set(6, 1, 0); B.set(7, 1, 1); B.set(8, 1, 2); B.set(9, 1, 3);
    B.set(8, 2, 0); B.set(7, 2, 1); B.set(6, 2, 2); B.set(5, 2, 3);
    B.set(4, 3, 0); B.set(3, 3, 1); B.set(2, 3, 2); B.set(1, 3, 3);
    EXPECT_TRUE(A != B);
}

TEST(MatrixTest, MultiplyingTwoMatrices) {
    Matrix A(4), B(4), expected(4);
    A.set(1, 0, 0); A.set(2, 0, 1); A.set(3, 0, 2); A.set(4, 0, 3);
    A.set(5, 1, 0); A.set(6, 1, 1); A.set(7, 1, 2); A.set(8, 1, 3);
    A.set(9, 2, 0); A.set(8, 2, 1); A.set(7, 2, 2); A.set(6, 2, 3);
    A.set(5, 3, 0); A.set(4, 3, 1); A.set(3, 3, 2); A.set(2, 3, 3);
    B.set(-2, 0, 0); B.set(1, 0, 1); B.set(2, 0, 2); B.set(3, 0, 3);
    B.set(3, 1, 0); B.set(2, 1, 1); B.set(1, 1, 2); B.set(-1, 1, 3);
    B.set(4, 2, 0); B.set(3, 2, 1); B.set(6, 2, 2); B.set(5, 2, 3);
    B.set(1, 3, 0); B.set(2, 3, 1); B.set(7, 3, 2); B.set(8, 3, 3);
    expected.set(20, 0, 0); expected.set(22, 0, 1); expected.set(50, 0, 2); expected.set(48, 0, 3);
    expected.set(44, 1, 0); expected.set(54, 1, 1); expected.set(114, 1, 2); expected.set(108, 1, 3);
    expected.set(40, 2, 0); expected.set(58, 2, 1); expected.set(110, 2, 2); expected.set(102, 2, 3);
    expected.set(16, 3, 0); expected.set(26, 3, 1); expected.set(46, 3, 2); expected.set(42, 3, 3);
    EXPECT_EQ(A * B, expected);
}

TEST(MatrixTest, MatrixMultipliedByTuple) {
    Matrix A(4);
    Tuple b(1, 2, 3, 1), expected(18, 24, 33, 1);
    A.set(1, 0, 0); A.set(2, 0, 1); A.set(3, 0, 2); A.set(4, 0, 3);
    A.set(2, 1, 0); A.set(4, 1, 1); A.set(4, 1, 2); A.set(2, 1, 3);
    A.set(8, 2, 0); A.set(6, 2, 1); A.set(4, 2, 2); A.set(1, 2, 3);
    A.set(0, 3, 0); A.set(0, 3, 1); A.set(0, 3, 2); A.set(1, 3, 3);
    EXPECT_EQ(A * b, expected);
}
