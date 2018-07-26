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
  constexpr auto s5 = 's' + s;
  static_assert(std::is_same_v<decltype(s5), CompileString<7> const>);
  constexpr auto s6 = "moo" + s;
  static_assert(std::is_same_v<decltype(s6), CompileString<9> const>);

  CHECK(!std::strcmp(s.data(), "foobar"));
  CHECK(!std::strcmp(s2.data(), "foobarbaz"));
  CHECK(!std::strcmp(s3.data(), "foobars"));
  CHECK(!std::strcmp(s4.data(), "foobarmeeh"));
  CHECK(!std::strcmp(s5.data(), "sfoobar"));
  CHECK(!std::strcmp(s6.data(), "moofoobar"));
}

TEST_CASE("[Operators] operator std::string_view", "[Operators]")
{
  constexpr auto s = CompileString{"foobar"};
  auto sw = std::string_view{s};

  CHECK(sw.data() == s.data());
  CHECK(sw.size() == s.size());
}

TEST_CASE("[Operators] Comparison", "[Operators]")
{
  constexpr char const raws[] = "foo";
  constexpr auto s = CompileString{raws};
  constexpr char const raws1[] = "bar";
  constexpr auto s1 = CompileString{raws1};
  constexpr char const raws2[] = "baz";
  constexpr auto s2 = CompileString{raws2};
  constexpr char const raws3[] = "foo";
  constexpr auto s3 = CompileString{raws3};

  SECTION("operator==")
  {
    CHECK(s == raws);
    CHECK(s == s3);
    CHECK(!(s == s2));
    CHECK(!(s == raws2));
    CHECK(raws == s);
    CHECK(!(raws == s2));
  }

  SECTION("operator!=")
  {
    CHECK(!(s != raws));
    CHECK(!(s != s3));
    CHECK(s != s2);
    CHECK(s != raws2);
    CHECK(!(raws != s));
    CHECK(raws != s2);
  }

  SECTION("operator<")
  {
    CHECK(s1 < s2);
    CHECK(s1 < raws2);
    CHECK(!(s < s1));
    CHECK(!(s < raws1));
    CHECK(!(s < s3));
    CHECK(!(s < raws3));
    CHECK(raws1 < s2);
    CHECK(!(raws < s1));
    CHECK(!(raws < s3));
  }

  SECTION("operator>")
  {
    CHECK(!(s1 > s2));
    CHECK(!(s1 > raws2));
    CHECK(s > s1);
    CHECK(s > raws1);
    CHECK(!(s > s3));
    CHECK(!(s > raws3));
    CHECK(!(raws1 > s2));
    CHECK(raws > s1);
    CHECK(!(raws > s3));
  }

  SECTION("operator<=")
  {
    CHECK(s1 <= s2);
    CHECK(s1 <= raws2);
    CHECK(!(s <= s1));
    CHECK(!(s <= raws1));
    CHECK(s <= s3);
    CHECK(s <= raws3);
    CHECK(raws1 <= s2);
    CHECK(!(raws <= s1));
    CHECK(raws <= s3);
  }

  SECTION("operator>=")
  {
    CHECK(!(s1 >= s2));
    CHECK(!(s1 >= raws2));
    CHECK(s >= s1);
    CHECK(s >= raws1);
    CHECK(s >= s3);
    CHECK(s >= raws3);
    CHECK(!(raws1 >= s2));
    CHECK(raws >= s1);
    CHECK(raws >= s3);
  }
}
