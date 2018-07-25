#include <CompileString/CompileString.hpp>

#include <cstring>
#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Access] operator[]", "[Access]")
{
  constexpr auto s = CompileString{"foo"};
  CHECK(s[0] == 'f');
  CHECK(s[1] == 'o');
  CHECK(s[2] == 'o');
}

TEST_CASE("[Access] front()", "[Access]")
{
  constexpr auto s = CompileString{"baz"};
  CHECK(s.front() == 'b');
}

TEST_CASE("[Access] back()", "[Access]")
{
  constexpr auto s = CompileString{"baz"};
  CHECK(s.back() == 'z');
}

TEST_CASE("[Access] data(), c_str()", "[Access]")
{
  constexpr auto s = CompileString{"baz"};
  CHECK(!strcmp(s.data(), "baz"));
  CHECK(!strcmp(s.c_str(), "baz"));
  constexpr auto s2 = CompileString{""};
  CHECK(!strcmp(s2.data(), ""));
  CHECK(!strcmp(s2.c_str(), ""));
}
