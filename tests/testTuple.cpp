#include <gtest/gtest.h>
#include "Tuple.hpp"
#include "raytracer.h"

TEST(TupleTest, TupleIsPoint) {
    Tuple a = Tuple::point(4.3, -4.2, 3.1);
    
    EXPECT_FLOAT_EQ(a.x(), 4.3);
    EXPECT_FLOAT_EQ(a.y(), -4.2);
    EXPECT_FLOAT_EQ(a.z(), 3.1);
    EXPECT_FLOAT_EQ(a.w(), 1.0);

    EXPECT_TRUE(a.isPoint());
    EXPECT_FALSE(a.isVector());
}

TEST(TupleTest, TupleIsVector) {
    Tuple a = Tuple::vector(4.3, -4.2, 3.1);
    
    EXPECT_FLOAT_EQ(a.x(), 4.3);
    EXPECT_FLOAT_EQ(a.y(), -4.2);
    EXPECT_FLOAT_EQ(a.z(), 3.1);
    EXPECT_FLOAT_EQ(a.w(), 0.0);

    EXPECT_FALSE(a.isPoint());
    EXPECT_TRUE(a.isVector());
}

TEST(TupleTest, PointCreatesTupleWithW1) {
    Tuple p = Tuple::point(4, -4, 3);
    
    EXPECT_FLOAT_EQ(p.x(), 4.0);
    EXPECT_FLOAT_EQ(p.y(), -4.0);
    EXPECT_FLOAT_EQ(p.z(), 3.0);
    EXPECT_FLOAT_EQ(p.w(), 1.0);
}

TEST(TupleTest, VectorCreatesTupleWithW0) {
    Tuple v = Tuple::vector(4, -4, 3);
    
    EXPECT_FLOAT_EQ(v.x(), 4.0);
    EXPECT_FLOAT_EQ(v.y(), -4.0);
    EXPECT_FLOAT_EQ(v.z(), 3.0);
    EXPECT_FLOAT_EQ(v.w(), 0.0);
}

TEST(TupleTest, AddingTwoTuples) {
    Tuple a1 = Tuple(3, -2, 5, 1);
    
    Tuple a2 = Tuple(-2, 3, 1, 0);
    
    Tuple result = a1 + a2;
    
    EXPECT_FLOAT_EQ(result.x(), 1.0);
    EXPECT_FLOAT_EQ(result.y(), 1.0);
    EXPECT_FLOAT_EQ(result.z(), 6.0);
    EXPECT_FLOAT_EQ(result.w(), 1.0);
}

TEST(TupleTest, SubtractingTwoPoints) {
    Tuple p1 = Tuple::point(3, 2, 1);
    
    Tuple p2 = Tuple::point(5, 6, 7);
    
    Tuple result = p1 - p2;
    
    EXPECT_FLOAT_EQ(result.x(), -2.0);
    EXPECT_FLOAT_EQ(result.y(), -4.0);
    EXPECT_FLOAT_EQ(result.z(), -6.0);
    EXPECT_FLOAT_EQ(result.w(), 0.0);
}

TEST(TupleTest, SubtractingVectorFromPoint) {
    Tuple p = Tuple::point(3, 2, 1);
    
    Tuple v = Tuple::vector(5, 6, 7);
    
    Tuple result = p - v;
    
    EXPECT_FLOAT_EQ(result.x(), -2.0);
    EXPECT_FLOAT_EQ(result.y(), -4.0);
    EXPECT_FLOAT_EQ(result.z(), -6.0);
    EXPECT_FLOAT_EQ(result.w(), 1.0);
}

TEST(TupleTest, SubtractingTwoVectors) {
    Tuple v1 = Tuple::vector(3, 2, 1);
    
    Tuple v2 = Tuple::vector(5, 6, 7);
    
    Tuple result = v1 - v2;
    
    EXPECT_FLOAT_EQ(result.x(), -2.0);
    EXPECT_FLOAT_EQ(result.y(), -4.0);
    EXPECT_FLOAT_EQ(result.z(), -6.0);
    EXPECT_FLOAT_EQ(result.w(), 0.0);
}

TEST(TupleTest, SubtractingVectorFromZeroVector) {
    Tuple zero = Tuple::vector(0, 0, 0);
    
    Tuple v = Tuple::vector(1, -2, 3);
    
    Tuple result = zero - v;
    
    EXPECT_FLOAT_EQ(result.x(), -1.0);
    EXPECT_FLOAT_EQ(result.y(), 2.0);
    EXPECT_FLOAT_EQ(result.z(), -3.0);
    EXPECT_FLOAT_EQ(result.w(), 0.0);
}

TEST(TupleTest, NegatingTuple) {
    Tuple a = Tuple(1, -2, 3, -4);
    
    Tuple result = -a;
    
    EXPECT_FLOAT_EQ(result.x(), -1.0);
    EXPECT_FLOAT_EQ(result.y(), 2.0);
    EXPECT_FLOAT_EQ(result.z(), -3.0);
    EXPECT_FLOAT_EQ(result.w(), 4.0);
}

TEST(TupleTest, MultiplyingTupleByScalar) {
    Tuple a = Tuple(1, -2, 3, -4);
    
    Tuple result = a * 3.5;
    
    EXPECT_FLOAT_EQ(result.x(), 3.5);
    EXPECT_FLOAT_EQ(result.y(), -7.0);
    EXPECT_FLOAT_EQ(result.z(), 10.5);
    EXPECT_FLOAT_EQ(result.w(), -14.0);
}

TEST(TupleTest, MultiplyingTupleByFraction) {
    Tuple a = Tuple(1, -2, 3, -4);
    
    Tuple result = a * 0.5;
    
    EXPECT_FLOAT_EQ(result.x(), 0.5);
    EXPECT_FLOAT_EQ(result.y(), -1.0);
    EXPECT_FLOAT_EQ(result.z(), 1.5);
    EXPECT_FLOAT_EQ(result.w(), -2.0);
}

TEST(TupleTest, DividingTupleByScalar) {
    Tuple a = Tuple(1, -2, 3, -4);
    
    Tuple result = a / 2;
    
    EXPECT_FLOAT_EQ(result.x(), 0.5);
    EXPECT_FLOAT_EQ(result.y(), -1.0);
    EXPECT_FLOAT_EQ(result.z(), 1.5);
    EXPECT_FLOAT_EQ(result.w(), -2.0);
}

TEST(TupleTest, ComputingMagnitudeOfVector1) {
    Tuple v = Tuple::vector(1, 0, 0);
    
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
}

TEST(TupleTest, ComputingMagnitudeOfVector2) {
    Tuple v = Tuple::vector(0, 1, 0);
    
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
}

TEST(TupleTest, ComputingMagnitudeOfVector3) {
    Tuple v = Tuple::vector(0, 0, 1);
    
    EXPECT_FLOAT_EQ(v.magnitude(), 1.0f);
}

TEST(TupleTest, ComputingMagnitudeOfVector4) {
    Tuple v = Tuple::vector(1, 2, 3);
    
    EXPECT_FLOAT_EQ(v.magnitude(), sqrt(14.0f));
}

TEST(TupleTest, ComputingMagnitudeOfVector5) {
    Tuple v = Tuple::vector(-1, -2, -3);
    
    EXPECT_FLOAT_EQ(v.magnitude(), sqrt(14.0f));
}

TEST(TupleTest, NormalizingVector1) {
    Tuple v = Tuple::vector(4, 0, 0);
    Tuple norm = v.normalized();
    EXPECT_FLOAT_EQ(norm.x(), 1.0f);
    EXPECT_FLOAT_EQ(norm.y(), 0.0f);
    EXPECT_FLOAT_EQ(norm.z(), 0.0f);
}

TEST(TupleTest, NormalizingVector2) {
    Tuple v = Tuple::vector(1, 2, 3);
    Tuple norm = v.normalized();
    EXPECT_FLOAT_EQ(norm.x(), 1.0f / sqrt(14.0f));
    EXPECT_FLOAT_EQ(norm.y(), 2.0f / sqrt(14.0f));
    EXPECT_FLOAT_EQ(norm.z(), 3.0f / sqrt(14.0f));
}

TEST(TupleTest, MagnitudeOfNormalizedVector) {
    Tuple v = Tuple::vector(1, 2, 3);
    Tuple norm = v.normalized();
    EXPECT_FLOAT_EQ(norm.magnitude(), 1.0f);
}

TEST(TupleTest, DotProduct) {
    Tuple a = Tuple::vector(1, 2, 3);
    Tuple b = Tuple::vector(2, 3, 4);
    EXPECT_FLOAT_EQ(a.dot(b), 20.0f);
}

TEST(TupleTest, CrossProduct) {
    Tuple a = Tuple::vector(1, 2, 3);
    Tuple b = Tuple::vector(2, 3, 4);
    Tuple cross_ab = a.cross(b);
    Tuple cross_ba = b.cross(a);
    
    EXPECT_FLOAT_EQ(cross_ab.x(), -1.0f);
    EXPECT_FLOAT_EQ(cross_ab.y(), 2.0f);
    EXPECT_FLOAT_EQ(cross_ab.z(), -1.0f);

    EXPECT_FLOAT_EQ(cross_ba.x(), 1.0f);
    EXPECT_FLOAT_EQ(cross_ba.y(), -2.0f);
    EXPECT_FLOAT_EQ(cross_ba.z(), 1.0f);
}

