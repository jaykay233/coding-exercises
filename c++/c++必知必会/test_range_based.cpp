#include <vector>
#include <map>
#include <iostream>


class A
{
    public: 
        A()
        {}
        ~A() = default;

        A(const A& rhs){

        }
    public:   
        int m;
};

class ChatDialog{
public:  
    ChatDialog(){
       std::cout<<"ChatDialog constructor"<<std::endl;
    }

    ~ChatDialog(){
        std::cout<<"ChatDialog destructor"<<std::endl;
    }

    void activate(){
        std::cout<<"activated "<<std::endl;
    }
};

std::map<int64_t,ChatDialog*> m_ChatDialogs;

//普通写法
void onDoubleClickFriendItem(int64_t userId){
    auto targetChatDialog = m_ChatDialogs.find(userId);
    if(targetChatDialog == m_ChatDialogs.end()){
        ChatDialog* pChatDialog = new ChatDialog();
        m_ChatDialogs.insert(std::pair<int64_t,ChatDialog*>(userId,pChatDialog));
        pChatDialog->activate();
    }
    else{
        targetChatDialog->second->activate();
    }
}

void onDoubleClickFriendItem2(int64_t userId){
    auto [iter, inserted] = m_ChatDialogs.try_emplace(userId);
    if(inserted)
        iter->second = new ChatDialog();
    iter->second->activate();
}

int main(){
    A a1;
    A a2;
    std::vector<A> v;
    v.push_back(a1);
    v.push_back(a2);
    for(auto iter:v){
        iter.m = 9;
    }
    for(auto iter:v){
        std::cout<<iter.m<<std::endl;
    }

    onDoubleClickFriendItem2(13343435L);
    onDoubleClickFriendItem2(34354544L);
    onDoubleClickFriendItem2(13343435L);
    return 0;
}