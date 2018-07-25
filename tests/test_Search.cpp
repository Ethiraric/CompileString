#include <CompileString/CompileString.hpp>

#include <cstring>
#include <type_traits>

#include <catch.hpp>

using compile_string::CompileString;

TEST_CASE("[Search] find()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find(CompileString{"is"}) == 2);
    CHECK(haystack.find(CompileString{"is a"}) == 5);
    CHECK(haystack.find(CompileString{"is"}, 3) == 5);
    CHECK(haystack.find(CompileString{"foo"}) == compile_string::npos);
    CHECK(haystack.find(CompileString{"This"}) == 0);
    CHECK(haystack.find(CompileString{"This"}, 1) == compile_string::npos);
    CHECK(haystack.find(CompileString{"This is a sentence"}) == 0);
    CHECK(haystack.find(CompileString{"sentencee"}) == compile_string::npos);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find("is") == 2);
    CHECK(haystack.find("is a") == 5);
    CHECK(haystack.find("is", 3) == 5);
    CHECK(haystack.find("foo") == compile_string::npos);
    CHECK(haystack.find("This") == 0);
    CHECK(haystack.find("This", 1) == compile_string::npos);
    CHECK(haystack.find("This is a sentence") == 0);
    CHECK(haystack.find("sentencee") == compile_string::npos);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find('T') == 0);
    CHECK(haystack.find('i') == 2);
    CHECK(haystack.find('i', 2) == 2);
    CHECK(haystack.find('i', 3) == 5);
    CHECK(haystack.find(' ') == 4);
    CHECK(haystack.find('x') == compile_string::npos);
    CHECK(haystack.find('\0') == compile_string::npos);
  }
}

TEST_CASE("[Search] rfind()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.rfind(CompileString{"is"}) == 5);
    CHECK(haystack.rfind(CompileString{"is a"}) == 5);
    CHECK(haystack.rfind(CompileString{"is"}, 5) == 5);
    CHECK(haystack.rfind(CompileString{"is"}, 4) == 2);
    CHECK(haystack.rfind(CompileString{"foo"}) == compile_string::npos);
    CHECK(haystack.rfind(CompileString{"sentence"}) == 10);
    CHECK(haystack.rfind(CompileString{"sentence"}, 10) == 10);
    CHECK(haystack.rfind(CompileString{"sentence"}, 9) == compile_string::npos);
    CHECK(haystack.rfind(CompileString{"This is a sentence"}) == 0);
    CHECK(haystack.rfind(CompileString{"sentencee"}) == compile_string::npos);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.rfind("is") == 5);
    CHECK(haystack.rfind("is a") == 5);
    CHECK(haystack.rfind("is", 5) == 5);
    CHECK(haystack.rfind("is", 4) == 2);
    CHECK(haystack.rfind("foo") == compile_string::npos);
    CHECK(haystack.rfind("sentence") == 10);
    CHECK(haystack.rfind("sentence", 10) == 10);
    CHECK(haystack.rfind("sentence", 9) == compile_string::npos);
    CHECK(haystack.rfind("This is a sentence") == 0);
    CHECK(haystack.rfind("sentencee") == compile_string::npos);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.rfind('T') == 0);
    CHECK(haystack.rfind('i') == 5);
    CHECK(haystack.rfind('i', 5) == 5);
    CHECK(haystack.rfind('i', 4) == 2);
    CHECK(haystack.rfind(' ') == 9);
    CHECK(haystack.rfind('x') == compile_string::npos);
    CHECK(haystack.rfind('\0') == compile_string::npos);
  }
}

TEST_CASE("[Search] find_first_of()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_first_of(CompileString{"si"}) == 2);
    CHECK(haystack.find_first_of(CompileString{"shxi"}) == 1);
    CHECK(haystack.find_first_of(CompileString{" t"}, 5) == 7);
    CHECK(haystack.find_first_of(CompileString{"mcu"}, 4) == 16);
    CHECK(haystack.find_first_of(CompileString{"HIS"}) == compile_string::npos);
    CHECK(haystack.find_first_of(CompileString{"Tlqp"}, 1) ==
          compile_string::npos);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_first_of("si") == 2);
    CHECK(haystack.find_first_of("shxi") == 1);
    CHECK(haystack.find_first_of(" t", 5) == 7);
    CHECK(haystack.find_first_of("mcu", 4) == 16);
    CHECK(haystack.find_first_of("HIS") == compile_string::npos);
    CHECK(haystack.find_first_of("Tlqp", 1) == compile_string::npos);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_first_of('T') == 0);
    CHECK(haystack.find_first_of('i') == 2);
    CHECK(haystack.find_first_of('i', 2) == 2);
    CHECK(haystack.find_first_of('i', 3) == 5);
    CHECK(haystack.find_first_of(' ') == 4);
    CHECK(haystack.find_first_of('x') == compile_string::npos);
    CHECK(haystack.find_first_of('\0') == compile_string::npos);
  }
}

TEST_CASE("[Search] find_first_not_of()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_first_not_of(CompileString{"This aen"}) == 13);
    CHECK(haystack.find_first_not_of(CompileString{"T"}) == 1);
    CHECK(haystack.find_first_not_of(CompileString{"This aentc"}) ==
          compile_string::npos);
    CHECK(haystack.find_first_not_of(CompileString{"tenc"}, 13) ==
          compile_string::npos);
    CHECK(haystack.find_first_not_of(CompileString{"is "}, 2) == 8);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_first_not_of("This aen") == 13);
    CHECK(haystack.find_first_not_of("T") == 1);
    CHECK(haystack.find_first_not_of("This aentc") == compile_string::npos);
    CHECK(haystack.find_first_not_of("tenc", 13) == compile_string::npos);
    CHECK(haystack.find_first_not_of("is ", 2) == 8);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"Thiss iss a ssentence"};

    CHECK(haystack.find_first_not_of('T') == 1);
    CHECK(haystack.find_first_not_of('i') == 0);
    CHECK(haystack.find_first_not_of('s', 3) == 5);
    CHECK(haystack.find_first_not_of('i', 2) == 3);
    CHECK(haystack.find_first_not_of('e', 20) == compile_string::npos);
    CHECK(haystack.find_first_not_of('1', 20) == 20);
  }
}

TEST_CASE("[Search] find_last_of()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_last_of(CompileString{"si"}) == 10);
    CHECK(haystack.find_last_of(CompileString{"shxi"}) == 10);
    CHECK(haystack.find_last_of(CompileString{" t"}, 5) == 4);
    CHECK(haystack.find_last_of(CompileString{" t"}, 14) == 13);
    CHECK(haystack.find_last_of(CompileString{" t"}, 3) == compile_string::npos);
    CHECK(haystack.find_last_of(CompileString{"HIS"}) == compile_string::npos);
    CHECK(haystack.find_last_of(CompileString{"Tlqp"}) == 0);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_last_of("si") == 10);
    CHECK(haystack.find_last_of("shxi") == 10);
    CHECK(haystack.find_last_of(" t", 5) == 4);
    CHECK(haystack.find_last_of(" t", 14) == 13);
    CHECK(haystack.find_last_of(" t", 3) == compile_string::npos);
    CHECK(haystack.find_last_of("HIS") == compile_string::npos);
    CHECK(haystack.find_last_of("Tlqp") == 0);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_last_of('T') == 0);
    CHECK(haystack.find_last_of('i') == 5);
    CHECK(haystack.find_last_of('i', 5) == 5);
    CHECK(haystack.find_last_of('i', 1) == compile_string::npos);
    CHECK(haystack.find_last_of(' ') == 9);
    CHECK(haystack.find_last_of('x') == compile_string::npos);
    CHECK(haystack.find_last_of('\0') == compile_string::npos);
  }
}

TEST_CASE("[Search] find_last_not_of()", "[Search]")
{
  SECTION("CompileString")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_last_not_of(CompileString{"This aenc"}) == 13);
    CHECK(haystack.find_last_not_of(CompileString{"this aenc"}) == 0);
    CHECK(haystack.find_last_not_of(CompileString{"T"}) == 17);
    CHECK(haystack.find_last_not_of(CompileString{"T"}, 3) == 3);
    CHECK(haystack.find_last_not_of(CompileString{"This aentc"}) ==
          compile_string::npos);
    CHECK(haystack.find_last_not_of(CompileString{"This ae"}, 11) ==
          compile_string::npos);
  }

  SECTION("Raw string")
  {
    constexpr auto haystack = CompileString{"This is a sentence"};

    CHECK(haystack.find_last_not_of("This aenc") == 13);
    CHECK(haystack.find_last_not_of("this aenc") == 0);
    CHECK(haystack.find_last_not_of("T") == 17);
    CHECK(haystack.find_last_not_of("T", 3) == 3);
    CHECK(haystack.find_last_not_of("This aentc") == compile_string::npos);
    CHECK(haystack.find_last_not_of("This ae", 11) == compile_string::npos);
  }

  SECTION("char")
  {
    constexpr auto haystack = CompileString{"Thiss iss a ssentence"};

    CHECK(haystack.find_last_not_of('T') == 20);
    CHECK(haystack.find_last_not_of('e') == 19);
    CHECK(haystack.find_last_not_of('s', 13) == 11);
    CHECK(haystack.find_last_not_of('i', 2) == 1);
    CHECK(haystack.find_last_not_of('T', 0) == compile_string::npos);
    CHECK(haystack.find_last_not_of('e', 20) == 19);
    CHECK(haystack.find_last_not_of('1', 20) == 20);
  }
}
