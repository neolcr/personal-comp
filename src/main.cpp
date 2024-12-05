#include "./generation.hpp"
#include "parser.hpp"
#include <cstdlib>


int main(int argc, char* argv[]) {
    if (argc != 2){
        std::cerr << "Incorrect usage" << std::endl;
        std::cerr << "hydro <<input.hy>" << std::endl;
        return EXIT_FAILURE;
    }


    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    // std::cout << "I read: " << contents << std::endl;

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();
    Parser parser(std::move(tokens));
    std::optional<NodeExit> tree = parser.parse();
    if (!tree.has_value()) {
        std::cerr << "No exist statement found" << std::endl;
        exit(EXIT_FAILURE);
    }

    Generator generator(tree.value());
    // std::cout <<tokens_to_asm(tokens) << std::endl;
    {
        std::fstream file("out.asm", std::ios::out);
        // file << tokens_to_asm(tokens);
        file << generator.generate();
    }

    system("nasm -f elf64 out.asm -o out.o");
    system("ld out.o -o out");

    return EXIT_SUCCESS;
}


