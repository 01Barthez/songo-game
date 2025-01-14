compile: src/*.c include/*.h
	gcc -o songo_game src/*.c ./main.c include/*.h -lSDL2 -lSDL2_image -lSDL2_ttf
run:
	./songo_game
clean:
	rm -f songo_game