test_map: map.cpp test_map.cpp land.cpp
	g++ -o build/test_map map.cpp test_map.cpp land.cpp
	build/test_map
