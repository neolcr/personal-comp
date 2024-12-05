#pragma once

#include "./tokenization.hpp"
#include <cstdlib>

enum class NodeType {
    STATEMENT,
    FUNCTION_CALL,
    IDENTIFIER,
    ARGUMENT,
    TYPE
};

struct Node {
    NodeType node_type;
    std::optional<std::string> value;
};

class ASTNode {

public:
    inline explicit ASTNode(std::vector<Token> tokens)
        : m_tokens(std::move(tokens))
    {
    }

    std::optional<Node> parse()
    {
        Node stmt { .node_type = NodeType::STATEMENT };

        return stmt;
    }

private:
    const std::vector<Token> m_tokens;
};
