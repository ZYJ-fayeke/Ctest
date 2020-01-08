
#include <bits/stdc++.h>

using namespace std;

#define Up(i,a,b) for(int i = a; i <= b; i++)



int main()

{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        stack<int> s;
        string str;
    getline(cin,str);
        Up(i,0,6)
        {

            if(isdigit(str[i]))

            {

                s.push(str[i]-'0');

            }

            else if(str[i]=='x' || str[i]=='/')

            {

                int _ = s.top();

                s.pop();

                if(str[i] == 'x')

                {

                    _ *= (str[++i]-'0');

                }

                else

                {

                    _ /= (str[++i]-'0');
                }
            s.push(_);
            }
            else if(str[i]=='+' || str[i]=='-')
            {
                if(str[i] == '+')
                {
                    s.push(str[++i]-'0');
                }
                else
                {
                    s.push(-(str[++i]-'0'));
            }
            }
        }
        int sum = 0;
        while(!s.empty())
        {
            int _ = s.top();
            sum += _;
            s.pop();
        }
        printf("%s\n",sum==24 ? "Yes" : "No");
    }
    return 0;

}
