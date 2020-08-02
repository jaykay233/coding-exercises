#include <cstdio>
#include <cstdlib>


void maxheapify(vector<int>& array,int index){
	int len = array.size();
	int ileft,iright,iMax;
	while(true){
		iMax = index;
		ileft = index*2+1;
		iright = (index+1)*2;
		if(ileft<len && array[ileft]<array[index]){
			iMax = ileft;
		}

		if(iright<len && array[iright]<array[index]){
			iMax = iright;
		}

		if(iMax!=index){
			swap(array[iMax],array[index]);
			index = iMax;
		}else{
			break;
		}
	}
}


void buildMaxHeap(vector<int>& array){
	int len = array.size();
	int i,iParent = int(len/2)-1;
	for(i=iParent;i>=0;i--){
		maxheapify(array,i);
	}
}

void sort(vector<int>& array){
	buildMaxHeap(array);
	vector<int> res;
	for(int i=array.size()-1;i>=0;i--){
		res.push_back(array[0]);
		swap(array[0],array[i]);
		array.pop_back();
	}
	reverse(res.begin(),res.end());
}


int main(){
	vector<int> array;
	sort(array);
}