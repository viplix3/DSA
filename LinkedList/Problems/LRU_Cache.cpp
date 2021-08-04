// https://practice.geeksforgeeks.org/problems/lru-cache/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class doublyLL {
	protected:
	int key, value;
	doublyLL *prev = NULL, *next = NULL;

	public:
	doublyLL(int k, int v)
		:key(k), value(v)
		{}
}

class LRUCache : private doublyLL
{
    private:
	unordered_map<int, doublyLL*> key_node_map;
	int capacity, count;
	doublyLL *head, *tail;


    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
		:capacity(cap)
		{}
    
    //Function to return value corresponding to the key.
    static int get(int key)
    {
		auto hash_itr = key_node_map.find(key);
		
		if(hash_itr == key_node_map.end())
			return -1;
		
		doublyLL *node = key_node_map[key];
		return node->value;
    }
    
    //Function for storing key-value pair.
    static void set(int key, int value)
    {
        // your code here   
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends