#include <CompileString/CompileString.hpp>

#include <cstring>
#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Operations] compare()", "[Operations]")
{
  constexpr char raws1[] = "foo";
  constexpr char raws2[] = "bar";
  constexpr auto s1 = CompileString{raws1};
  constexpr auto s2 = CompileString{raws2};
  constexpr auto shorts1 = CompileString{"fo"};
  constexpr auto longs1 = CompileString{"foobar"};

  CHECK(s1.compare(s2) > 0);
  CHECK(s1.compare(raws2) > 0);
  CHECK(s2.compare(s1) < 0);
  CHECK(s2.compare(raws1) < 0);
  CHECK(s1.compare(raws1) == 0);
  CHECK(s2.compare(raws2) == 0);
  CHECK(s1.compare(shorts1) > 0);
  CHECK(s1.compare(longs1) < 0);
  CHECK(s1.compare("") > 0);
}

TEST_CASE("[Operations] starts_with()", "[Operations]")
{
  constexpr auto s1 = CompileString{"foobarbazzabraboof"};

  CHECK(s1.starts_with(""));
  CHECK(s1.starts_with("foo"));
  CHECK(s1.starts_with("foobarbazzabraboof"));
  CHECK(!s1.starts_with("bar"));
  CHECK(!s1.starts_with("foobarbazzabrabood"));
  CHECK(!s1.starts_with("foobarbazzabrabooftoolong"));
  CHECK(!s1.starts_with("oobarbazzabraboof"));

  CHECK(s1.starts_with(CompileString{""}));
  CHECK(s1.starts_with(CompileString{"foo"}));
  CHECK(s1.starts_with(CompileString{"foobarbazzabraboof"}));
  CHECK(!s1.starts_with(CompileString{"bar"}));
  CHECK(!s1.starts_with(CompileString{"foobarbazzabrabood"}));
  CHECK(!s1.starts_with(CompileString{"foobarbazzabrabooftoolong"}));
  CHECK(!s1.starts_with(CompileString{"oobarbazzabraboof"}));
}

TEST_CASE("[Operations] ends_with()", "[Operations]")
{
  constexpr auto s1 = CompileString{"foobarbazzabraboof"};

  CHECK(s1.ends_with(""));
  CHECK(s1.ends_with("oof"));
  CHECK(s1.ends_with("foobarbazzabraboof"));
  CHECK(!s1.ends_with("bar"));
  CHECK(!s1.ends_with("doobarbazzabraboof"));
  CHECK(!s1.ends_with("foobarbazzabrabooftoolong"));
  CHECK(!s1.ends_with("foobarbazzabraboo"));

  CHECK(s1.ends_with(CompileString{""}));
  CHECK(s1.ends_with(CompileString{"oof"}));
  CHECK(s1.ends_with(CompileString{"foobarbazzabraboof"}));
  CHECK(!s1.ends_with(CompileString{"bar"}));
  CHECK(!s1.ends_with(CompileString{"doobarbazzabraboof"}));
  CHECK(!s1.ends_with(CompileString{"foobarbazzabrabooftoolong"}));
  CHECK(!s1.ends_with(CompileString{"foobarbazzabraboo"}));
}
