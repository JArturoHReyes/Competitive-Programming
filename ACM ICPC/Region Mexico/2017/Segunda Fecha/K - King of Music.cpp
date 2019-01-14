#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1000005
using namespace std;

int n , k , w;

int arr[maxn];

vector < int > printKmin()
{
    deque < int > Qi(k);
    
    vector < int > ret;
    
    int i;
    
    for(i = 0; i < k; i++)
    {
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.front()])
        {
            Qi.pop_front();
        }
        
        Qi.push_front(i);
    }
    
    for( ; i < n; i++)
    {   
        ret.push_back(arr[Qi.back()]);
        
        while ( (!Qi.empty()) && Qi.front() <= i - k)
        {
            Qi.pop_back();
        }
        
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.front()])
        {
            Qi.pop_back();
        }
        
        Qi.push_front(i);
    }
    
    ret.push_back(arr[Qi.back()]);
    
    return ret;
}

// A Dequeue (Double ended queue) based method for printing maixmum element of 
// all subarrays of size k 
vector < int > printKMax() 
{ 
	// Create a Double Ended Queue, Qi that will store indexes of array elements 
	// The queue will store indexes of useful elements in every window and it will 
	// maintain decreasing order of values from front to rear in Qi, i.e., 
	// arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
	std::deque<int> Qi(k);
	
	vector < int > ret;

	/* Process first k (or first window) elements of array */
	int i; 
	for (i = 0; i < k; ++i) 
	{ 
		// For very element, the previous smaller elements are useless so 
		// remove them from Qi 
		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
			Qi.pop_back(); // Remove from rear 

		// Add new element at rear of queue 
		Qi.push_back(i); 
	} 

	// Process rest of the elements, i.e., from arr[k] to arr[n-1] 
	for ( ; i < n; ++i) 
	{ 
		// The element at the front of the queue is the largest element of 
		// previous window, so print it 
		//cout << arr[Qi.front()] << " ";
		
		ret.push_back(arr[Qi.front()]);

		// Remove the elements which are out of this window 
		while ( (!Qi.empty()) && Qi.front() <= i - k) 
			Qi.pop_front(); // Remove from front of queue 

		// Remove all elements smaller than the currently 
		// being added element (remove useless elements) 
		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
			Qi.pop_back(); 

		// Add current element at the rear of Qi 
		Qi.push_back(i); 
	} 

	// Print the maximum element of last window 
	//cout << arr[Qi.front()];
	ret.push_back(arr[Qi.front()]);
	
	return ret;
}

int main() 
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    while(cin >> n >> k >> w && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        vector < int > maxi = printKMax();
        
        vector < int > mini = printKmin();
        
        bool ok = true;
        
        for(int i = 0; i < maxi.size(); i++)
        {
            if(abs(mini[i] - maxi[i]) > w)
            {
                ok = false;
            }
        }
        
        if(ok)
        {
            cout << "Yes." << endl;
        }
        else
        {
            cout << "No." << endl;
        }
    }
	
	return 0; 
} 
