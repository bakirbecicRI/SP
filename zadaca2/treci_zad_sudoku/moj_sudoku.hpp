#include <vector>
#include <iostream>
#include <string>
#include <fstream>
class sudoku{
  public:
  sudoku(const std::string& file){
    board.resize(9, std::vector<int>(9,0));
    fixed.resize(9, std::vector<bool>(9, false));
    index.resize(9, std::vector<std::string>(9, " "));
    std::ifstream in(file);
    if (!in){
      std::cout<<"Citanje je neuspjelo!"<<std::endl;
      exit(1);
    }
    for (auto i=0; i<9; i++){
      for (auto j=0; j<9; j++){
          in>>board[i][j];
          if (board[i][j]!=0){
              fixed[i][j]=true;
          }
      }
    }
  }
  void printBoard(){
    std::cout<<"+----+-----+----+----+-----+----+"<<std::endl;

    for (auto i=0; i<9; i++){

      std::cout<<"| ";
      for (auto g=0; g<9; g++){
          if (g==2||g==5)
            std::cout<<index[i][g]<<" || ";
          else if(g==8) 
            std::cout<<index[i][g]<<" |";
          else {
            std::cout<<index[i][g]<<"  "; 
          }
      }
      std::cout<<std::endl;
      std::cout<<"| ";
      for (auto j=0; j<9; j++){
        
          if (j==2||j==5){
            std::cout<<board[i][j]<<" || ";
          }
          else if(j==8){
            std::cout<<board[i][j]<<" |";
          } 
          else {
          std::cout<<board[i][j]<<"  ";
          }
      }
      std::cout<<std::endl;
      if(i==2||i==5){
    std::cout<<"+----+-----+----+----+-----+----+"<<std::endl;
    std::cout<<"+----+-----+----+----+-----+----+"<<std::endl;
    }
      else if(i==8){
    std::cout<<"+----+-----+----+----+-----+----+"<<std::endl;
      }
    }

  }
    void board_input(int row, int column, int num){
      row=row-1;
      column=column-1;
      num=num-1;
      bool s=true;
      if (num+1==0){
          board[row][column]=0;
          fixed[row][column]=false;
          std::cout<<"Nulirana pozicija."<<std::endl;
      }
      else if (row<0 || row>8 || column<0 || column>8 || num<0 || num>8){
          std::cout<<"Nevalidan unos (unos od 1 do 9)."<<std::endl;
      }
      else if (fixed[row][column]==true){
        std::cout<<"Ne mozete mijenjati vec dodijeljen broj!"<<std::endl;
        s=false;
      }
      else {
      if ((row==0 || row==1 || row==2)&&(column==0 || column==1 || column==2)){
        for (auto i=0; i<3; i++){
          for (auto j=0; j<3; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u prvom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
      } 
      else if ((row==0 || row==1 || row==2)&&(column==3 || column==4 || column==5)){
      for (auto i=0; i<3; i++){
          for (auto j=3; j<6; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u drugom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
         
      } 
      else if ((row==0 || row==1 || row==2)&&(column==6 || column==7 || column==8)){
      for (auto i=0; i<3; i++){
          for (auto j=6; j<9; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u trecem kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==3 || row==4 || row==5)&&(column==0 || column==1 || column==2)){
      for (auto i=3; i<6; i++){
          for (auto j=0; j<3; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u cetvrtom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==3 || row==4 || row==5)&&(column==3 || column==4 || column==5)){
      for (auto i=3; i<6; i++){
          for (auto j=3; j<6; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u petom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==3 || row==4 || row==5)&&(column==6 || column==7 || column==8)){
      for (auto i=3; i<6; i++){
          for (auto j=6; j<9; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u sestom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==6 || row==7 || row==8)&&(column==0 || column==1 || column==2)){
      for (auto i=6; i<9; i++){
          for (auto j=0; j<3; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u sedmom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==6 || row==7 || row==8)&&(column==3 || column==4 || column==5)){
      for (auto i=6; i<9; i++){
          for (auto j=3; j<6; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u osmom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 
      else if ((row==6 || row==7 || row==8)&&(column==6 || column==7 || column==8)){
      for (auto i=6; i<9; i++){
          for (auto j=6; j<9; j++){
              if(board[i][j]==num+1){
                index[i][j]="*";
                std::cout<<"Konflikt u devetom kvadratu!"<<std::endl;
                s=false;
                break;
              }
          }
          if (!s) break;
        } 
                        
      } 

     for (auto i=0; i<9; i++){
           if(board[row][i]==num+1){
              index[row][i]="*";
              std::cout<<"Konflikt u redu!"<<std::endl;
              s=false;
              continue;
           }
     } 
     for (auto i=0; i<9; i++){
              if(board[i][column]==num+1){
                index[i][column]="*";
                std::cout<<"Konflikt u koloni!"<<std::endl;
                s=false;
                continue;
              }
            }
        if (s){
          board[row][column]=num+1;
          fixed[row][column]=true;
        }
      }
          printBoard();
    }
bool winnable(){
  bool s=1;
  for (auto i=0; i<9; i++){
      for (auto j=0; j<9; j++){
        if(board[i][j]==0)
          s=0;
      }
  }   
  if (s)
    return true;
  else {
    return false;
  }
 }
void index_clearing(){
    for (auto i=0; i<9; i++){
      for (auto j=0; j<9; j++){
        index[i][j]=" ";
      }
    }

}
  
  void play(){
    while (true){
      int row, column, num;
      std::cout<<"Sudoku: unesi red, kolonu, broj u formatu (red kolona broj), nula za brisanje polja,"<<std::endl;
      std::cout<<" za izlazak iz igre pritisnite -1, za brisanje markera upisite -2: "<<std::endl;
      std::cin>>row;
      if (row==-1)
        break;
      if(row==-2){
        index_clearing();
        printBoard();
        std::cout<<"Sudoku: unesi red, kolonu, broj u formatu (red kolona broj), nula za brisanje polja,"<<std::endl;
      std::cout<<" za izlazak iz igre pritisnite -1, za brisanje markera upisite -2: "<<std::endl;
      std::cin>>row;
      if (row==-1){
        break;
      }
      std::cin>>column>>num;
      board_input(row, column, num);
            if (winnable()){
            std::cout<<"Cestitam pobjedili ste sudoku!"<<std::endl;
            }
      }
      else {
      std::cin>>column>>num;
      board_input(row, column, num);
      if(winnable()){
          std::cout<<"Cestitam pobjedili ste sudoku!"<<std::endl;
          break;
      }
    }
  }   
  }      
        
  private:
  std::vector<std::vector<int>> board;
  std::vector<std::vector<bool>> fixed;
  std::vector<std::vector<std::string>> index;
};
