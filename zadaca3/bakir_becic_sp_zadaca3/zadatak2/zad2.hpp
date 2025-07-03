#pragma once
#include <iostream>
#include <list>
#include <string>

class BrowserHistory{
  public:
  void goback(){
    if (current==*(tabs.begin())){
      std::cout<<"----------------------------------"<<std::endl;
      std::cout<<"Cannot go backwards any more!"<<std::endl;
      std::cout<<"----------------------------------"<<std::endl;
    }
    else if (tabs.size()==1){
      std::cout<<"----------------------------------"<<std::endl;
      std::cout<<"Already at the beginning"<<std::endl;
      std::cout<<"----------------------------------"<<std::endl;
    }
    else if (tabs.empty()){
 std::cout<<"----------------------------------"<<std::endl;
 std::cout<<"Empty !"<<std::endl;
 std::cout<<"----------------------------------"<<std::endl;
    }
    else{
    auto temp=tabs.begin();
    for (auto it=tabs.begin(); it!=tabs.end(); it++){
      if (*it==current){
        temp=it;
      }
  }
    current=*(--temp);
    current_pos--;
  }
  }
  void add_new(){
  std::string val;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Input the value: ";
  std::cin>>val;
  std::cout<<"----------------------------------"<<std::endl;
  if (current_pos==tabs.size()-1){
  tabs.push_back(val);
  current=val;
  current_pos=tabs.size()-1;
  std::cout<<"Value '"<<val<<"' added. "<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  }
  if(current_pos!=tabs.size()-1) {
    std::list<std::string> new_tabs;
    for (auto it=tabs.begin(); it!=tabs.end(); it++){
      if (*it==current){
        new_tabs.push_back(*it);
        new_tabs.push_back(val);
        break;
      }
      else {
      new_tabs.push_back(*it);
      }
    }
    tabs.clear();
    std::swap(new_tabs,tabs);
   std::cout<<"Value '"<<val<<"' added. "<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  current=val;
  current_pos=tabs.size()-1;
 }
  }
  void print_current(){
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Current: "<<current<<"("<<current_pos<<")"<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  }
  void help(){
  std::cout<<"Options\n1. Go back\n2. Go forward\n3. Add new page\n4. Remove current page\n5. Remove using position\n6. Print current\n7. Print history\n8. Quit\n9. Print options"<<std::endl;
  }
  void history(){
    int i=0;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"History: "<<std::endl;
  for (auto it=tabs.begin(); it!=tabs.end(); it++){
    if (it==--(tabs.end()))
      std::cout<<*it<<"("<<i<<")"<<std::endl;
    else {
    std::cout<<*it<<"("<<i<<")->";
    }
    i++;
  }
  std::cout<<"----------------------------------"<<std::endl;
  }
  void remove_current(){
    auto curr_pos=0;
    for (auto it=tabs.begin(); it!=tabs.end();it++,++curr_pos){
        if(*it==current){
          auto to_erase=it;
          if (it!=tabs.begin()){
          --it;
          current=*it;
          }
          else {
          ++it;
          current=*it;
          }
          current_pos=curr_pos-1;
          tabs.erase(to_erase);
    }
  }
  }
  void goforward(){
    if (tabs.size()==1){
      std::cout<<"----------------------------------"<<std::endl;
      std::cout<<"Only one element"<<std::endl;
      std::cout<<"----------------------------------"<<std::endl;
    }
    if (tabs.empty()){
 std::cout<<"----------------------------------"<<std::endl;
 std::cout<<"Empty !"<<std::endl;
 std::cout<<"----------------------------------"<<std::endl;
    }
    else {
    auto temp=tabs.begin();
    for (auto it=tabs.begin(); it!=tabs.end(); it++){
      if (current==*it)
        temp=it;
    }
    if (temp==--(tabs.end())&&(tabs.size())>1){
  std::cout<<"----------------------------------"<<std::endl;
 std::cout<<"Already on last element !"<<std::endl;
 std::cout<<"----------------------------------"<<std::endl;
    }
    else {
    current=*(++temp);
    current_pos++;
    }
    }
  }
  void remove_pos(){
  int pos;
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Position: "<<std::endl;
  std::cin>>pos;
  std::cout<<"----------------------------------"<<std::endl;
  if (pos==0){
  std::cout<<"----------------------------------"<<std::endl;
  std::cout<<"Cannot remove first page"<<std::endl;
  std::cout<<"----------------------------------"<<std::endl;
  }
  else {
    auto position=tabs.begin();
    for (auto i=0; i<pos; i++){
      position++;
    }
    if (*position!=current){
  auto current_position=tabs.begin();
  for (auto i=tabs.begin(); i!=tabs.end(); i++){
    current_position++;
  }
  for (auto i=tabs.begin(); i!=current_position; i++){
    if (position==i)
      current_pos--;
  }
    tabs.erase(position);
  }
    else {
   current=*(--position);
   current_pos--;  
   tabs.erase(++position);   
    }       
  }
  }
  void play(){
    int x;
  std::cout<<"Options\n1. Go back\n2. Go forward\n3. Add new page\n4. Remove current page\n5. Remove using position\n6. Print current\n7. Print history\n8. Quit\n9. Print options"<<std::endl;
  while (true){
    std::cout<<"Pick an option: "<<std::endl;
  std::cin>>x;
  if(x==1){
  goback();
  }
  if(x==2){
  goforward();
  }
  if(x==4){
  remove_current();
  }
  if(x==3){
  add_new();
  }
  if(x==6){
  print_current();
  }
  if(x==8){
  std::cout<<"Closing..."<<std::endl;
  break;
  }
  if(x==7){
  history();
  }
  if(x==9){
  help();
  }
  if(x==5){
  remove_pos();
  }
  }    
  }
  private:
  std::list<std::string> tabs{"homepage"};
  std::string current="homepage";
  int current_pos=0;
};
