#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void checkToken(string token)
{
    if (token.empty())
    {
        return;

    }

    string type = "Unknown";
    bool isValid = true;

    if (token == "cout" || token == "endl" || token == "int" || token == "float" || token == "return")
    {
        type = "Keyword";
    }
    else if (token == "<<" || token == "+")
    {
        type = "Operator";
    }
    else if (token == "(" || token == ")" || token == "}" || token == "{" )
    {
        type = "Initializer";
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
        for (size_t i = 0; i < token.length(); i++)
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

    for (size_t a = 0; a <= expr.length(); a++)
    {
        if (a == expr.length() || expr[a] == ' ' || expr[a] == '\t' || expr[a] == '\r')
        {
            string token = "";
            for (int i = start; i < a; i++)
            {
                token += expr[i];
            }

            checkToken(token);
            start = a + 1;
        }
    }
}

int main()
{

    ofstream MyFile("exp3.txt");
    MyFile << R"(
    int main ( ) {
    cout << "Hello" ;
    int x ;
    float y ;
    return x + y ;
    }
)";
    MyFile.close();

    string text;
    ifstream readfile("exp3.txt");


    while (getline(readfile, text))
    {
        cout << text << endl<< endl;
    }
    cout << "----------------------------------------------------------" << endl;

    readfile.close();
    readfile.open("exp3.txt");

    while (getline(readfile, text))
    {
        tokenizeExpression(text);
    }
    cout << "__________________________________________________________" << endl;

    readfile.close();
    return 0;
}
