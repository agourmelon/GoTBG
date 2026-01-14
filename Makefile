test_map: map.cpp test_map.cpp land.cpp
	g++ -std=c++23 -o build/test_map map.cpp test_map.cpp land.cpp
	build/test_map

main: land.cpp main.cpp map.cpp
	g++ -std=c++23 -o build/main main.cpp land.cpp map.cpp
	build/main
