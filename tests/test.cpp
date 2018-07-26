#include <CompileString/CompileString.hpp>

#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Constructor] Using deduction-guide", "[Constructor]")
{
  auto s = CompileString{"foo"};
  CHECK(std::is_same_v<decltype(s), CompileString<3>>);
  auto s2 = CompileString{""};
  CHECK(std::is_same_v<decltype(s2), CompileString<0>>);
}

TEST_CASE("[Capacity] size()", "[Capacity]")
{
  constexpr auto s = CompileString{"foo"};
  CHECK(s.size() == 3);
  constexpr auto s2 = CompileString{""};
  CHECK(s2.size() == 0);
}

TEST_CASE("[Capacity] empty()", "[Capacity]")
{
  constexpr auto s = CompileString{"foo"};
  CHECK(!s.empty());
  constexpr auto s2 = CompileString{""};
  CHECK(s2.empty());
}
