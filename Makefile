# default:
# 	g++ src/main.cpp \
# 	src/graphics_main.cpp \
# 	src/input_main.cpp \
# 	src/game_main.cpp \
# 	src/entities/entity.cpp \
# 	-std=c++2a -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o build/RayLibGame

FLAGS = -std=c++2a -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib`

output: main.o graphics_main.o input_main.o game_main.o entity.o
	g++ main.o graphics_main.o input_main.o game_main.o entity.o -o build/BalloonTowerOffense

main.o: src/main.cpp
	g++ -c src/main.cpp $(FLAGS) 

graphics_main.o: src/graphics_main.cpp src/graphics_main.hpp
	g++ -c src/graphics_main.cpp $(FLAGS) 

input_main.o: src/input_main.cpp src/input_main.hpp
	g++ -c src/input_main.cpp $(FLAGS) 

game_main.o: src/game_main.cpp src/game_main.hpp
	g++ -c src/game_main.cpp $(FLAGS) 

entity.o: src/entities/entity.cpp src/entities/entity.hpp
	g++ -c src/entities/entity.cpp $(FLAGS) 

# main_menu.o: src/graphics/main_menu.hpp src/graphics/main_menu.tpp
# 	g++ -c src/graphics/main_menu.hpp $(FLAGS) 

clean:
	rm *.o output