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

// append a string to datastructures
void append(IOType type, string data) {
  (type == INPUT ? idata : odata).push_back(data);
}

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
    // inf << idata[i] << " \n"[i+1<idata.size()];
    inf << idata[i] << endl;
    i++;
  }

  int o=0;
  repeat(odata.size()) {
    // outf << odata[o] << " \n"[i+1<idata.size()];
    outf << odata[o] << endl;

    o++;
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
    append(INPUT, "2");
    append(INPUT, "1 2");
    append(OUTPUT, "2");
    makeTest();
  }

  // case 2
  {
    append(INPUT, "4");
    append(INPUT, "4 6 8 10");
    append(OUTPUT, "-1");
    makeTest();
  }
}

// generates edge test-cases and saves them
void makeEdgeTests() {
  // case 3 - all primes
  {
    append(INPUT, "4");
    append(INPUT, "2 2 2 2");
    append(OUTPUT, "1");
    makeTest();
  }

  // case 4 - no primes
  {
    append(INPUT, "4");
    append(INPUT, "1 1 1 1");
    append(OUTPUT, "-1");
    makeTest();
  }

  // case 5 - prime in the middle
  {
    append(INPUT, "4");
    append(INPUT, "1 3 2 1");
    append(OUTPUT, "2");
    makeTest();
  }

  // case 5 - large array
  {
    append(INPUT, "10000");

    string arr = "";
    repeat(10000 - 1) {
      arr += "4 ";
    }

    arr += "3343";
    append(INPUT, arr);
    append(OUTPUT, "10000");
    makeTest();
  }

  // case 6 - large array
  {
    append(INPUT, "10000");

    string arr = "";
    repeat(10000 - 2) {
      arr += "4 ";
    }

    arr += "9437 4";
    append(INPUT, arr);
    append(OUTPUT, "9999");
    makeTest();
  }
}

// generates some automatic test-cases and saves them
void makeAutoTests() {
  // repeat(AUTO_TESTS) {
  //   ll a = getRand(0, RAND_MAX, true);
  //   ll b = getRand(0, RAND_MAX, true);
  //   ll s = a + b;
  //   string input = to_string(a) + " " + to_string(b);
  //   string output = to_string(s);
  //   makeTest(input, output);
  // }
}