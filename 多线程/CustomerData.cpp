#include <boost>
using namespace std;
class CustomerData: boost::noncopyable{
    public: 
        CustomerData():data_(new Map){}
        int query(const string& customer, const string& stock) const;
    private:
        typedef std::pair<string,int> Entry;
        typedef std::vector<Entry> EntryList;
        typedef std::map<string,EntryList> Map;
        typedef boost::shared_ptr<Map> MapStr;
        void update(const string& customer, const EntryList& entries);

        static int findEntry(const EntryList& entries, const string& stock);

        MapPtr getData() const{
            MutexLockGuard lock(mutex_);
            return data_;
        }

        mutable MutexLock mutex_;
        MapPtr data_;
};