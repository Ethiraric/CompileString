# CompileString
A tiny header to manipulate "raw strings" in a `std::string` fashion at
compile-time.

A `toString` function on integers is provided in its own header if needs be.

## How it works
`CompileString` is templated over the length of the string (`CompileString<4>`)
and holds a `std::array<char, N + 1>` (`N` being the length of the string, `+
1` to store the end-of-string character `\0`).

In order to add two strings, you need to add their lengths and allocate a new
`array`. This means that the type returned by `operator+` is different from the
type of its 2 operands. A `CompileString` is only assignable to another if both
their lengths are the same.

## Bugs and issues
Feel free to open an Issue or a Pull request.
