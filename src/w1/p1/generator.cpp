#include <iostream>     /* cin, cout, string, ... */
#include <vector>       /* vector */
#include <fstream>      /* ofstream */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/stat.h>   /* stat for mkdir */
// #include <sys/types.h>  

using namespace std;

/**
 * @brief To the power of huge
 * The problem is to compute the result of a^n
 * n is too large so the result must be divided by
 * 1e9+7 and the remainder is the final answer.
 * 
 * for example:
 *  2^3 = 8 % (1e9+7) = 8
 * 
 *  10^10 = 10000000000 % (1e9+7) = 999999937
 */

// global
const bool DEBUG = true;
int test_num = 1;
enum IOType { INPUT, OUTPUT };
#define repeat(n) for(int ijk=(n); ijk>0; ijk--)
typedef vector<string> srr;
typedef long long ll;

// configs
const int AUTO_TESTS = 20;  /* the number of tests that will be generated automatically */

// datastructures
srr idata;     // Stores the input.txt data
srr odata;    // Stores the output.txt data

// solve function
ll MOD = 1e9 + 7;
ll solve(ll a, ll b) {
  a %= MOD;
  ll r = 1;

  while(b > 0) {
    if (b % 2 == 1) {
      r = (r * a) % MOD;
    }

    a = (a * a) % MOD;

    b >>= 1;
  }

  return r;
}

void makeInitTests();
void makeEdgeTests();
void makeAutoTests();

// append a string to datastructures
void append(IOType type, string data) {
  (type == INPUT ? idata : odata).push_back(data);
}

void init() {
  // initialize random seed
  srand (time(0));
  
  // initialize string vectors
  idata = vector<string>();
  odata = vector<string>();

  // make directory
  mkdir("in", 0777);
  mkdir("out", 0777);
}

// random function
ll getRand(ll low=0, ll high=INT32_MAX, bool canBeNegative=false) {
  ll result = rand() % (high - low + 1) + low;

  if (canBeNegative) if (rand() % 2 == 0) result = -result;

  return result;
}

// steps one test forward
void stepTest() {
  if (DEBUG) cout << "Case [" << test_num << "] generated.\n";
}

// generates tests cases automatically
void generate() {
  init();
  makeInitTests();
  makeEdgeTests();
  makeAutoTests();
}

// saves an array of string to specified file
void save() {
  ofstream inf("in/input" + to_string(test_num) + ".txt");
  ofstream outf("out/output" + to_string(test_num) + ".txt");
  test_num++;

  int i=0;
  repeat(idata.size()) {
    inf << idata[i] << endl;

    i++;
  }

  int j=0;
  repeat(odata.size()) {
    outf << odata[j] << endl;

    j++;
  }

  inf.close();
  outf.close();
  
  idata.clear();
  odata.clear();
}

// make a string to the specified string vector
void makeTest() {
  stepTest();
  save();
}


int main()
{
  generate();
}

// generate some sample test-cases and saves them
// useful for problem statement
void makeInitTests() {
  // case 1
  {
    append(INPUT, "2 3");
    append(OUTPUT, "8");
    makeTest();
  }

  // case 2
  {
    append(INPUT, "10 10");
    append(OUTPUT, "999999937");
    makeTest();
  }
}

// generates edge test-cases and saves them
void makeEdgeTests() {
  // case 3 - zero power I
  {
    append(INPUT, "1 0");
    append(OUTPUT, "1");
    makeTest();
  }

  // case 4 - zero power II
  {
    append(INPUT, "2 0");
    append(OUTPUT, "1");
    makeTest();
  }

  // case 5 - one power
  {
    append(INPUT, "12 1");
    append(OUTPUT, "12");
    makeTest();
  }

  // case 6 - large
  {
    ll a = 3 * 1e15;
    ll b = 4 * 1e15;
    ll answer = solve(a, b);
    append(INPUT, to_string(a) + " " + to_string(b));
    append(OUTPUT, to_string(answer));
    makeTest();
  }
}

// generates some automatic test-cases and saves them
void makeAutoTests() {
  repeat(AUTO_TESTS) {
    ll a = getRand(1) * getRand(1);
    ll b = getRand(1) * getRand(1);
    ll answer = solve(a, b);
    append(INPUT, to_string(a) + " " + to_string(b));
    append(OUTPUT, to_string(answer));
    makeTest();
  }
}