#include <CompileString/CompileString.hpp>

#include <cstring>
#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Iterators] begin(), end()", "[Iterators]")
{
  constexpr auto s = CompileString{"foobar"};
  auto begin = s.begin();
  auto end = s.end();

  CHECK(begin != end);
  CHECK(*begin == 'f');
  CHECK(*(begin + 1) == 'o');
  CHECK(*(begin + 3) == 'b');
  CHECK(*(end - 1) == 'r');
  CHECK(begin + 6 == end);
  CHECK(*(++begin) == 'o');
}

TEST_CASE("[Iterators] rbegin(), rend()", "[Iterators]")
{
  constexpr auto s = CompileString{"foobar"};
  auto begin = s.rbegin();
  auto end = s.rend();

  CHECK(begin != end);
  CHECK(*begin == 'r');
  CHECK(*(begin + 1) == 'a');
  CHECK(*(begin + 3) == 'o');
  CHECK(*(end - 1) == 'f');
  CHECK(begin + 6 == end);
  CHECK(*(++begin) == 'a');
}

