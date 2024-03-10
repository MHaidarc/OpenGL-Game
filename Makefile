main:
	cc src/main.c glad/src/gl.c -Iglad/include -lglfw -ldl -Wall -Wextra -Wpedantic -O2 -o bin/game

