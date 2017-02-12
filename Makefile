all: RomanCalc.c
	@gcc -c RomanCalc.c
	
clean:
	@rm -f *.o 

test: test.c RomanCalc.c
	@gcc -o test test.c RomanCalc.c  `pkg-config --cflags --libs check`