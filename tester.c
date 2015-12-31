#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"

struct _testcase
{
	void *data;
	char *name;
	test_case_fnc fnc;
};

// Console colors: http://linuxgazette.net/issue65/padala.html
static const char _green[] = { 0x1B, '[', '1', ';', '3', '2', 'm', 0};
static const char _red[] = { 0x1B, '[', '1', ';', '3', '1', 'm', 0};
static const char _bold[] = { 0x1B, '[', '1', 'm', 0};
static const char _reset[] = { 0x1B, '[', '0', ';', '0', 'm', 0};

char *suite_name = "Tester";
int test_count;
int error_count;
static int _count;
static struct _testcase *_testcases;

void add_test_case(char *name, test_case_fnc fnc, void *data)
{
	struct _testcase *current = _testcases;
	_testcases = (struct _testcase *)malloc(sizeof(struct _testcase) * (_count + 1));
	memcpy(_testcases, current, sizeof(struct _testcase) * _count);
	_testcases[_count].data = data;
	_testcases[_count].name = name;
	_testcases[_count].fnc = fnc;
	++_count;
}

int main(int argc, char *argv[])
{
	int i;
	const char *color;
	printf("%s************** Starting %s **************%s\n", _bold, suite_name, _reset);
	for(i = 0; i < _count; ++i) {
		if(_testcases[i].name)
			printf("%s \n", _testcases[i].name);
		_testcases[i].fnc(_testcases[i].data);
		printf("\n");
	}
	color = (error_count)?_red:_green;
	printf("%s%d tests ran for %s. %d errors found.%s\n", color, test_count, suite_name, error_count, _reset);
	return error_count;
}
