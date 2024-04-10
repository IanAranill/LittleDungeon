files = funz.cpp main.cpp weapon.cpp hero.cpp creature.cpp treasure.cpp
option = -std=c++14 -static-libstdc++ -static-libgcc -static -w
compile:
	g++ $(option) $(files) -o gioco

run:
	./gioco

release:
	g++ $(option) $(files) -o LittleDungeon_linux
	x86_64-w64-mingw32-g++ $(option) $(files) -o LittleDungeon_win_x86_64
	i686-w64-mingw32-g++ $(option) $(files) -o LittleDungeon_win_x86_32