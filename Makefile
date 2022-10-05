default:
	g++ \
	src/main.cpp \
	-std=c++11 -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o build/RayLibGame

#new cpp files need to be included above to compile

#to compile in c:
# default:
# 	cc src/main.c -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o build/RayLibGame