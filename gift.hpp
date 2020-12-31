#ifndef GIFT_FILE
#define GIFT_FILE

#include <bits/stdc++.h>
#include "csv.hpp"

using namespace std;

void xmasTree()
{
    cout<<"\033[0;32m    *    \033[0m\n";
    cout<<"\033[0;32m    *    \033[0m\n";
    cout<<"\033[0;32m   ***   \033[0m\n";
    cout<<"\033[0;32m  *****  \033[0m\n";
    cout<<"\033[0;32m ******* \033[0m\n";
    cout<<"\033[0;32m*********\033[0m\n";
    cout<<"  *****  \n\n";
}

class Gift: private csvInput
{
    public:
        ~Gift();
        void makeGift(string,string,string,string,string,string);
};

Gift::~Gift()
{}

void Gift::makeGift(string file_1, string file_2, string file_3, string file_4, string file_5, string valid_word)
{
    ifstream in(file_4);
    ofstream out(file_5);
    long double sum,upLimit,downLimit;
    string wishlist;
    in>>upLimit>>downLimit;
    this->data_csv_read(file_1);
    vector<vector<string>> kids=this->getArray(),wishes,items;
    this->clearArray();
    this->data_csv_read(file_2);
    wishes=this->getArray();
    this->clearArray();
    this->data_csv_read(file_3);
    items=this->getArray();
    for(size_t i=0;i<kids.size();++i)
        if(kids[i][kids[i].size()-1]==valid_word)
        {
            sum=0;
            wishlist="\0";
            for(size_t j=0;j<wishes[i].size();++j)
                for(size_t k=0;k<items.size();++k)
                    if(items[k][0]==wishes[i][j]&&sum+stold(items[k][items[k].size()-1])<=upLimit)
                    {
                        sum+=stold(items[k][items[k].size()-1]);
                        wishlist+=(wishes[i][j]+',');
                        break;
                    }
            if(wishlist=="\0")
                out<<kids[i][0]<<','<<kids[i][1]<<','<<"Nokia_2.2,"<<kids[i][kids[i].size()-2]<<'\n';
            else if(upLimit-sum<=0)
                out<<kids[i][0]<<','<<kids[i][1]<<','<<wishlist<<kids[i][kids[i].size()-2]<<'\n';
            else
                out<<kids[i][0]<<','<<kids[i][1]<<','<<wishlist<<upLimit-sum<<"xLollipops,"<<kids[i][kids[i].size()-2]<<'\n';
        }
        else
            out<<kids[i][0]<<','<<kids[i][1]<<",2xCoal,"<<downLimit-1<<"xLollipops,"<<kids[i][kids[i].size()-2]<<'\n';
    this->clearArray();
    in.close();
    out.close();
}

#endif