#include <cctype>
#include <cstdlib>
#include <cwctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

enum class TokenType {
    _return,
    int_lit,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};


std::vector<Token> tokenize(const std::string& str){
    // for (char c : str) {
    //     std::cout << c << std::endl;
    // }
    std::vector<Token> tokens {};
    std::string buf {};
    for (int i = 0; i < str.length() ; i++ ) {
        char c = str.at(i);
        if (std::isalpha(c)) {
            buf.push_back(c);
            i++;
            while (std::isalpha(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            if (buf == "return"){
                tokens.push_back({.type = TokenType::_return});
                std::cout << "Pushed back: " << buf << std::endl;
                buf.clear();
                continue;
            } else {
                std::cerr << "You messed up" << std::endl;
                exit(EXIT_FAILURE);
            }

        } else if (std::isdigit(c)) {
            buf.push_back(c);
            i++;
            while(std::isdigit(str.at(i))){
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buf});
            std::cout << "Pushed back: " << buf << std::endl;
            buf.clear();

        } else if (c == ';') {
            tokens.push_back({.type = TokenType::semi});
            std::cout << "Pushed back: " << c << std::endl;

        } else if (std::isspace(c)){
            continue;
        } else {
            std::cerr << "You messed up because there is something weird" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
}

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

    std::cout << "I read: " << contents << std::endl;


    tokenize(contents);

    return EXIT_SUCCESS;
}


