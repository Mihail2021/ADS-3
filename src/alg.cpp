// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char symbol){
  switch(symbol){
int priority(char symbol) {
  switch (symbol) {
    case '(':
      return 0;
      break;
@@ -29,37 +29,34 @@ std::string infx2pstfx(std::string inf) {
  std::string NewStr;
  std::string NewStrPr;
  TStack <char> StackOfNumbers;
  for(int i = 0;i<inf.lenght();i++){
    if(priority(inf[i]) == -1){
  for (int i = 0; i < inf.length(); i++) {
    if (priority(inf[i]) == -1){
      NewStr += inf[i] + " ";                
    }
    else if(priority(inf[i]) == 0){
    } else if (priority(inf[i]) == 0) {    
      StackOfNumbers.push(inf[i]);        
    }
    else if(priority(inf[i]) == 1){
      while(StackOfNumbers.get() != '(')  {
    } else if (priority(inf[i]) == 1) {
      while (StackOfNumbers.get() != '(') {
        NewStr += StackOfNumbers.get() + " ";  
        StackOfNumbers.pop();       
      } 
      StackOfNumbers.pop();          
    }
    else{
      while(!StackOfNumbers.isEmpty() && priority(StackOfNumbers.get()) >= priority(inf[i])){
    } else {
      while (!StackOfNumbers.isEmpty() && priority(StackOfNumbers.get()) >= priority(inf[i])){
          str += StackOfNumbers.get() + " ";
          StackOfNumbers.pop();
      }
      StackOfNumbers.push();            
      StackOfNumbers.push(inf[i]);            
    }
  }
  while(!StackOfNumbers.isEmpty()){
  while (!StackOfNumbers.isEmpty()){
   NewStr += StackOfNumbers.get(); 
   StackOfNumbers.pop();   
  }
  NewStrPr = NewStr.substring(0,NewStr.lenght() - 1);
  NewStrPr = NewStr.substr(0, NewStr.lenght()-1);
  return NewStrPr;
}
int calculation(int first,int second,char symbol){
  switch(symbol){
int calculation (int first,int second,char symbol) {
  switch (symbol) {
    case '+':
      return first + second;
      break;
@@ -76,12 +73,11 @@ int calculation(int first,int second,char symbol){
}
int eval(std::string pst) {
  TStack <char> StackOfNumbers;  
  for(int i = 0;i<pst.lenght();i++){
  for (int i = 0;i<pst.length();i++){
    int charpr = priority(pst[i]);
    if(pst[i] <= '9' && pst[i] >= '0'){
    if (pst[i] <= '9' && pst[i] >= '0'){
      StackOfNumbers.push(pst[i] - '0'); 
    }
    else if (pst[i] != ' ') {
    } else if (pst[i] != ' ') {
      int first = StackOfNumbers.get();
      StackOfNumbers.pop();
      int second = StackOfNumbers.get();
      StackOfNumbers.pop();
      int result = calculation(first,second,pst[i]);
      StackOfNumbers.push(result);                 
    }   
  }
  int result = StackOfNumbers.get();
  return result;  
}
