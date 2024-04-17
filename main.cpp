#include <iostream>
#include <unordered_map>
#include <vector>

void depth_traversal(std::unordered_map<char, std::vector<char>> graph, char source = 'a');



int main() {
    std::unordered_map<char, std::vector<char>> graph  = {
            {'a', {'b', 'c'}},
            {'b', {'d'}},
            {'c', {'e'}},
            {'d', {'f'}},
            {'e', {}},
            {'f', {}}
    };

    depth_traversal(graph, 'a');

    return 0;
}

//Depth first traversal algorithm
//Traverses graph deeper in a linear pattern, example of a -> b -> d then moves back to a -> c -> e -> b -> d
//Uses a stack (Add to top and remove from top)
void depth_traversal(std::unordered_map<char, std::vector<char>> graph, char source) {
    std::vector<char> stack {source}; //initialize stack with source node

    while(stack.size() > 0) { //Run as long as stack is not empty
        char current = stack.front();
        stack.erase(stack.begin());
        std::cout << current <<std::endl;
        for(char neighbour: graph[current]) { //Enters vector using current as key
            stack.push_back(neighbour); //Push neighbours to top of stack
        }

    }

}

//Breadth first traversal
//Traverses graph by exploring all neighbours adjacent to the starting node
//uses a que (Add from the back and remove from the front)
