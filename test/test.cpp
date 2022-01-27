#include <avakar/bitflags.h>
#include <avakar/mutest.h>

namespace {

using namespace avakar::bitflags;

enum E1
{
	none,
	e1 = 1,
	e2 = 2,
	e3 = 3,
	e4 = 4,
};

enum class E2
{
	none,
	e1 = 1,
	e2 = 2,
	e3 = 3,
	e4 = 4,
};

}

mutest_case("bitwise")
{
	chk (e1 | e2) == e3;
	chk (E2::e1 | E2::e2) == E2::e3;

	chk (e1 & e2) == none;
	chk (E2::e1 & E2::e2) == E2::none;

	chk (e3 & ~e1) == e2;
	chk (E2::e3 & ~E2::e1) == E2::e2;
}
