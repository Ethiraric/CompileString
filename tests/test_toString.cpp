#include <CompileString/ToString.hpp>

#include <cstring>
#include <limits>
#include <type_traits>

#include <catch.hpp>

using compile_string::toString;

TEST_CASE("[toString] toString()", "[ToString]")
{
  SECTION("int")
  {
    constexpr auto s1 = toString<14>();
    CHECK(!std::strcmp(s1.data(), "14"));
    constexpr auto s2 = toString<-14>();
    CHECK(!std::strcmp(s2.data(), "-14"));
    constexpr auto s3 = toString<0>();
    CHECK(!std::strcmp(s3.data(), "0"));
    constexpr auto s4 = toString<1>();
    CHECK(!std::strcmp(s4.data(), "1"));
    constexpr auto s5 = toString<-1>();
    CHECK(!std::strcmp(s5.data(), "-1"));
    constexpr auto s6 = toString<std::numeric_limits<int>::max()>();
    auto const s6ref = std::to_string(std::numeric_limits<int>::max());
    CHECK(s6.data() == s6ref);
    constexpr auto s7 = toString<std::numeric_limits<int>::min()>();
    auto const s7ref = std::to_string(std::numeric_limits<int>::min());
    CHECK(s7.data() == s7ref);
  }

  SECTION("unsigned int")
  {
    constexpr auto s1 = toString<14u>();
    CHECK(!std::strcmp(s1.data(), "14"));
    constexpr auto s3 = toString<0>();
    CHECK(!std::strcmp(s3.data(), "0"));
    constexpr auto s4 = toString<1>();
    CHECK(!std::strcmp(s4.data(), "1"));
    constexpr auto s6 = toString<std::numeric_limits<unsigned int>::max()>();
    auto const s6ref = std::to_string(std::numeric_limits<unsigned int>::max());
    CHECK(s6.data() == s6ref);
    constexpr auto s7 = toString<std::numeric_limits<unsigned int>::min()>();
    auto const s7ref = std::to_string(std::numeric_limits<unsigned int>::min());
    CHECK(s7.data() == s7ref);
  }
}
