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
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "RomanCalc.h"

void main(int argc, char **argv)
{
	char *s;
	s = (char *) malloc(30);
	RomanAdd("XXXV","XLII",s);
  	//RomanSub("MMCMXIX","I",s);
  	printf("Result=%s\n",s);
}