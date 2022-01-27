#include <vector>
#include <iostream>
using namespace std;

class lift{
public:
  lift(const std::vector<std::vector<int>>& ques, int cap):queues(ques), capacity(cap){
    goup = true;
    int len = queues.size();
    ups = vector<vector<int>>(len);
    downs = vector<vector<int>>(len);
    for(int i = 0;i<len;i++){
      for(int j : queues[i]){
        if(j>i) {
            // cout<<"ups " << i << " add " << j <<endl; 
            ups[i].push_back(j);
        }
        else if(j<i) {
            // cout<<"downs " << i << " add " << j <<endl; 
            downs[i].push_back(j);
        }
      }
    }
  }
  vector<int> peoples;
  vector<vector<int>> ups;
  vector<vector<int>> downs;
  vector<vector<int>> queues;
  int capacity;
  bool goup;
};

void print(std::vector<int>& li){
    if(li.empty()){
        // cout<<"list empty"<<endl;
        return;
    }
    for(int i = 0;i<li.size();i++){
        if(i!=li.size()-1)
            cout<<li[i]<<" ";
        else 
            cout<<li[i];
    }
    cout<<endl;
}


std::vector<int> the_lift(const std::vector<std::vector<int>> &queues, int capacity) {
  lift eval(queues,capacity);
  vector<int> res = {0};
  int len = queues.size();
  while(1){
    bool canbreak = true;
    // cout<<len<<endl;
    for(int i = 0;i<len;i++){
      bool needstop = false;
      int level = eval.goup ? i : len-1-i;
    //   cout<<"people list level " << level << " ";
    //   print(eval.peoples);
    //   cout<<"up list level "<<level<<" ";
    //   print(eval.ups[i]);
    //   cout<<"down list level "<<level<<" ";
    //   print(eval.downs[i]);


      for(auto it = eval.peoples.begin();it!=eval.peoples.end();){
        if(*it == level){
        //   cout<<"level " << level << " people out need stop" << endl;
          needstop = true;
          it = eval.peoples.erase(it);
        }else{
          it++;
        }
      }

      
    //   cout<<"level: "<<level<<endl;
    //   print(eval.peoples);
    //   cout<<"need stop " << (needstop ? "yes" : "no") << endl;

      if(eval.goup && !eval.ups[level].empty()){
        needstop = true;
        // cout<<"level " << level << " up need stop" << endl;
        for(auto it = eval.ups[level].begin();it!=eval.ups[level].end() && eval.peoples.size() < eval.capacity;){
          eval.peoples.push_back(*it);
          it = eval.ups[level].erase(it);
        }
      }
      else if(!eval.goup && !eval.downs[level].empty()){
        needstop = true;
        // cout<<"level " << level << " down need stop" << endl;
        for(auto it = eval.downs[level].begin();it!=eval.downs[level].end() && eval.peoples.size() < eval.capacity;){
          eval.peoples.push_back(*it);
          it = eval.downs[level].erase(it);
        }
      }
      
      if(needstop){
        // cout<<"level " << level << " finally stop" << endl;
        if(res.size()==1 && level==0)
            continue;
        if(!res.empty() && level != res.back())
            res.push_back(level);
      }
      
    }
    eval.goup = !eval.goup;
    if(!eval.peoples.empty())
        canbreak = true;
    for(int i = 0;i<queues.size();i++){
        if(!eval.ups[i].empty() || !eval.downs[i].empty())
            canbreak = false;
    }
    if(canbreak){
        // cout<<" break "<<endl;
        break;
    }
  }
  if(!res.empty() && res.back()!=0)
    res.push_back(0);
  return res;
}


int main(){
    vector<vector<int>> queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
    vector<int> result = the_lift(queues,5);
    print(result);
}