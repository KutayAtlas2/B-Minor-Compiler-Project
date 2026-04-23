typedef enum{

    // declerathingys
    AST_VARIABLE_DECL,
    AST_FUNCTION_DECL,
    AST_PARAM,
    AST_TYPE, // not my type tho

    // statematamastuff
    AST_IF_STMT,
    AST_WHILE_STMT,
    AST_RETURN_STMT,
    AST_PRINT_STMT,
    AST_EXPR_STMT,
    AST_BLOCK, // the {"long ahh code"} thingy (important ig?)

    //uhh expressions... yea
    AST_BINARY_EXPR, // +, -, *, /, ^, %
    AST_UNARY_EXPR, 
    AST_ASSIGN_EXPR,
    AST_CALL_EXPR,// dial the functions phone number [f(x) type stuff]
    AST_ARG_LIST,

    // literally
    AST_IDENTIFIER, // INDENTIFIER? really, that would have cost at least 3 hours and 5 rage quits
    AST_INTEGER_LITERAL, // lmao how did u forget this???
    AST_STRING_LITERAL,
    AST_FLOAT_LITERAL,
    AST_CHAR_LITERAL,
    AST_BOOLEAN_LITERAL,
    AST_ARRAY_LITERAL,
    AST_VOID_LITERAL, 


} ast_kind;

struct ast_node {
    ast_kind kind; // so kind
    int op;  //as in operator

    
    struct ast_node *left;  
    struct ast_node *right;  
    struct ast_node *middle; // for "else" structure
    struct ast_node *next;   // goes to da next statetamathingymabob

    // the datatatata
    char *name;              // for AST_IDENTIFIER || AST_VARIABLE_DECL
    int int_value;           // for AST_INTEGER_LITERAL || AST_BOOLEAN_LITERAL
    int num_value;
    double float_value;      // for AST_FLOAT_LITERAL
    char *string_value;      // for AST_STRING_LITERAL || AST_CHAR_LITERAL

    //Semantic Info (secret item for later)
    int type;                // The evaluated type (is this whole expr an integer?)
    struct symbol *symbol;   // Pointer to the Symbol Table entry (where it lives in the *fast express highway(RAM)*)
};

struct ast_node* make_node(ast_kind kind, struct ast_node* left, struct ast_node* right);
void print_ast(struct ast_node* node, int level);