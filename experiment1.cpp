#include <iostream>
#include <string>
using namespace std;

void fun (string a)
{
    int b=a.length();
    if (b>=2 && a[0]=='/' && a[1]=='/')
    {
        cout<< "This is single line comment."<<endl;
    }
    else if(b>=4 && a[0]=='/' && a[1]=='*' && a[b-2]=='*' && a[b-1]=='/' )
    {
        cout << "This is multi line comment."<<endl;
    }
    else
    {
        cout<< "Undefind Syntax"<<endl<<endl;
    }
}

void fun1(string b)
{
    int w=0;
    for(int i=0; i<b.length(); i++)
    {
        char ch=b[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=')
        {
            cout<< "Operator : "<< ch <<endl;
            w++;
        }
    }
    if(w==0)
    {
        cout<< "No operator here."<<endl<<endl;
    }
}

void fun2(string c)
{
    bool b=true;
    if(c.length()==0)
    {
        b=false;
    }
    else
    {
        for(int i=0; i<c.length(); i++)
        {
            if(c[i]<48 || c[i]>57)
            {
                b=false;
            }
        }
    }

    if(b)
    {
        cout<< "Numeric Constant."<<endl<<endl;
    }
    else
    {
        cout<< "Not a Numeric"<<endl<<endl;
    }
}

void fun4(string d)
{
    bool b=true;
    char ch =d[0];

    if(d.length()==0)
    {
        cout<< "No value"<<endl<<endl;

    }

    if(!((ch>=65 && ch<=90) || (ch >=97 && ch <=122) || ch==95 ))
    {
        b=false;
    }

    if(b)
    {
        for(int i=1; i<d.length(); i++)
        {
            char a=d[i];
            if(!((ch>=65 && ch<=90) || (ch >=97 && ch <=122) || ch==95 || (ch >=48 && ch<=57)))
            {
                b=false;
                break;
            }
        }
    }

    if(b)
    {
        cout<< "Valid."<<endl<<endl;
    }
    else
    {
        cout<< "Not a valid"<<endl<<endl;
    }

}


int main()
{

    int a;
    string b;

    do
    {
        cout << "Select an option:" <<endl<<endl;
        cout << "1. Check Comment " <<endl;
        cout << "2. Check Operators" <<endl;
        cout << "3. Check Numeric Constant" <<endl;
        cout << "4. Check Identifier or Not" <<endl;
        cout << "5. Exit." <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter option (1-5) : ";
        cin >>a;

        if (a >= 1 && a <= 4)
        {
            cout << "Enter Value : ";
            cin >>b;
        }

        switch(a)
        {
        case 1:
            fun(b);
            break;
        case 2:
            fun1(b);
            break;
        case 3:
            fun2(b);
            break;
        case 4:
            fun4(b);
            break;
        case 5:
            cout << "Exiting...(press enter)" << endl;
            break;
        default:
            cout << "select an option between 1 to 5" <<endl<<endl;
        }

    }
    while(a!= 5);



    return 0;
}
