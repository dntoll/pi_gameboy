CPP_FILES := $(wildcard src/*.cc)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cc=.o)))


all: pi_gameboy


pi_gameboy: mcp3008.o ili9341.o $(OBJ_FILES)
	g++ -g -lwiringPi -lrt -o $@ $^ 
	
obj/%.o: src/%.cc
	g++ $(CC_FLAGS) -c -o $@ $<

mcp3008.o: ../mcp3008/mcp3008.h ../mcp3008/mcp3008.cc
	g++ -c ../mcp3008/mcp3008.cc

ili9341.o: ../ili9341/src/ili9341.h ../ili9341/src/ili9341.cc
	g++ -c ../ili9341/src/ili9341.cc 

clean: 
	rm *.o pi_gameboy
	rm src/*.o
