#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
#define FIO                 ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl                '\n'
#define pb                  push_back
#define eb                  emplace_back
#define ins                  insert
#define F                   first
#define S                   second
#define umapll               unordered_map<ll ,ll>
#define vt                  vector
#define vll                 vector<ll>
#define pll                 pair<ll,ll>
#define vpll                vector<pll>
#define vvll                vector<vll>
#define all(v)              v.begin(),v.end()
#define rall(v)             v.rbegin(), v.rend()
#define fps(x,y)            fixed << setprecision(y) << x
#define w(t)                ll t;cin>>t;while(t--)
#define FOR(i,n)            for(ll i=0;i<n;i++)
#define REV(i,n)            for(ll i=n-1;i>=0;i--)
#define ffor(i,a,b)         for(ll i=a;i<=b;i++)
#define rfor(i,b,a)         for(ll i=b;i>=a;i--)
#define it(i,v)             for(auto i=v.begin();i!=v.end();i++)
#define setbits(x)          __buildin_popcount(x)
#define MAX                 1000001
#define INF                 0x3f
const ll mod=               1e9+7;
const double pi=            3.1415926536;
ll powerm(ll, ll, ll);
ll power(ll, ll);
ll dx[]={-1,0,1,0}; //urdl
ll dy[]={0,1,0,-1};
//void solve(){ }
//cout<<"Case #"<<test<<": "<<ans;
//=========================================================================================================

struct student{
    string id;
    int rank;
    vector<int> choice;
};
bool fun(student s1,student s2){
    return s1.rank<s2.rank;
}

int main(){

    FIO
	ifstream inFile1, inFile2;
    ofstream outFile;


    inFile1.open("courses", ios::in);
	int cn;
    cn=20;
    // cin>>cn;

    unordered_map<int,int> seat;
    FOR(i,cn){
        int cid,cseat;
        char cha;
        inFile1>>cid>>cha>>cseat;
        seat[cid]=cseat;
    }

	inFile2.open("students", ios::in);
    int sn;
    sn=10000;
    // cin>>sn;

    vector<student> stu;
    vector<string> studentId;
    FOR(i,sn){
        string str;
        getline(inFile2,str);
        vector<string> v;
        stringstream ss(str);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        student s;
        s.id=v[0],
        studentId.pb(v[0]);
        s.rank=stoi(v[1]);
        FOR(j,cn){
            s.choice.pb(stoi(v[j+2]));
        }
        stu.push_back(s);
    }

    sort(stu.begin(),stu.end(),fun);
    unordered_map<string,int> ans;

    FOR(i,sn){
        FOR(j,cn){
            if(seat[stu[i].choice[j]]>0) {
                ans[stu[i].id]=stu[i].choice[j];
                seat[stu[i].choice[j]]--;
                break;
            }
        }
    }
	outFile.open("allotments");
    FOR(i,studentId.size()){
        outFile<<studentId[i]<<", "<<ans[studentId[i]]<<endl;
    }

    return(0);
}
