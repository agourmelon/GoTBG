test_map: map.cpp test_map.cpp land.cpp
	g++ -o build/test_map map.cpp test_map.cpp land.cpp
	build/test_map

main: land.cpp main.cpp
	g++ -o build/main main.cpp
	build/main
