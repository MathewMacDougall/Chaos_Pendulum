#include <gtest/gtest.h>
#include "../src/util/point.hpp"

TEST(PointTest, TestObservers) {
    Point a;
    Point b {1.0, 1.0};
    Point c  = Point(-0.0456, 3E9);
    Point d {3, 4};

    EXPECT_EQ(a.x(), 0.0);
    EXPECT_EQ(b.x(), 1.0);
    EXPECT_EQ(b.len(), sqrt(2));
    EXPECT_EQ(c.y(), 3E9);
    EXPECT_EQ(d.lensq(), 25);
    EXPECT_EQ(a, Point());
    EXPECT_EQ(Point(), a);
    EXPECT_NE(c, d);
    EXPECT_EQ(c, c.clone());
    EXPECT_TRUE(c != d);
    EXPECT_DOUBLE_EQ(b.angle(), M_PI_4);
    EXPECT_DOUBLE_EQ(a.angle(), 0);
    EXPECT_DOUBLE_EQ(c.angle(), atan(c.y() / c.x()));
    EXPECT_EQ(a.perp(), Point());
    EXPECT_EQ(b.perp(), Point(-1, 1));
    EXPECT_EQ(c.perp(), Point(-3E9, -0.0456));
    EXPECT_FALSE(b.isSameDirectionAs(d));
    EXPECT_TRUE(b.isSameDirectionAs(d, M_PI_4));
    EXPECT_TRUE(c.isSameDirectionAs(c));
}

TEST(PointTest, TestMutators) {
    Point a;

    a.move(-2.9, 11.402);
    EXPECT_EQ(a, Point(-2.9, 11.402));

    a.set(-42, 0.01);
    EXPECT_EQ(a, Point(-42, 0.01));

    a.set(0, -5.425);
    EXPECT_EQ(a, Point(0, -5.425));

    a.set(2, 0);
    a.rotate(M_PI / 2.0);
    EXPECT_EQ(a, Point(0, 2));

    a.set(0, 0);
    a.rotate(M_PI);
    EXPECT_EQ(a, Point());

    a.set(sqrt(3), sqrt(3));
    a.rotate(-M_PI * 3.0 / 4.0);
    EXPECT_EQ(a, Point(0, -sqrt(6)));
}

TEST(PointTest, TestArithmeticOperations) {
    Point a = Point(3.5, -1.25);
    Point b = Point(-0.1, 2);
    Point c;
    Point d = Point(0, -5);
    Point e = Point(-1, sqrt(3));
    Point f = e.perp();

    EXPECT_EQ(a.add(b), Point(3.4, 0.75));
    EXPECT_EQ(b.add(a), Point(3.4, 0.75));
    EXPECT_EQ(b.add(c), b);

    EXPECT_EQ(b.sub(a), Point(-3.6, 3.25));
    EXPECT_EQ(a.sub(b), Point(3.6, -3.25));

    EXPECT_EQ(d.norm(), Point(0, -1));
    EXPECT_EQ(e.norm(), Point(-0.5, sqrt(3)/2));

    EXPECT_EQ(c * 5, Point());
    EXPECT_EQ(b * -1, Point(0.1, -2));
    EXPECT_EQ(d * 3, Point(0, -15));
    EXPECT_EQ(e * -4.5, Point(4.5, -sqrt(3) * 4.5));

    EXPECT_DOUBLE_EQ(a.dot(a), a.lensq());
    EXPECT_DOUBLE_EQ(c.dot(a), 0);
    EXPECT_DOUBLE_EQ(e.dot(f), 0);

    EXPECT_EQ(d.projectOnto(c), Point());
    EXPECT_EQ(e.projectOnto(f), Point());
    EXPECT_EQ(b.projectOnto(Point(-4, 0)), Point(-0.1, 0));
    EXPECT_EQ(e.projectOnto(e), e);
    EXPECT_DOUBLE_EQ(d.projectOnto(a).len(), 1.6816819849907811);
    EXPECT_EQ(d.projectOnto(a), Point((double) 350 / 221, (double) -125 / 221));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}