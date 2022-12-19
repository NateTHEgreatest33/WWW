#compiler
COMP = g++

#compiler flags
CFLAGS = -std=c++2a -g

#linker flags
LFLAGS = -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib`

debug: main.o graphics_main.o input_main.o game_main.o entity.o button.o utl.o screen.o
	$(COMP) main.o graphics_main.o input_main.o game_main.o entity.o button.o utl.o screen.o ${LFLAGS} -o build/debug/BalloonTowerOffense

release: main.o graphics_main.o input_main.o game_main.o entity.o button.o utl.o screen.o
	$(COMP) main.o graphics_main.o input_main.o game_main.o entity.o button.o utl.o screen.o ${LFLAGS} -o build/release/BalloonTowerOffense

main.o: src/main.cpp src/graphics/main_menu.tpp
	$(COMP) -c src/main.cpp $(CFLAGS) 

graphics_main.o: src/graphics_main.cpp src/graphics_main.hpp
	$(COMP) -c src/graphics_main.cpp $(CFLAGS) 

input_main.o: src/input_main.cpp src/input_main.hpp
	$(COMP) -c src/input_main.cpp $(CFLAGS) 

game_main.o: src/game_main.cpp src/game_main.hpp
	$(COMP) -c src/game_main.cpp $(CFLAGS) 

entity.o: src/entities/entity.cpp src/entities/entity.hpp
	$(COMP) -c src/entities/entity.cpp $(CFLAGS) 

button.o: src/entities/button.cpp src/entities/button.hpp
	$(COMP) -c src/entities/button.cpp $(CFLAGS) 

utl.o: src/utl/utl.cpp src/utl/utl.hpp
	$(COMP) -c src/utl/utl.cpp $(CFLAGS) 

screen.o: src/graphics/screen.cpp src/graphics/screen.hpp
	$(COMP) -c src/graphics/screen.cpp $(CFLAGS) 

#did you remember to add *.o file to debug or relase job?

clean:
	rm *.o