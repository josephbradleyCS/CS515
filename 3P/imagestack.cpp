#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv) {
  //cout << "test1" << endl;
  stringstream strstr;

  ifstream infil;
  infil.open(argv[1]);
  //cout << argv[1] << endl;

  if (!infil) {
    cout << "Can not open argv for input";
  }

  //cout << "test1" << endl;

  if (infil.fail()) {
    cout << "Can not open: " << argv[1] << " for input\n";
    exit(1);
  }

  //cout << "test1" << endl;


  strstr << infil.rdbuf();
  string p2;
  int width;
  int height;
  int greyscale;
  strstr >> p2;
  strstr >> width;
  strstr >> height;
  strstr >> greyscale;

  //cout << greyscale << endl;

  strstr.str("");
  infil.close();

  //cout << "test1" << endl;


  /////////////////////////////

  int*** arr = new int**[height];
  //cout << "test2" << endl;


  int numfiles = argc - 2;
  //cout << numfiles << endl;

  for (int i = 0; i < height; i++) {
    arr[i] = new int*[width];
    for (int j = 0; j < width; j++) {
      arr[i][j] = new int[numfiles];
      // for (int l = 0; l < numfiles; l++) {
      //   arr[i][j][l] = 0;
      // }
    }
  }

  //cout << "test3" << endl;


  for (int l = 1; l < argc - 1; l++) {
    //cout << "test4" << endl;

    stringstream ss;

    ifstream infile;
    infile.open(argv[l]);

    if (!infile) {
      cout << "Can not open argv for input";
    }

    //cout << "test2" << endl;
    if (infile.fail()) {
      cout << "Can not open: " << argv[l] << " for input";
      exit(1);
    }
    //cout << infile.rdbuf();

    ss << infile.rdbuf();
    string p2;
    int width;
    int height;
    int greyscale;

    ss >> p2;
    ss >> width;
    ss >> height;
    ss >> greyscale;

    //cout << p2 << " " << width << " " << height << " " << greyscale << endl;

    //cout << "test4" << endl;


    //cout << "test5" << endl;

    for (int j = 0; j < height; j++) {
      for (int k = 0; k < width; k++) {
        //cout << "ROW:" << j << " COLS: " << k << " PIC: " << l << endl;
        ss >> arr[j][k][l-1];
      }
    }
  }



//   cout << "test1" << endl;
//
     ofstream inout;
//
    inout.open(argv[argc-1]);
//
//
//
//
  if (inout.fail()) {
    cout << "Error opening output file\n";
    exit(1);
  }
//
   inout << "P2" << endl << width << " " << height << endl << greyscale << endl;
//
  int l = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int* th = new int[numfiles]{0};
      for (l = 0; l < numfiles; l++) {
        th[l] = arr[i][j][l];
      }
//
      sort(th, th+numfiles);
//

      int a = 0;
      if (numfiles % 2 == 0) {
        a = (th[(numfiles)/2 -1] + th[((numfiles)/2)])/2;
      } else {
        a = th[numfiles/2];
      }
      inout << a << " ";
//       //cout << "\t median: " << th[(int)(numfiles/2)] << " ";
      delete[] th;
//       if (th[(int)(numfiles/2)] != 0) {
//         //cout << th[(int)(numfiles/2)] << " ";
    }
      inout << '\n';
  }
//     inout << endl;

//
inout.close();


//cout << "If you see this and the program crashes its the deletes" << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      delete[] arr[i][j];
    }
    delete[] arr[i];
  }
  delete[] arr;
}
