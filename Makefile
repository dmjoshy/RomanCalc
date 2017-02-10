all: RomanCalc.c
	@gcc -c RomanCalc.c
	@ar rcs RomanCalc.a RomanCalc.o
	
clean:
	@rm -f *.o 

test: test.c RomanCalc.c
	@gcc -o test test.c RomanCalc.c