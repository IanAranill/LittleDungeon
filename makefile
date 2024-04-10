compile:
	g++ -std=c++14 funz.cpp main.cpp weapon.cpp hero.cpp creature.cpp treasure.cpp -o gioco

run:
	./gioco
release:
	g++ -std=c++14 funz.cpp main.cpp weapon.cpp hero.cpp creature.cpp treasure.cpp -o LittleDungeon_linux
	x86_64-w64-mingw32-g++ -std=c++14 funz.cpp main.cpp weapon.cpp hero.cpp creature.cpp treasure.cpp -o LittleDungeon_win_x86_64
	i686-w64-mingw32-g++ -std=c++14 funz.cpp main.cpp weapon.cpp hero.cpp creature.cpp treasure.cpp -o LittleDungeon_win_x86_32
	zip LittleDungeon.0.1.0.zip *.cpp *.h