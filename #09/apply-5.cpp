#include <iostream>
#include <vector>

void print(const std::vector<int>& a) {
    int n = a.size();
    std::cout << "{";
    if(n>0) {
        std::cout << a[0];            // Print the first element
        for(int i=1; i < n; i++)
            std::cout << ',' << a[i]; // Print the rest
    }
    std::cout << "}";
}
void permute(std::vector<int>& a, int begin, int end) {
    if (begin == end) {
        print(a);
        std::cout << std::endl;
        return;
    }

    for (int i=begin; i<=end; i++) {
        std::swap(a[begin], a[i]);
        permute(a, begin + 1, end);
        std::swap(a[begin], a[i]);
    }
}
int main() {
    // Get number of values from the user
    std::cout << "Please enter number of values to permute: ";
    int number;
    std::cin >> number;
    // Create the vector to hold all the values
    std::vector<int> list(number);
    // Initialize the vector
    for(int i=0; i<number; i++)
        list[i] = i;

    // Print original list
    print(list);
    std::cout << "\n----------\n";
    // Print all the permutations of list
    permute(list, 0, number-1);
    std::cout << "\n----------\n";
    // Print list after all the manipulations
    print(list);
}