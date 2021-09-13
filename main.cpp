#include <bits/stdc++.h>

using namespace std;

//general
#define FOR(i, v) for (auto i: v)
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000005;
ll INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
#define all(v) v.begin(), v.end()
#define count(v, i) count(all(v), i)

//for vectors
#define push push_back
#define pop pop_back
#define vec vector
#define max(v) * max_element(all(v))
#define min(v) * min_element(all(v))
#define sum(v) accumulate(all(v), 0)
template < class T >
    int ind(vec < T > v, T a) {
        int i = find(all(v), a) - v.begin();
        return i;
    }
typedef vec < int > vi;
typedef vec < string > vs;

vi range(int a = 0, int b = 0, int c = 1) {
    if (b == 0 && c == 1) {
        b = a;
        a = 0;
    }
    vi v;
    if (c > 0) {
        for (int i = a; i < b; i += c) v.push(i);
    } else {
        for (int i = a; i > b; i += c) v.push(i);
    }
    return v;
}
template < class T >
    vec < T > sub(vec < T > a, vi b) {
        vec < T > v;
        FOR(i, b) v.push(a[i]);
        return v;
    }
template < class T >
    vec < T > rev(vec < T > v) {
        reverse(all(v));
        return v;
    }
template < class T >
    vec < T > sort(vec < T > v, int r = 0) {
        if (r) {
            sort(all(v));
            v = rev(v);
        } else sort(all(v));
        return v;
    }
template < class T >
    vec < T > uniq(vec < T > a) {
        vec < T > v;
        FOR(i, a)
        if (ind(v, i) == v.size()) v.push(i);
        return v;
    }
string to_string(string s) {
    return s;
}
template < class T >
    string join(vec < T > v, string s = "") {
        string k;
        if (v.size() > 0) {
            FOR(i, range(v.size() - 1))
            k += to_string(v[i]) + s;
            k += to_string(v[v.size() - 1]);
            return k;
        } else return "";
    }
template < class T >
    vec < pair < int, T >> enumerate(vec < T > v) {
        vec < pair < int, T >> v1;
        FOR(i, range(v.size())) v1.push(make_pair(i, v[i]));
        return v1;
    }

template < class T >
    vec < T > for_each(vec < T > v, T( * f)(T)) {
        vec < T > v1;
        FOR(i, v) v1.push(f(i));
        return v1;
    }
template < class T >
    vec < T > filter(vec < T > v, int( * f)(T)) {
        vec < T > v1;
        FOR(i, v)
        if (f(i)) v1.push(i);
        return v1;
    }
template < class T >
    T reduce(vec < T > v, T( * f)(T, T)) {
        T a = f(0, v[0]);
        FOR(i, range(1, v.size())) a = f(a, v[i]);
        return a;
    }
string reduce(vec < string > v, string( * f)(string, string)) {
    string a = f("", v[0]);
    FOR(i, range(1, v.size())) a = f(a, v[i]);
    return a;
}

//for pairs
#define f first
#define s second
#define mp make_pair
typedef pair < int, int > pii;
typedef pair < int, string > pis;
typedef pair < string, int > psi;
typedef pair < string, string > pss;

//for maps
typedef map < string, int > msi;
typedef map < int, string > mis;
#define add emplace

template < class T1, class T2 >
    vec < T1 > keys(map < T1, T2 > m) {
        vec < T1 > v;
        FOR( & i, m) v.push(i.f);
        return v;
    }
template < class T1, class T2 >
    vec < T2 > values(map < T1, T2 > m) {
        vec < T2 > v;
        FOR( & i, m) v.push(i.s);
        return v;
    }
template < class T1, class T2 >
    vec < pair < int, T1 >> enumerate(map < T1, T2 > m) {
        vec < pair < int, T1 >> v;
        FOR(i, range(m.size())) v.push(mp(i, keys(m)[i]));
        return v;
    }

template < class T1, class T2 >
    map < T1, T2 > for_each(map < T1, T2 > m, pair < T1, T2 > ( * f)(T1, T2)) {
        map < T1, T2 > m1;
        FOR(i, range(m.size())) m1.insert(f(keys(m)[i], values(m)[i]));
        return m1;
    }
template < class T1, class T2 >
    map < T1, T2 > filter(map < T1, T2 > m, int( * f)(T1, T2)) {
        map < T1, T2 > m1;
        FOR(i, range(m.size()))
        if (f(keys(m)[i], values(m)[i])) m1.insert(mp(keys(m)[i], values(m)[i]));
        return m1;
    }

//for strings
#define str string

string to_low(string s) {
    transform(all(s), s.begin(), ::tolower);
    return s;
}
string to_up(string s) {
    transform(all(s), s.begin(), ::toupper);
    return s;
}
string to_title(string s) {
    s[0] = toupper(s[0]);
    return s;
}
int is_up(string s) {
    int b = s == to_up(s);
    return b;
}
int is_low(string s) {
    int b = s == to_low(s);
    return b;
}
int is_title(string s) {
    int b = s == to_title(s);
    return b;
}
string swap_case(string s) {
    string k = "";
    FOR(i, s) {
        if (isupper(i)) k += tolower(i);
        else k += toupper(i);
    }
    return k;
}
string sub(string s, vi b) {
    string k = "";
    FOR(i, b) k.push(s[i]);
    return k;
}
string rev(string s) {
    reverse(all(s));
    return s;
}
string strip(string s, char t = ' ') {
    int c, k;
    FOR(i, range(s.size()))
    if (s[i] != t) {
        c = i;
        break;
    }
    FOR(i, range(s.size()))
    if (s[s.size() - i - 1] != t) {
        k = s.size() - i;
        break;
    }
    return s.size() == 0 ? "" : sub(s, range(c, k));
}
vs split(string s, char c = ' ') {
    s = strip(s);
    vs v;
    string k;
    size_t a = s.size() - rev(s).find(c);
    FOR(i, range(a)) {
        if (s[i] == c) {
            v.push(k);
            k = "";
            continue;
        } else k += s[i];
    }
    v.push(sub(s, range(a, s.size())));
    return s.size() == 1 ? (vs) {
        s
    } : v;
}
string replace_all(string s, string a, string b) {
    vs v = split(s);
    FOR(i, range(v.size()))
    if (v[i] == a) {
        v[i] = b;
        break;
    }
    return join(v, " ");
}
vec < pair < int, char >> enumerate(string s) {
    vec < pair < int, char >> v;
    FOR(i, range(s.size())) v.push(mp(i, s[i]));
    return v;
}

string for_each(string s, char( * f)(char)) {
    string s1;
    FOR(c, s) s1 += f(c);
    return s1;
}
string filter(string s, int( * f)(char)) {
    string s1;
    FOR(c, s)
    if (f(c)) s1 += f(c);
    return s1;
}

//I/O   
template < typename T >
    void print(T a) {
        cout << a;
    }
void print(string s) {
    cout << s;
}
template < class T, typename X = string >
    void print(vec < T > v, X s = " ");
template < class T1, class T2, typename X1 = string, typename X2 = string >
    void print(map < T1, T2 > m, X1 a = " ", X2 b = "\n");
template < class T1, class T2 >
    void print(pair < T1, T2 > p, string s = " ") {
        print(p.f);
        print(s);
        print(p.s);
    }
template < class T, typename X = string >
    void print(vec < T > v, X s) {
        int c = v.size() - 1;
        if (v.size() != 0)
            FOR(i, range(c)) {
                print(v[i]);
                print(s);
            }
        else print("");
    }
template < class T1, class T2, typename X1 = string, typename X2 = string >
    void print(map < T1, T2 > m, X1 a, X2 b) {
        int c = m.size() - 1;
        if (m.size() != 0) {
            FOR(i, range(c)) {
                print(keys(m)[i]);
                print(a);
                print(values(m)[i]);
                print(b);
            }
            print(keys(m)[c]);
            print(a);
            print(values(m)[c]);
        } else print("");
    }

template < typename T >
    void printb(T a) {
        cout << a;
    }
void printb(char c) {
    cout << "'" << c << "'";
}
void printb(string s) {
    cout << '"' << s << '"';
}
template < class T >
    void printb(vec < T > v);
template < class T1, class T2, typename X = string >
    void printb(map < T1, T2 > m, X b = "\n");
template < class T1, class T2 >
    void printb(pair < T1, T2 > p) {
        printb("(");
        printb(p.f);
        printb(", ");
        printb(p.s);
        printb(")");
    }
template < class T >
    void printb(vec < T > v) {
        int c = v.size() - 1;
        printb("[");
        if (v.size() != 0) {
            FOR(i, range(c)) {
                printb(v[i]);
                printb(", ");
            }
            printb(v[c]);
        }
        printb("]");
    }
template < class T1, class T2, typename X = string >
    void printb(map < T1, T2 > m, X b) {
        int c = m.size() - 1;
        printb("{");
        if (m.size() != 0) {
            FOR(i, range(c)) {
                printb(keys(m)[i]);
                printb(": ");
                printb(values(m)[i]);
                printb(", ");
            }
            printb(keys(m)[c]);
            printb(": ");
            printb(values(m)[c]);
        }
        printb("}");
    }

template < typename T >
    T input(T a, string s = "") {
        cout << s;
        cin >> a;
        return a;
    }
string input(string s, string a = "") {
    cout << a;
    getline(cin, s);
    return s;
}
template < class T1, class T2 >
    pair < T1, T2 > input(pair < T1, T2 > p, string s = "") {
        cout << s;
        T1 a = input(a);
        T2 b = input(b);
        p = mp(a, b);
        return p;
    }
template < class T >
    vec < T > input(vec < T > v, int n = 1, string s = "") {
        cout << s;
        T x;
        v.clear();
        FOR(i, range(n)) v.push(input(x));
        return v;
    }
template < class T1, class T2 >
    map < T1, T2 > input(map < T1, T2 > m, int n = 1, string s = "", int x = 1) {
        cout << s;
        T1 a;
        T2 b;
        FOR(i, range(n)) {
            a = input(a);
            b = x == 1 ? input(b) : input(b, x);
            m[a] = b;
        }
        return m;
    }

//extras
vi factors(int n) {
    vi v;
    FOR(i, range(1, n + 1))
    if (n % i == 0) v.push(i);
    return v;
}
int is_prime(int n) {
    int b = factors(n).size() == 2;
    return b;
}
vi prime_factors(int n) {
    vi v;
    FOR(i, factors(n))
    if (is_prime(i)) v.push(i);
    return v;
}
int factorial(int n) {
    int f = 1;
    FOR(i, range(1, n + 1)) f *= i;
    return f;
}

//main

int main() {
    ios_base::sync_with_stdio(false);
}
