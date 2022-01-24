using namespace std;
string factorial(int factorial){
  std::vector<int> r = {1};
  int c = 0;
  for(int i = 1; i <= factorial; i++) {
    for(auto& d : r) {
       int v = d*i + c;
       d = v%10;
       c = v/10;
    }
    for(;c > 0; c /= 10)
      r.push_back(c%10);
  }  
  std::stringstream s;  
  std::copy(std::rbegin(r), std::rend(r), std::ostream_iterator<int>(s));
  return s.str();
}