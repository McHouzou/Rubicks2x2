#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<char> vi;
typedef vector<string> si;

class cube{
public:
  vector<vi> colours;
};

void fill_cube(cube &C, string c){
  C.colours.assign(6, vi());
  for (int i=0; i<6; i++){
    for (int j=0; j<4; j++){
      C.colours[i].push_back(c[i*4 + j]);
    }
  }
}

string cube_to_string(cube C){
  string s = "";
  for (int i=0; i<6; i++)
    for (int j=0; j<4; j++)
      s+=C.colours[i][j];
  return s;
}

void show_cube(cube &C){
  for (int i=0; i<6; i++){
    cout<<"Side "<<i<<":"<<endl;
    for (int j=0; j<4; j++){
      cout<<C.colours[i][j];
      if(j%2 != 0)
        cout<<endl;
    }
    cout<<endl;
  }
}

bool solved_cube(cube C){
  bool solved = true;
  char t;
  for (int i=0; i<6; i++){
    for (int j=0; j<4; j++){
      if(j == 0)
        t = C.colours[i][j];
      else if (t != C.colours[i][j]){
        solved = false;
        break;
      }
    if (solved == false)
      break;
    }
  }
  return solved;
}


cube move_cube(cube C, char move, char torque){
  switch (move){

    case 'r':
      if(torque == 'c'){
        int face[] = {0,1,2,3,4}, sites[] = {1, 3}, rot[] = {0,1,3,2};
        vector<char> temp;
        //Rotate the faces 0->1 first
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            temp.push_back(C.colours[face[i]][sites[j]]);
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            C.colours[face[i]][sites[j]] = temp[(i*2 + j +6)%8];

        //Rotate the 4th face
        temp.clear();
        for(int i=3; i<7; i++)
          temp.push_back(C.colours[face[4]][rot[i%4]]);
        for(int i=0; i<4; i++)
          C.colours[face[4]][rot[i]] = temp[i];
      }
      else{
        int face[] = {0,1,2,3,4}, sites[] = {1, 3}, rot[] = {0,1,3,2};
        vector<char> temp;
        //Rotate the faces 0->3 first
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            temp.push_back(C.colours[face[i]][sites[j]]);
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            C.colours[face[i]][sites[j]] = temp[(i*2 + j + 2)%8];

        //Rotate the 4th face
        temp.clear();
        for(int i=1; i<5; i++)
          temp.push_back(C.colours[face[4]][rot[i%4]]);
        for(int i=0; i<4; i++)
          C.colours[face[4]][rot[i]] = temp[i];
      }
      break;

    case 't':
      if(torque == 'c'){
        int face[] = {0,5,2,4,1}, sites[] = {0,1,0,1,3,2,0,1}, rot[] = {0,1,3,2};
        vector<char> temp;
        //Rotate the faces 0->1 first
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            temp.push_back(C.colours[face[i]][sites[i*2 + j]]);
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++){
            C.colours[face[i]][sites[i*2 + j]] = temp[(i*2 + j +6)%8];
          }

        //Rotate the 4th face
        temp.clear();
        for(int i=3; i<7; i++)
          temp.push_back(C.colours[face[4]][rot[i%4]]);
        for(int i=0; i<4; i++)
          C.colours[face[4]][rot[i]] = temp[i];
      }
      else{
        int face[] = {0,5,2,4,1}, sites[] = {0,1,0,1,3,2,0,1}, rot[] = {0,1,3,2};
        vector<char> temp;
        //Rotate the faces 0->3 first
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            temp.push_back(C.colours[face[i]][sites[i*2 + j]]);
        for(int i=0; i<4; i++)
          for(int j=0; j<2; j++)
            C.colours[face[i]][sites[i*2 + j]] = temp[(i*2 + j + 2)%8];

        //Rotate the 4th face
        temp.clear();
        for(int i=1; i<5; i++)
          temp.push_back(C.colours[face[4]][rot[i%4]]);
        for(int i=0; i<4; i++)
          C.colours[face[4]][rot[i]] = temp[i];
      }
      break;

    case 'b':
        if(torque == 'c'){
          int face[] = {1,5,3,4,2}, sites[] = {0,1,2,0,3,2,1,3}, rot[] = {0,1,3,2};
          vector<char> temp;
          //Rotate the faces 0->1 first
          for(int i=0; i<4; i++)
            for(int j=0; j<2; j++)
              temp.push_back(C.colours[face[i]][sites[i*2 + j]]);
          for(int i=0; i<4; i++)
            for(int j=0; j<2; j++){
              C.colours[face[i]][sites[i*2 + j]] = temp[(i*2 + j +6)%8];
            }

          //Rotate the 4th face
          temp.clear();
          for(int i=3; i<7; i++)
            temp.push_back(C.colours[face[4]][rot[i%4]]);
          for(int i=0; i<4; i++)
            C.colours[face[4]][rot[i]] = temp[i];
        }
        else{
          int face[] = {1,5,3,4,2}, sites[] = {0,1,2,0,3,2,1,3}, rot[] = {0,1,3,2};
          vector<char> temp;
          //Rotate the faces 0->3 first
          for(int i=0; i<4; i++)
            for(int j=0; j<2; j++)
              temp.push_back(C.colours[face[i]][sites[i*2 + j]]);
          for(int i=0; i<4; i++)
            for(int j=0; j<2; j++)
              C.colours[face[i]][sites[i*2 + j]] = temp[(i*2 + j + 2)%8];

          //Rotate the 4th face
          temp.clear();
          for(int i=1; i<5; i++)
            temp.push_back(C.colours[face[4]][rot[i%4]]);
          for(int i=0; i<4; i++)
            C.colours[face[4]][rot[i]] = temp[i];
        }
      break;
  }
  return C;
}

bool check_P(vector <string> P){
  bool oke = true;
  if((P[P.size()-1][0] == P[P.size()-2][0]) && (P[P.size()-1][1] != P[P.size()-2][1]))
    oke = false;
  if((P[P.size()-1][0] == P[P.size()-2][0]) && (P[P.size()-1][1] == P[P.size()-2][1])){
    if (P[P.size()-1][1] == 'a')
      oke = false;
  }
  return oke;
}

void solve_cube(cube C){
  string moves[]={"rc", "ra", "tc", "ta", "bc", "ba"};
  queue <cube> T; //cubes to visit
  queue <si> paths; // paths to all cubes to visit

  vector <string> P; //Path to cube

  T.push(C);
  paths.push(P);

  bool solved = false;
  int max_psize = 0;
  cout<<"Calculating Move No. 1"<<endl;

  //while not solved
  while(!solved){
    cube node = T.front(); //Store the front of the T queue
    P = paths.front();     // and the path to it.

    if (P.size() > max_psize){
      cout<<"Calculating Move No. "<<P.size() + 1<<endl;
      max_psize = P.size();
    }

    T.pop();  //pop them so that you don't check again
    paths.pop();
    for(int i=0; i<6; i++){  //go through all the moves
      cube n = move_cube(node, moves[i][0], moves[i][1]); //n is the cube after move[i]
      P.push_back(moves[i]);   //store the extra move in P

      if(solved_cube(n)){ // if it solves the cube
        for (int j=0; j<P.size(); j++) //print the path to it
          cout<<P[j]<<endl;
        solved = true; //solved is true (to break while loop)
        break;         //break for loop.
      }

      else { // if it doesn't
      //check if cube has been in T already (check c)
        if (check_P(P)){
          T.push(n);   //Store the cube in T with the path to it in P
          paths.push(P);
        }
        P.pop_back();  // Pop the last move from P, and go on.
      }
    }
  }
}

int main(){
  cube R;
  string c;
  cout<<endl<<"Please give the cube in the form of a string"<<endl<<"Explanation:"<<endl;
  cout<<"faces:"<<endl<<"5"<<endl<<"0 1 2 3"<<endl<<"4"<<endl;
  cout<<"Start facing face 0, having face 1 on the top. Face 1 follows with 2 on top etc."<<endl;
  cout<<"Continue until having face 0 again facing you. Next are faces 4 and 5, in that order, with face 1 on top."<<endl;
  cout<<"Give each face's colours in the following order, as you face it:"<<endl;
  cout<<"0 1"<<endl<<"2 3"<<endl;
  cout<<"e.g."<<endl<<"If face 1 has colours: "<<endl<<"w y"<<endl<<"y w"<<endl<<"The string will look like:"<<endl;
  cout<<"****wyyw****************"<<endl<<"String: ";
  cin>>c;
  cout<<"Solution is given as sequence of pairs of characters, representing the move sequence. Interpretation:"<<endl;
  cout<<"First character - r,t,b = right, top, back."<<endl;
  cout<<"Second character - a,c = anticlockwise, clockwise (when facing the 'moving' face)"<<endl;
  cout<<"Always hold cube with face 0 facing you."<<endl;

  fill_cube(R, c);
  solve_cube(R);
}
