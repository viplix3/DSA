#include<bits/stdc++.h>
using namespace std;

struct hashTable
{
    int BUCKET;
    list<int> *table;

    hashTable(int size){
        BUCKET = size;
        table = new list<int> [size];
    }

    void table_insert(int key){
        int hash = key % BUCKET;
        table[hash].push_back(key);
    }

    void table_delete(int key){
        int hash = key % BUCKET;
        table[hash].remove(key);
    }

    bool search(int key){
        int hash = key % BUCKET;
        for(auto x: table[hash])
            if(x == key)
                return true;
        return false;
    }

    void printHashTableInfo(){
        printf("\n\n======== HASH TABLE ========");
        printf("\n======== Hash\t Key ========");
        for(int hash=0; hash < BUCKET; hash++){
            printf("\n          %d\t  ", hash);
            bool chaining = false;
            for(auto x: table[hash]){
                if(chaining){
                    printf(" -> %d", x);
                }
                else{
                    printf("%d", x);
                    chaining = true;
                }
            }
        }
        printf("\n======== HASH TABLE ========\n");
    }
};

int main(){
    int hashTableSize, numQueries;
    int user_choice, key;

    printf("Enter hash table size: ");
    scanf("%d", &hashTableSize);

    hashTable customHashTable{hashTableSize};

    do{
        printf("\n========== Custom Hash-Table Menu ==========\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\nEnter your choice: ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            printf("Enter key to be inserted: ");
            scanf("%d", &key);
            if(customHashTable.search(key) == true)
                printf("Key already presenting in the hash table, aborting insert");
            else{
                customHashTable.table_insert(key);
                printf("Key inserted");
            }
            customHashTable.printHashTableInfo();
            break;
        
        case 2:
            printf("Enter key to be deleted: ");
            scanf("%d", &key);
            if(customHashTable.search(key) == false)
                printf("Key not present in the hash table, aborting delete");
            else{
                customHashTable.table_delete(key);
                printf("Key deleted");
            }
            customHashTable.printHashTableInfo();
            break;
        
        case 3:
            printf("Enter key to be searched for: ");
            scanf("%d", &key);
            bool search_result;
            search_result = customHashTable.search(key);
            if(search_result)
                printf("Key is present in the hash table");
            else
                printf("Key is not present in the hash table");
            customHashTable.printHashTableInfo();
            break;
        
        case 4:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

    }while(user_choice != 4);


    return 0;
}