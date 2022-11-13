default:
	g++ src/main.cpp \
	src/graphics_main.cpp \
	src/input_main.cpp \
	src/game_main.cpp \
	src/entities/entity.cpp \
	src/graphics/main_menu.cpp \
	-std=c++2a -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o build/RayLibGame
