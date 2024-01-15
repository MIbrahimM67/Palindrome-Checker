
#include <iostream>
#include <stack>
#include <string>

bool Check(std::string& Expression, std::stack<std::string>&s1,std::string &HalfExp)
{

    int len = Expression.length();
    if (len % 2 == 0)
    {
        for (int i = 0; i <len / 2; i++)
        {
            std::string temp = "";
            temp += Expression[i];
           
            s1.push(temp);
            temp.clear();
        }
       
       for (int i = (len / 2) ; i <len; i++)
        {
           HalfExp += Expression[i];
        }
       for (int i = 0; i <= s1.size(); i++)
       {
           std::string temp = "";
           temp += HalfExp[i];
           if (temp != s1.top())
           {
               return false;
           }
           s1.pop();
           temp.clear();
       }
       return true;



    }
    else {
        for (int i = 0; i < len / 2; i++)
        {
            std::string temp = "";
            temp += Expression[i];

            s1.push(temp);
            temp.clear();
        }

        for (int i = (len / 2)+1; i < len; i++)
        {
            HalfExp += Expression[i];
        }
        for (int i = 0; i <= s1.size(); i++)
        {
            std::string temp = "";
            temp += HalfExp[i];
            if (temp != s1.top())
            {
                return false;
            }
            s1.pop();
            temp.clear();
        }
        return true;

    }
    return s1.empty();


}

int main()
{
    std::string Expression,HalfExp;
    std::stack<std::string> s1;
    std::cout << "Enter the string to check!\n";
    std::getline(std::cin, Expression);

    if (Check(Expression, s1, HalfExp))
    {
        std::cout << "it is  palindrome";
    }
    else
        std::cout << "not palindrome";

}

