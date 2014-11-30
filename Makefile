all: pi_gameboy


pi_gameboy: src/main.o
	g++ src/main.o -o pi_gameboy  -lwiringPi

main.o: src/main.cc
	g++ -c src/main.cc

#mcp3008: ../mcp3008/mcp3008.h ../mcp3008/mcp3008.cc
#	g++ mcp3008.cc -o mcp3008 

#ili9341: ../ili9341/src/ili9341.h ../ili9341/src/ili9341.cc
#	g++ ../ili9341/src/ili9341.cc 



clean: 
	rm *.o mcp3008
