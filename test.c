/******************************************************************************
 *
 *  File Name........: test.c
 *
 *  Description......: Roman Calc test code
 *
 *  Created by dmjoshy on 2/10/17
 *
 *  Revision History.:
 *  0.1: Basic Tests
 *  0.5: Green on Basic Add
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "RomanCalc.h"

START_TEST (test_basic_add)
{
  	char a[10]="IV";
  	char b[10]="III";
  	char c[10]="";
  	RomanAdd(a,b,c);
  	ck_assert_str_eq(c, "VII");
}
END_TEST

START_TEST (test_basic_sub)
{
  	char a[10]="IV";
  	char b[10]="III";
  	char c[10]="";
  	RomanSub(a,b,c);
  	ck_assert_str_eq(c, "I");
}
END_TEST

Suite * roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_basic_add);
    tcase_add_test(tc_core, test_basic_sub);
    suite_add_tcase(s, tc_core);

    return s;
}
int main(void)
{
	int number_failed;
    Suite *s;
    SRunner *sr;
    s = roman_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}