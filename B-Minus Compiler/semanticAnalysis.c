#include "ast.h"

int semanticAnalysis(struct ast_node *n) {
    if(!n) {return AST_VOID_LITERAL;}

    int left_type = semanticAnalysis(n->left);
    int right_type = semanticAnalysis(n->right);
}