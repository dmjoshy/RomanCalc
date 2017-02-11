/******************************************************************************
 *
 *  File Name........: RomanCalc.c
 *
 *  Description......:
 *
 *  Created by dmjoshy on 2/10/17
 *
 *  Revision History.:
 *  0.1: Function defs
 *  0.2: Added to Num conversion
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RomanCalc.h"
const char *thous[3] = {"M", "MM", "MMM"};
const char *huns[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *tens[9] = {"X", "XX", "XXXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *ones[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
// ****** Calc OPERATIONS ****** 
void RomanAdd(char *a, char *b){
	printf("%s=%d\n",a,ToNum(a));
	printf("Addition end\n");
}

void RomanSub(char *a, char *b){
	printf("Subtraction end\n");
}
// ****** Conversion OPERATIONS ****** 
int ToRoman(char *a){
	
}

int ToNum(char *a){
	//indexes for each group's place, initially -1
	int th,h,te,u;
	th=h=te=u=-1;
	th=findplace(a, 'M', 'F');//F meaningless in this call
	h=findplace(a,'C','D');
	te=findplace(a,'X','L');
	u=findplace(a,'I','V');
	//exception check for 'CM'
	if(h<th && h!=-1)
		th=-1;
	//exception check for 'XC'
	if(te<h && te!=-1)
		h=-1;
	//exception check for 'IX'
	if(u<te && u!=-1)
		te=-1;
	printf("%d %d %d %d\n",th,h,te,u);
	int n1,n2,n3,n4;
	n1=n2=n3=n4=0;
	char s1[5],s2[5],s3[5],s4[5];
	if(th!=-1){
		//extracting correct portion of string
		int x;
		if(h==-1 && te==-1 && u==-1)
			x=strlen(a);
		else{
			if(h!=-1){
				x=h-th;
			}
			if(te!=-1 && h==-1)
				x=te-th;
			if(u!=-1 && te==-1 && h==-1)
				x=u-th;
		}
		strncpy(s1,a,x);
		s1[x]='\0';
		printf("1000's=%s\n",s1);

	}
	if(h!=-1){
		//extracting correct portion of string
		int x;
		if(te==-1 && u==-1)
			x=strlen(a)-h;
		else{
			if(te!=-1){
				x=te-h;
			}
			if(u!=-1 && te==-1)
				x=u-h;
			
		}
		strncpy(s2,a+h,x);
		s2[x]='\0';
		printf("100's=%s\n",s2);

	}
	if(te!=-1){
		//extracting correct portion of string
		int x;
		if(u==-1)
			x=strlen(a)-te;
		else
			x=u-te;
		strncpy(s3,a+te,x);
		s3[x]='\0';
		printf("10's=%s\n",s3);

	}
	if(u!=-1){
		//extracting correct portion of string
		strncpy(s4,a+u,strlen(a)-u);
		s4[strlen(a)-u]='\0';
		printf("1's=%s\n",s4);

	}
	int i;
	for(i=0;i<3;i++)
		if(strcmp(s1,thous[i])==0)
		{	n1=i+1; break;}
	for(i=0;i<9;i++)
		if(strcmp(s2,huns[i])==0)
		{	n2=i+1; break;}
	for(i=0;i<9;i++)
		if(strcmp(s3,tens[i])==0)
		{	n3=i+1; break;}
	for(i=0;i<9;i++)
		if(strcmp(s4,ones[i])==0)
		{	n4=i+1; break;}
	return n1*1000+n2*100+n3*10+n4;
}
//custom function for finding groups
int findplace(char *s,char a, char b){
	char *start;
	int s1,s2,t;
	s1=s2=t=-1;
	start = strchr(s, a);
	if(start!=NULL)
		s1 = (int)(start - s);
	start = strchr(s, b);
	if(start!=NULL)
		s2 = (int)(start - s);
	if(s2==-1 && s1!=-1)
		t=s1;
	else
	if(s2!=-1 && s1==-1)
		t=s2;
	else
	if(s2!=-1 && s1!=-1)
		if(s2<s1)
			t=s2;
		else
			t=s1;
	return t;
}