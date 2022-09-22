knapsack: sequential/knapsack.cpp parallel/knapsack.cpp sequential/mem_efficient_knapsack.cpp parallel/mem_efficient_knapsack.cpp sequential/space_locality_knapsack.cpp
	g++ -fopenmp sequential/knapsack.cpp -o build/2d_knapsack
	g++ -fopenmp parallel/knapsack.cpp -o build/2d_knapsack_parallel
	g++ -fopenmp sequential/mem_efficient_knapsack.cpp -o build/mem_efficient_knapsack
	g++ -fopenmp parallel/mem_efficient_knapsack.cpp -o build/mem_efficient_knapsack_parallel
	g++ -fopenmp sequential/space_locality_knapsack.cpp -o build/space_locality_knapsack

