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
 *	0.3: Added to Roman conversion
 *  0.4: Added add and sub functions
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RomanCalc.h"
const char *thous[3] = {"M", "MM", "MMM"};
const char *huns[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *tens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *ones[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
// ****** Calc OPERATIONS ****** 
void RomanAdd(char *a, char *b, char *res){
	//printf("%s=%d\n",a,ToNum(a));
	char *s;
	s = (char *) malloc(30);
	ToRoman(ToNum(a)+ToNum(b),s);
	//printf("Result=%s\n",s);
	strcpy(res,s);
	
}

void RomanSub(char *a, char *b, char *res){
	char *s;
	s = (char *) malloc(30);
	ToRoman(ToNum(a)-ToNum(b),s);
	//printf("Result=%s\n",s);
	strcpy(res,s);
	
}
// ****** Conversion OPERATIONS ****** 
void ToRoman(int a, char *res){
	int n1,n2,n3,n4;
	//printf("%d\n",a);
	n1=a/1000;
	n2=(a%1000)/100;
	n3=(a%100)/10;
	n4=a%10;
	if(n1!=0)
		strcat(res,thous[n1-1]);
	if(n2!=0)
		strcat(res,huns[n2-1]);
	if(n3!=0)
		strcat(res,tens[n3-1]);
	if(n4!=0)
		strcat(res,ones[n4-1]);
}

int ToNum(char *a){
	//indexes for each group's place, initially -1
	int th,h,te,u;
	th=h=te=u=-1;
	//printf("%s\n",a);
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
	//printf("%d %d %d %d\n",th,h,te,u);
	int n1,n2,n3,n4;
	n1=n2=n3=n4=0;
	char *s1,*s2,*s3,*s4;
	s1 = (char *) malloc(5);
	s2 = (char *) malloc(5);
	s3 = (char *) malloc(5);
	s4 = (char *) malloc(5);
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
		//printf("1000's=%s\n",s1);

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
		//printf("100's=%s\n",s2);

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
		//printf("10's=%s\n",s3);

	}
	if(u!=-1){
		//extracting correct portion of string
		strncpy(s4,a+u,strlen(a)-u);
		s4[strlen(a)-u]='\0';
		//printf("1's=%s\n",s4);

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
	//printf("Number=%d\n",n1*1000+n2*100+n3*10+n4);
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