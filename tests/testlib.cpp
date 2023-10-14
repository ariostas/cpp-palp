#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <cpp-palp/global.hpp>
#include <cpp-palp/rat.hpp>


using namespace cpp_palp;

TEST_CASE("Test Rationals", "[rational]") {

  Rational a(1,2), b(1,3), c(17,2);
  Rational d = a + a;
  REQUIRE ( d == Rational(1,1) );
}
