all: mcp3008

mcp3008: main.cc mcp3008.h mcp3008.cc
	g++ main.cc mcp3008.cc -o mcp3008  -lwiringPi

clean: 
	rm *.o mcp3008
