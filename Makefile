all: pi_gameboy

#mcp3008: ../mcp3008/mcp3008.h ../mcp3008/mcp3008.cc
#	g++ mcp3008.cc -o mcp3008 

#ili9341: ../ili9341/src/ili9341.h ../ili9341/src/ili9341.cc
#	g++ ../ili9341/src/ili9341.cc 

pi_gameboy: src/main.cc
	g++ src/main.cc -o pi_gameboy  -lwiringPi

clean: 
	rm *.o mcp3008
