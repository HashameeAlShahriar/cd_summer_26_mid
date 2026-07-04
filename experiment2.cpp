#include <iostream>
#include <string>

using namespace std;

void checkToken(string token)
{
    if (token.empty()) return;

    string type = "Unknown";
    bool isValid = true;


    if (token == "cout" || token == "endl")
    {
        type = "Keyword";
    }
    else if (token == "<<" || token == "+")
    {
        type = "Operator";
    }
    else if (token == ";")
    {
        type = "Punctuation";
    }
    else if (token.front() == '"' && token.back() == '"')
    {
        type = "String";
    }
    else if (isdigit(token[0]))
    {
        type = "Numeric";

    }
    else if (isalpha(token[0]) || token[0] == '_')
    {
        type = "Identifier";
        for (int i = 0; i < token.length(); i++)
        {
            char c = token[i];
            if (!isalnum(c) && c != '_')
            {
                isValid = false;
            }
        }
    }
    else
    {
        isValid = false;
    }


    cout << "Token: " << token;
    for (int i = token.length(); i < 12; i++)
    {
        cout << " ";
    }

    cout << "Type: " << type;
    for (int i = type.length(); i < 18; i++)
    {
        cout << " ";
    }

    cout << "Status: ";
    if (isValid)
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}


void tokenizeExpression(string expr)
{
    int start = 0;


    for (int a=0; a < expr.length(); a++)
    {


        if (expr[a]==' ')
        {
            string token = "";
            for (int i = start; i < a; i++)
            {
                token += expr[i];
            }
            checkToken(token);
            start = a+1;
        }
    }
}
int main()
{
    string a = "cout << 60 + sum << \"Hello\" << endl ; ";

    cout << "Analyzing " << a<< "\n\n";

    tokenizeExpression(a);



    return 0;
}
