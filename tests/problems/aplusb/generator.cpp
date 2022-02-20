#include <iostream>     /* cin, cout, string, ... */
#include <vector>       /* vector */
#include <fstream>      /* ofstream */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/stat.h>   /* stat for mkdir */
// #include <sys/types.h>  

using namespace std;

/**
 * @brief Sample problem generator
 * The problem is a + b
 * 
 * Input contains two integers a and b
 * Output must contain the result of the a + b
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

void makeInitTests();
void makeEdgeTests();
void makeAutoTests();

void init() {
  // initialize random seed
  srand (time(NULL));
  
  // initialize string vectors
  idata = vector<string>();
  odata = vector<string>();

  // make directory
  mkdir("in", 0777);
  mkdir("out", 0777);
}

// random function
int getRand(int low=0, int high=INT32_MAX, bool canBeNegative=false) {
  int result = rand() % (high - low + 1) + low;

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
    outf << odata[i] << endl;

    i++;
  }

  inf.close();
  outf.close();
  
  idata.clear();
  odata.clear();
}

// make a string to the specified string vector
void makeTest(string input, string output) {
  stepTest();
  idata.push_back(input);
  odata.push_back(output);
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
  makeTest("1 1", "2");

  // case 2
  makeTest("3 9", "12");
}

// generates edge test-cases and saves them
void makeEdgeTests() {
  // case 3 - zeros
  {
    makeTest("0 0", "0");
  }

  // case 3 - oppisite
  {
    makeTest("-1 1", "0");
  }

  // case 4 - large
  {
    ll a = INT32_MAX;
    ll b = INT32_MAX;
    ll s = a + b;
    string input = to_string(a) + " " + to_string(b);
    string output = to_string(s);
    makeTest(input, output);
  }
}

// generates some automatic test-cases and saves them
void makeAutoTests() {
  repeat(AUTO_TESTS) {
    ll a = getRand(0, RAND_MAX, true);
    ll b = getRand(0, RAND_MAX, true);
    ll s = a + b;
    string input = to_string(a) + " " + to_string(b);
    string output = to_string(s);
    makeTest(input, output);
  }
}