// https://practice.geeksforgeeks.org/problems/lru-cache/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class doublyLL {
	public:
    int key, value;
    doublyLL *prev, *next;

	public:
	doublyLL(int k, int v)
		:key(k), value(v), prev(NULL), next(NULL)
		{}

    static void add_to_head(doublyLL **headRef, doublyLL *node)
    {
        doublyLL *head = *headRef;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    static void remove_node_from_current_pos(doublyLL *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }

    static void delete_node(doublyLL *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};

class LRUCache
{
    private:
	unordered_map<int, doublyLL*> key_node_map;
	int capacity, count;
	doublyLL *head = NULL, *tail = NULL;


    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        count = 0;
        
        // Throw away nodes
        head = new doublyLL(INT_MIN, INT_MIN);
        tail = new doublyLL(INT_MAX, INT_MAX);
        head->next = tail;
        tail->prev = head;

        key_node_map[INT_MIN] = head;
        key_node_map[INT_MAX] = tail;

    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(key_node_map[key] != NULL) {
            doublyLL *node = key_node_map[key]; // Get the doubly linked list node address for the corresponding key
            int out_data = node->value;

            // Move the node to the front of doubly LL
            doublyLL::remove_node_from_current_pos(node);
            doublyLL::add_to_head(&head, node);

            return out_data;
        }
        else
            return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(key_node_map[key] != NULL) { // If key is already present
            // Update the existing data with new data
            doublyLL *node = key_node_map[key];
            node->value = value;

            // Move the node to front of doubly LL
            doublyLL::remove_node_from_current_pos(node);
            doublyLL::add_to_head(&head, node);
        }
        else { // Key is not present
            doublyLL *new_node = new doublyLL(key, value);
            key_node_map[key] = new_node;
            if(count < capacity) { // Doubly LL is not full, simply add node to head
                count += 1;
                doublyLL::add_to_head(&head, new_node);
            }
            else { // Doubly LL is full
                // Remove the least recently used data
                key_node_map.erase(tail->prev->key);
                doublyLL::delete_node(tail->prev);

                // Add a new node to head
                doublyLL::add_to_head(&head, new_node);
            }
        }

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