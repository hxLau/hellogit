#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<cstdio>
#include<iomanip>
#include<fstream>
#include<algorithm>
using namespace std;

struct student
{
    string name;
    string sex;
    string score;
    double sc;
    student(){};
    student(string Name,string Sex,string Score,double Sc)
    {
        name=Name;
        sex=Sex;
        score=Score;
        sc=Sc;
    }
    bool operator <(const student &s) const
    {
         return (sc>s.sc)||((sc==s.sc)&&(name<s.name));
    }
};

double average(const vector<student>& s)
{
     double total=0;
     for(int i=0;i<s.size();i++)
     {
         total+=s[i].sc;
     }
     return total/double(s.size());
}

int main()
{
    vector<student> all,male,female;
    ifstream input;
    input.open("score.csv");
    string x;
    getline(input,x);
    
    string name,sex,score;
    while(getline(input,x))
    {
        stringstream ss(x);
        getline(ss,name,',');
        getline(ss,sex,',');
        getline(ss,score,',');
        sex.erase(0,1);
        score.erase(0,1);
        double sc=stod(score);
        student stu(name,sex,score,sc);
        
        if(stu.sex=="Female") female.push_back(stu);
        else male.push_back(stu);
        all.push_back(stu);
    }
    cout<<"全班同学的平均分为："<<fixed<<setprecision(1)<<average(all)<<endl;
    cout<<"男生的平均分为："<<setprecision(1)<<average(male)<<endl;
    cout<<"女生的平均分为："<<setprecision(1)<<average(female)<<endl;
    sort(all.begin(),all.end());
    for(int i=0;i<all.size();i++)
    {
        cout<<all[i].name<<" "<<all[i].sex<<" "<<all[i].score<<endl;
    }
    return 0;
}






























