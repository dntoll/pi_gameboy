all: pi_gameboy


pi_gameboy: src/main.o mcp3008.o ili9341.o src/joystick.o src/pong.o
	g++ src/main.o src/joystick.o mcp3008.o ili9341.o -o pi_gameboy  -lwiringPi
	

main.o: src/main.cc src/joystick.o src/pong.o
	g++ -c src/main.cc src/main.cc src/pong.cc

mcp3008.o: ../mcp3008/mcp3008.h ../mcp3008/mcp3008.cc
	g++ -c ../mcp3008/mcp3008.cc

ili9341.o: ../ili9341/src/ili9341.h ../ili9341/src/ili9341.cc
	g++ -c ../ili9341/src/ili9341.cc 



clean: 
	rm *.o pi_gameboy
	rm src/*.o
