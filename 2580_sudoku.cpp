#include <iostream>

using namespace std;

int sudoku[9][9] ={0,};
int row = 0;

bool isValid(int cnt, int row, int value){
  int i, j;

  for(i=0; i<9; i++){
    if(sudoku[row][i] == value){
      return false;
    }
  }

  for(i=0; i<9; i++){
    if(sudoku[i][cnt]==value){
      return false;
    }
  }

  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      if(sudoku[row/3 + i][cnt/3 + j] == value){
        return false;
      }
    }
  }

  return true;
}

void Print(){
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cout<<sudoku[i][j]<<" ";
    }
    cout<<"\n";
  }

  return;
}

void Solve(int cnt){
  if(cnt > 8){ 
    cnt = 0;
    row++;
  }

  for(int i=1; i<10; i++){

    while(sudoku[row][cnt] != 0 && cnt<9){
      cnt++;
      cout<<cnt<<" ";
    }
    if(isValid(cnt, row, i) && sudoku[row][cnt] == 0){
      sudoku[row][cnt] = i;
      Solve(cnt+1);
    }
  }
  cout<<cnt<<" "<<row<<"\n";
  if(row ==8 && cnt == 8){
    cout<<"hello\n";
    Print();
  }

}


int main(void){
  int i, j;

  for(i=0; i<9; i++){
    for(j=0; j<9; j++){
      cin>>sudoku[i][j];
    }
  }

  Solve(0);

  return 0;
}
