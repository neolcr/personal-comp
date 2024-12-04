#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2){
        std::cerr << "Incorrect usage" << std::endl;
        std::cerr << "hydro <<input.hy>" << std::endl;
        return EXIT_FAILURE;
    }



    // std::cout << argv[0] << std::endl;
    // std::cout << argv[1] << std::endl;
    // std::cout << "Hello world Felipe" << std::endl;
    return EXIT_SUCCESS;
}


