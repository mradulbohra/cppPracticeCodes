#include<bits/stdc++.h>

using namespace std;

pair<int, int> getMiniMax(int arr[], int left, int right)
{

    pair<int, int> answer, left_answer, right_answer;
    int mid;

    if(left==right)
    {
        answer.first = arr[left];
        answer.second = arr[right];
        return answer;
    }

    if(left+1==right)
    {
        if(arr[left]>arr[right])
            answer.first = arr[right], answer.second = arr[left];
        else answer.first = arr[left], answer.second = arr[right];

        return answer;
    }

    mid = (left+right)/2;
    left_answer = getMiniMax(arr, left, mid);
    right_answer = getMiniMax(arr, mid+1, right);

    if(left_answer.first<right_answer.first)
        answer.first = left_answer.first;
    else answer.first = right_answer.first;

    if(left_answer.second>right_answer.second)
        answer.second = left_answer.second;
    else answer.second = right_answer.second;

    return answer;

}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    pair<int, int> minimax = getMiniMax(arr, 0, n-1);
    cout<<minimax.first<<" "<<minimax.second<<endl;

    return 0;
}
