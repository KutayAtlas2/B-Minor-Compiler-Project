#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h" // wow congrats to me. I didnt forget add it this time and not deal with nonexistent errors for 30 minutes.

symbol *head = NULL;
int current_scope = 0; // 0 = Global, 1+ = Local

void enterScope() {
    current_scope++;
}

void exitScope() {
    symbol *s = head;

    while (s != NULL && s->scope == current_scope) {
        s->retired = 1;
        s = s->next;
    }
    current_scope--;
}

int insertSymbol(char *name, int type) {
    // Check if it exists IN THE CURRENT SCOPE only. Shadowing is allowed for outer scopes.
    symbol *s = head;

    printf("DEBUG: Inserting '%s' | Current Scope: %d | Head Scope: %s\n", 
        name, current_scope, (head ? "Exists" : "NULL"));

    while (s != NULL) {
        if (s-> scope == current_scope && strcmp(s->name, name) == 0) return 0; // Error: Redeclared in same scope.
        s = s->next;
    }

    symbol *new_sym = malloc(sizeof(symbol));
    new_sym->name = strdup(name);
    new_sym->type = type;
    new_sym->scope = current_scope;
    new_sym->next = head;
    head = new_sym;
    return 1;
}

symbol* lookUpSymbol(char *name) {
    symbol *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && !current->retired) return current;
        current = current->next;
    }
    return NULL; // lmao bozos passport failed in ALL the accessible scopes
}

symbol* lookUpRetiredSymbol(char *name) {
    symbol *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}