#include <CompileString/CompileString.hpp>

#include <cstring>
#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Operators] operator+()", "[Operators]")
{
  constexpr auto s = CompileString{"foobar"};
  constexpr auto s2 = s + "baz";
  static_assert(std::is_same_v<decltype(s2), CompileString<9> const>);
  constexpr auto s3 = s + 's';
  static_assert(std::is_same_v<decltype(s3), CompileString<7> const>);
  constexpr auto s4 = s + CompileString{"meeh"};
  static_assert(std::is_same_v<decltype(s4), CompileString<10> const>);

  CHECK(!std::strcmp(s.data(), "foobar"));
  CHECK(!std::strcmp(s2.data(), "foobarbaz"));
  CHECK(!std::strcmp(s3.data(), "foobars"));
  CHECK(!std::strcmp(s4.data(), "foobarmeeh"));
}

TEST_CASE("[Operators] operator std::string_view", "[Operators]")
{
  constexpr auto s = CompileString{"foobar"};
  auto sw = std::string_view{s};

  CHECK(sw.data() == s.data());
  CHECK(sw.size() == s.size());
}
