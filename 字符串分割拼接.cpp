#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string origin;
    char p;
    string s;

    getline(cin, origin);
    // 读取分隔符p
    cin >> p;
    cin.ignore(); // 吃掉p后面那一个空格，剩下整行全部是s
    getline(cin, s);

    vector<string> sum;
    string cur;
    int len = origin.size();

    for (int i = 0; i < len; i++)
    {
        char curcha = origin[i];
        if (curcha == p)
        {
            // ? 不管cur是空还是非空，都push！！！这就是生成""的关键
            sum.push_back(cur);
            cur.clear();
        }
        else
        {
            cur += curcha;
        }
    }
    // 循环结束，把最后一段压入
    sum.push_back(cur);


    // ========== 第一行输出 数组 ["a", "", "c"] ==========
    cout << "[";
    for (int i = 0; i < sum.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << "\"" << sum[i] << "\"";
    }
    cout << "]" << endl;


    // ========== 第二行 join：元素之间插入s ==========
    for (int i = 0; i < sum.size(); i++)
    {
        if (i > 0)
            cout << s;
        cout << sum[i];
    }
    cout << endl;

    return 0;
}

