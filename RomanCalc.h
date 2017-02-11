/******************************************************************************
 *
 *  File Name........: RomanCalc.h
 *
 *  Description......:
 *
 *  Created by dmjoshy on 2/10/17
 *
 *  Revision History.:
 *	0.1: Function headers
 *  0.2: Added new headers
 *****************************************************************************/

//const char *tens[10] = {"foo", "bar", "bletch", ...};
//const char *units[10] = {"foo", "bar", "bletch", ...};
void RomanAdd(char*, char *);
void RomanSub(char*, char *);
int ToRoman(char*);
int ToNum(char*);
int findplace(char*, char, char);