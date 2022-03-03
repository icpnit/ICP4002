#include <iostream>     /* cin, cout, string, ... */
#include <vector>       /* vector */
#include <fstream>      /* ofstream */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/stat.h>   /* stat for mkdir */
#include <stack>
// #include <sys/types.h>  

using namespace std;

/**
 * @brief Simple Unit Shell Simulator
 * 
 * Only the cd and pwd
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

// random string
string strRand(int len) {
  string r = "";
  repeat(len) {
    r += (char)('a' + getRand(0, 25));
  }
  return r;
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
    append(INPUT, "5");
    append(INPUT, "pwd");
    append(OUTPUT, "/");
    append(INPUT, "cd /home");
    append(INPUT, "pwd");
    append(OUTPUT, "/home");
    append(INPUT, "cd opmc");
    append(INPUT, "pwd");
    append(OUTPUT, "/home/opmc");
    makeTest();
  }
}

// generates edge test-cases and saves them
void makeEdgeTests() {
  // case 3 - cd ..
  {
    append(INPUT, "7");
    append(INPUT, "cd a");
    append(INPUT, "pwd");
    append(OUTPUT, "/a");
    append(INPUT, "cd b/d");
    append(INPUT, "pwd");
    append(OUTPUT, "/a/b/d");
    append(INPUT, "cd ..");
    append(INPUT, "cd ../b/e");
    append(INPUT, "pwd");
    append(OUTPUT, "/a/b/e");
    makeTest();
  }

  // case 3 - cd ..
  {
    append(INPUT, "7");
    append(INPUT, "cd icpc/../icpc");
    append(INPUT, "pwd");
    append(OUTPUT, "/icpc");
    append(INPUT, "cd icpc/icpc/icpc/../a/../b");
    append(INPUT, "pwd");
    append(OUTPUT, "/icpc/icpc/icpc/b");
    append(INPUT, "cd /yeho/avaz");
    append(INPUT, "cd shod");
    append(INPUT, "pwd");
    append(OUTPUT, "/yeho/avaz/shod");
    makeTest();
  }
}

// generates some automatic test-cases and saves them
void makeAutoTests() {
  // Oof too complicated...
}