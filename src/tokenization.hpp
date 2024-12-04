#pragma once

#include <cctype>
#include <cstdlib>
#include <cwctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>


enum class TokenType {
    exit,
    int_lit,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};


class Tokenizer {
public:
    inline Tokenizer(std::string& src): m_src(std::move(src))
    {

    }

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

                if (buf == "exit"){
                    tokens.push_back({.type = TokenType::exit});
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
                buf.clear();

            } else if (c == ';') {
                tokens.push_back({.type = TokenType::semi});
            } else if (std::isspace(c)){
                continue;
            } else {
                std::cerr << "You messed up because there is something weird" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        return tokens;
    }
private:

    [[nodiscard]]std::optional<char> peak(int ahead = 1) const {
        if (m_index + ahead >= m_src.length()){
            return {};
        } else {
            return m_src.at(m_index);
        }

    }

    char consume() {
        return m_src.at(m_index++);

    }

    const std::string m_src;
    int m_index;


};
