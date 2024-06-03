#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include "DrawAllShapes.cpp"
#include "Circle.h"
#include "Square.h"
#include <vector>

class MCircle : public Circle {
private:
  double radius_;
public:
  MCircle(double radius_) : Circle(radius_) {}
  MOCK_METHOD(void, radius, (), (const));
  MOCK_METHOD(void, accept, ( ShapeVisitor const& v), ());
};

class MSquare : public Square {
private:
  double side_;
public:
  MSquare(double side_) : Square(side_) {}
  MOCK_METHOD(void, side, (), (const));
};

using ::testing::AtLeast;

TEST (MockSquare, test1) {
  MSquare sq(3.4);
  EXPECT_CALL(sq, side()).Times(AtLeast(1));
  sq.side();
}

TEST (MockCircle, test2) {
  MCircle si(3.14);
  EXPECT_CALL(si, radius()).Times(AtLeast(1));
  si.radius();
}

TEST (GetParametrs, test3) {
  Circle a(3.14);
  Square b(5);
  EXPECT_EQ(a.radius(), 3.14);
  EXPECT_EQ(b.side(), 5);
}

TEST (NewTest, test3) {
  std::unique_ptr<MCircle> el = std::make_unique<MCircle>( 2.3 );
  EXPECT_CALL(*el, accept(testing::_)).Times(AtLeast(1));
  el->accept(Draw{});
}