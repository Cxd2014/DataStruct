#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE (100)
static char calc[MAX_TOKEN_SIZE];
static int globle_pos = 0;

static char token_show[7][32] = {
    "BAD_TOKEN",
    "NUMBER_TOKEN",
    "ADD_OPERATOR_TOKEN",
    "SUB_OPERATOR_TOKEN",
    "MUL_OPERATOR_TOKEN",
    "DIV_OPERATOR_TOKEN",
    "END_OF_LINE_TOKEN",
};

typedef enum {
    BAD_TOKEN,
    NUMBER_TOKEN,
    ADD_OPERATOR_TOKEN,
    SUB_OPERATOR_TOKEN,
    MUL_OPERATOR_TOKEN,
    DIV_OPERATOR_TOKEN,
    END_OF_LINE_TOKEN
} TokenKind;

typedef enum {
    INITIAL_STATUS,
    IN_INT_PART_STATUS,
    DOT_STATUS,
    IN_FRAC_PART_STATUS
} LexerStatus;

typedef struct {
    TokenKind kind;
    double      value;
    char        str[MAX_TOKEN_SIZE];
} Token;

void get_token(Token *token)
{
    int out_pos = 0;
 
    LexerStatus status = INITIAL_STATUS;
    char current_char;

    token->kind = BAD_TOKEN;
    while (calc[globle_pos] != '\0') {
        current_char = calc[globle_pos];
        if ((status == IN_INT_PART_STATUS || status == IN_FRAC_PART_STATUS)
            && !isdigit(current_char) && current_char != '.') {
            token->kind = NUMBER_TOKEN;
            sscanf(token->str, "%lf", &token->value);
            return;
        }
        
        /* 去掉空格和换行符操作 */
        if (isspace(current_char)) {
            if (current_char == '\n') {
                token->kind = END_OF_LINE_TOKEN;
                globle_pos++;
                return;
            }
            globle_pos++;
            continue;
        }
        
        if (out_pos >= MAX_TOKEN_SIZE-1) {
            fprintf(stderr, "token too long.\n");
            exit(1);
        }
        token->str[out_pos] = calc[globle_pos];
        globle_pos++;
        out_pos++;
        token->str[out_pos] = '\0';

        if (current_char == '+') {
            token->kind = ADD_OPERATOR_TOKEN;
            return;
        } else if (current_char == '-') {
            token->kind = SUB_OPERATOR_TOKEN;
            return;
        } else if (current_char == '*') {
            token->kind = MUL_OPERATOR_TOKEN;
            return;
        } else if (current_char == '/') {
            token->kind = DIV_OPERATOR_TOKEN;
            return;
        } else if (isdigit(current_char)) {
            if (status == INITIAL_STATUS) {
                status = IN_INT_PART_STATUS;
            } else if (status == DOT_STATUS) {
                status = IN_FRAC_PART_STATUS;
            }
        } else if (current_char == '.') {
            if (status == IN_INT_PART_STATUS) {
                status = DOT_STATUS;
            } else {
                fprintf(stderr, "syntax error.\n");
                exit(1);
            }
        } else {
            fprintf(stderr, "bad character(%c)\n", current_char);
            exit(1);
        }
    }
}

int main(int argc, char **argv)
{   
    int len = strlen(argv[1]);
    if(len >= MAX_TOKEN_SIZE){
        printf("sorry,the string is too long than %d!\n",MAX_TOKEN_SIZE);
        return -1;
    }

    strcpy(calc,argv[1]);
    /* 字符串结尾要加一个换行符 */
    calc[len] = '\n';
    printf("calc = %s\n",calc);

    Token token;
    while(calc[globle_pos] != '\0'){
        get_token(&token);
        printf("token.str = %-5s token.TokenKind = %s \n",token.str,token_show[token.kind]);
    }
    return 0;
}