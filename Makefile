#compiler
COMP = g++

#compiler flags
CFLAGS = -std=c++2a -g

#linker flags
LFLAGS = -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib`

debug: main.o graphics_main.o input_main.o game_main.o entity.o
	$(COMP) main.o graphics_main.o input_main.o game_main.o entity.o ${LFLAGS} -o build/debug/BalloonTowerOffense

output: main.o graphics_main.o input_main.o game_main.o entity.o
	$(COMP) main.o graphics_main.o input_main.o game_main.o entity.o ${LFLAGS} -o build/release/BalloonTowerOffense

main.o: src/main.cpp
	$(COMP) -c src/main.cpp $(CFLAGS) 

graphics_main.o: src/graphics_main.cpp src/graphics_main.hpp
	$(COMP) -c src/graphics_main.cpp $(CFLAGS) 

input_main.o: src/input_main.cpp src/input_main.hpp
	$(COMP) -c src/input_main.cpp $(CFLAGS) 

game_main.o: src/game_main.cpp src/game_main.hpp
	$(COMP) -c src/game_main.cpp $(CFLAGS) 

entity.o: src/entities/entity.cpp src/entities/entity.hpp
	$(COMP) -c src/entities/entity.cpp $(CFLAGS) 

# main_menu.o: src/graphics/main_menu.hpp src/graphics/main_menu.tpp
# 	g++ -c src/graphics/main_menu.hpp $(CFLAGS) 

clean:
	rm *.o