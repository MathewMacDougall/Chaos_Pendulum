#include <gtest/gtest.h>
#include "../src/util/point.hpp"

TEST(PointTest, TestObservers) {
    Point a;
    Point b {1.0, 1.0};
    Point c  = Point(-0.0456, 3E9);
    Point d {3, 4};

    EXPECT_EQ(a.x(), 0.0);
    EXPECT_EQ(b.x(), 1.0);
    EXPECT_EQ(b.len(), 1.0);
    EXPECT_EQ(c.y(), 3E9);
    EXPECT_EQ(d.lensq(), 25*25);
    EXPECT_TRUE(a == (Point()));
    EXPECT_TRUE(Point() == (a));
    EXPECT_FALSE(c == (d));
    EXPECT_TRUE(c == (c.clone()));
}

TEST(PointTest, TestMutators) {
    Point a;
    a.move(-2.9, 11.402);
    EXPECT_TRUE(a == (Point(-2.9, 11.402)));
    a.set(-42, 0.01);
    EXPECT_TRUE(a == (Point(-42, 0.01)));
    a.set(0, -5.425);
    EXPECT_TRUE(a == (Point(0, -5.425)));
    a.set(2, 0);
    a.rotate(M_PI / 2);
    EXPECT_TRUE(a == (Point(2, 0)));
    a.set(0, 0);
    a.rotate(M_PI);
    EXPECT_TRUE(a == (Point()));
    a.set(sqrt(3), sqrt(3));
    a.rotate(-M_PI * 3 / 4);
    EXPECT_TRUE(a == (Point(0, -sqrt(6))));
}

TEST(PointTest, TestOperations) {
    Point a = Point(3.5, -1.25);
    Point b = Point(-0.1, 2);
    Point c;
    Point d = Point(0, -5);
    Point e = Point(-1, sqrt(3));

    EXPECT_TRUE(a.add(b) == (Point(3.4, 0.75)));
    EXPECT_TRUE(b.add(a) == (Point(3.4, 0.75)));
    EXPECT_TRUE(b.add(c) == (b));
    EXPECT_TRUE(b.sub(a) == (Point(-3.6, 3.25)));
    EXPECT_TRUE(a.sub(b) == (Point(3.6, -3.25)));
    EXPECT_TRUE(d.norm() == (Point(0, -1)));
    EXPECT_TRUE(e.norm() == (Point(-0.5, sqrt(3)/2)));
}

/*
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/