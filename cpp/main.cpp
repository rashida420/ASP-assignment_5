#include <iostream>
#include <vector>
#include<cstdio>
using namespace std;
int mv=1;

int game(vector<int> arr){
    if(arr.size()==1){
        return arr[0];
    }
    vector<int> next_arr;
    for(int i=0; i<arr.size(); i++){
        if(mv==1 && i%2 ==0){
            next_arr.push_back(arr[i]);
        }
        else if (mv==2 && i%2 ==1){
            next_arr.push_back(arr[i]);
        }
        else if (mv==3 && (i+1) % 3 != 0){
            next_arr.push_back(arr[i]);
        }
    }
    mv = mv % 3 +1;
    return game(next_arr);

}

int main(){
    int n;
    vector<int> arr;

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        arr.push_back(i);
    }
    printf("%d", game(arr));

    return 0;


}
