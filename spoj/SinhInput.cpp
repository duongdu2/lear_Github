#include <bits/stdc++.h>
#include <random>
#define fi first
#define se second
using namespace std;

typedef pair<long long, long long> pt;
const long long rngLim = 43*1e8;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long CreLL(long long l, long long r)
{ //sinh 1 so nguyen bat ki trong doan [l, r].
    return rng() % (r - l + 1) + l;
}
double CreDB(int l, int r)
{ //sinh 1 so thap phan bat ki trong doan [l, r], l va r phai co so chu so nho hon 5.
    double scale = rng() / (double) rngLim;
    //them 1 vai so 0 vao sau dau phay de tang tinh ngau nhien:
    int reduce = CreLL(1, 12);
    for(int i = 1; i <= 3; i++)
    	if(reduce == 9 + i) scale /= 10*i;
    return scale * (r - l) + l;
}

//sinh test nho
void createTest(ofstream &fout)
{
    int T = CreLL(1, 10);
    fout << T << endl;
    while(T--){
    	int N = CreLL(3,10);
        fout << N << endl;
		for(int i = 0; i < N; i++){
			fout << CreLL(1, 100) << " ";
		}
        fout << endl;
    }
}
//sinh test vua
void createTest2(ofstream &fout)
{
    int T = CreLL(10, 50);
    fout << T << endl;
    while(T--){
    	int N = CreLL(3,50);
        fout << N << endl;
		for(int i = 0; i < N; i++){
			fout << CreLL(1, 1e4) << " ";
		}
        fout << endl;
    }
}
//sinh test lon
void createTest3(ofstream &fout)
{
    int T = CreLL(50, 100);
    fout << T << endl;
    while(T--){
    	int N = CreLL(3,100);
        fout << N << endl;
		for(int i = 0; i < N; i++){
			fout << CreLL(1, 1e9) << " ";
		}
        fout << endl;
    }
}

//cho nay khong can sua
int main()
{
    srand(time(NULL));
    int N = 15;
    for (int i = 0; i < N; i++)
    {
        string s;
        ostringstream convert;
        convert << i + 1;
        s = convert.str();
        string input = "test/" + s + ".in";
        ofstream fout(input.c_str());
        if (i < 5)
            createTest(fout);
        else if (i < 10)
            createTest2(fout);
        else
            createTest3(fout);
        fout.close();
        cout << "Created test:" << i + 1 << endl;
    }
    return 0;
}
