// leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
    bool sign(string::iterator& S_pointer, string::iterator& D_pointer, string::iterator start)
    {
        if (*start <= '9')
        {
            if (*start == '-' || *start == '+')
                S_pointer = start;

            else if (*start == '.')
            {
                D_pointer = start;
            }

            else if (*start < '0')
                return false;
            return true;

        }
        else
            return false;
    }

    bool re(string::iterator endpoint, string::iterator& pointer, string::iterator start, string::iterator end)
    {
        for (string::iterator it = start;it != end;it++)
        {
            if (*it == '.')
            {
                if (pointer == endpoint)
                    pointer = it;
                else
                    return false;
            }
            else if (*it > '9' || *it < '0')
                return false;

        }
        return true;
    }


    bool isNumber(string s) {
        string::iterator E_pointer = s.end();
        string::iterator FS_pointer = s.end();
        string::iterator SS_pointer = s.end();
        string::iterator FD_pointer = s.end();
        string::iterator SD_pointer = s.end();
        if (s.empty())
            return false;
        if (sign(FS_pointer, FD_pointer, s.begin()))
        {
            for (string::iterator it = s.begin();it != s.end();it++)
            {
                if (*it == 'e' || *it == 'E')
                {
                    if (E_pointer != s.end())
                    {
                        return false;
                    }
                    E_pointer = it;
                }
            }

            if (E_pointer == s.end())
            {
                bool temp = re(s.end(), FD_pointer, s.begin() + 1, s.end());
                if (FS_pointer != s.end())
                {
                    if (FS_pointer + 1 == s.end())
                        return false;
                }
                if (FD_pointer != s.end())
                {
                    if (FD_pointer + 1 == s.end())
                    {
                        if (FD_pointer == s.begin())
                            return false;
                        else if (*(FD_pointer - 1) > '9' || *(FD_pointer - 1) < '0')
                            return false;
                    }
                }
                return temp;
            }
            else
            {

                if (E_pointer + 1 == s.end() || E_pointer == s.begin())
                    return false;
                if (*(E_pointer - 1) > '9' || *(E_pointer - 1) < '0')
                    return false;

                bool f = re(s.end(), FD_pointer, s.begin() + 1, E_pointer);
                if (FS_pointer != s.end())
                {
                    if (FS_pointer + 1 == s.end())
                        return false;
                }
                if (FD_pointer != s.end())
                {
                    if (FD_pointer + 1 == E_pointer && FD_pointer == s.begin())
                        return false;
                }
                if (sign(SS_pointer, SD_pointer, E_pointer + 1) && f)
                {
                    if ((SS_pointer != s.end() || SD_pointer != s.end()) && E_pointer + 1 == s.end())
                        return false;
                    bool sec = re(s.end(), SD_pointer, E_pointer + 2, s.end());
                    if (SS_pointer != s.end())
                    {
                        if (SS_pointer + 1 == s.end())
                            return false;
                    }
                    if (SD_pointer != s.end())
                    {/*
                        if (SD_pointer + 1 == s.end())*/
                            return false;
                    }
                    
                    return sec;
                }
                return false;
            }
        }
        else
            cout << "here";
        return false;
    }


    int getSum(int a, int b) {
        unsigned int A = a;
        unsigned int B = b;
        unsigned int c = A ^ B;
        unsigned int d =A & B;
        d = d << 1;
        while (d != 0)
        {
            unsigned  int e = c ^ d;
            unsigned  int f = c & d;
            f = f << 1;
            c = e;
            d = f;
            cout << f <<"\n";
        }
        if (c <= INT_MAX)
            return static_cast<int>(c);

        if (c >= INT_MIN)
            return static_cast<int>(c - INT_MIN) + INT_MIN;
    }
int main()
{
    cout << getSum(-1, 1);
}



