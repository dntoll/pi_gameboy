CPP_FILES := $(wildcard src/*.cc)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cc=.o)))
ILICPP_FILES := $(wildcard ../ili9341/src/*.cc)
ILIOBJ_FILES := $(addprefix ../ili9341/obj/,$(notdir $(ILICPP_FILES:.cc=.o)))

all: pi_gameboy


pi_gameboy: mcp3008.o $(OBJ_FILES) $(ILIOBJ_FILES)
	g++ -g -lwiringPi -lrt -o $@ $^ 
	
obj/%.o: src/%.cc $(ILICPP_FILES)
	g++ -g $(CC_FLAGS) -c -o $@ $<

../ili9341/obj/%.o: ../ili9341/src/%.cc 
	g++ -g $(CC_FLAGS) -c -o $@ $<

mcp3008.o: ../mcp3008/mcp3008.h ../mcp3008/mcp3008.cc
	g++ -g -c ../mcp3008/mcp3008.cc

#ili9341.o: ../ili9341/src/ili9341.h ../ili9341/src/ili9341.cc
#	g++ -g -c ../ili9341/src/ili9341.cc 

clean: 
	rm obj/*.o pi_gameboy
	rm src/*.o

reload:
	git pull
	make
	sudo ./pi_gameboy