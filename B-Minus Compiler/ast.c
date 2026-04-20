#include "ast.h" /* you spent an hour on this cause you forgot to include the library dumbass */
#include <stdlib.h>
#include <stdio.h>
struct ast_node* make_node(ast_kind kind, struct ast_node *l, struct ast_node *r) {
    struct ast_node *n = calloc(1, sizeof(struct ast_node));
    n->kind = kind;
    n->left = l;
    n->right = r;
    return n;
}
// print to ACTUALLY SEE the thing
void print_ast(struct ast_node *n, int level) {
    if (!n) return;

    for (int i = 0; i < level; i++) printf("  "); 

    printf("Node: %d", n->kind);
    if (n->name) printf(" (Name: %s)", n->name);
    if (n->kind == AST_INTEGER_LITERAL) printf(" (Val: %d)", n->int_value);
    printf("\n");

    print_ast(n->left, level + 1);
    print_ast(n->middle, level + 1);
    print_ast(n->right, level + 1);
    print_ast(n->next, level); // next items in a list stay at same level
}