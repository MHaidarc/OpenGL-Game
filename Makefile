main:
	cc src/main.c glad/src/gl.c -Iglad/include -lglfw -lm -Wall -Wextra -Wpedantic -O3 -o bin/game

