#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE (100)
static char calc[MAX_TOKEN_SIZE];
static int globle_pos = 0;

static int token_current = 0;
#define unget_token() token_current--

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

static Token token_array[MAX_TOKEN_SIZE];

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

static void my_get_token(Token *token)
{
    //printf("token_current = %d\n",token_current);
    token->kind = token_array[token_current].kind;
    token->value = token_array[token_current].value;
    memcpy(token->str,token_array[token_current].str,(sizeof(char)*MAX_TOKEN_SIZE));
    token_current++;
}

static double parse_primary_expression()
{
    Token token;

    my_get_token(&token);
    if (token.kind == NUMBER_TOKEN) {
        return token.value;
    }
    fprintf(stderr, "syntax error.\n");
    exit(1);
    return 0.0; /* make compiler happy */
}

static double parse_term()
{
    double v1;
    double v2;
    Token token;

    v1 = parse_primary_expression();
    for (;;) {
        my_get_token(&token);
        if (token.kind != MUL_OPERATOR_TOKEN
            && token.kind != DIV_OPERATOR_TOKEN) {
            unget_token();
            break;
        }
        v2 = parse_primary_expression();
        if (token.kind == MUL_OPERATOR_TOKEN) {
            v1 *= v2;
        } else if (token.kind == DIV_OPERATOR_TOKEN) {
            v1 /= v2;
        }
    }
    return v1;
}

double parse_expression()
{
    double v1;
    double v2;
    Token token;

    v1 = parse_term();
    for (;;) {
        my_get_token(&token);
        if (token.kind != ADD_OPERATOR_TOKEN && token.kind != SUB_OPERATOR_TOKEN) {
            unget_token();
            break;
        }

        v2 = parse_term();
        if (token.kind == ADD_OPERATOR_TOKEN) {
            v1 += v2;
        } else if (token.kind == SUB_OPERATOR_TOKEN) {
            v1 -= v2;
        } else {
            unget_token();
        }
    }
    return v1;
}


int main(int argc, char **argv)
{   
    
    int i = 0; 
    double value = 0;
    int len = strlen(argv[1]);
    if(len >= MAX_TOKEN_SIZE){
        printf("sorry,the string is too long than %d!\n",MAX_TOKEN_SIZE);
        return -1;
    }
         
    strcpy(calc,argv[1]);
    /* 字符串结尾要加一个换行符 */
    calc[len] = '\n';

    printf("calc = %s\n",calc);
    
    while(calc[globle_pos] != '\0'){
        get_token(&token_array[i]);
        printf("token.str = %-5s token.kind = %s \n",token_array[i].str,token_show[token_array[i].kind]);
        i++;
    }
    value = parse_expression();
    printf("the result is %f\n",value);

    return 0;
}