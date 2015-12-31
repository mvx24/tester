// clang selftest.c tester.c
#include <stdio.h>
#include <stdint.h>
#include "tester.h"

void basic_assert_test(void *data)
{
	ASSERT(1 == 1);
	ASSERT(ASSERT(1 == 1));
}

void __attribute__((constructor)) setup(void)
{
	suite_name = "tester self test";
	add_test_case("Basic Assert Testing", basic_assert_test, NULL);
}

void __attribute__((destructor)) teardown(void)
{
	// Nothing to teardown
}
