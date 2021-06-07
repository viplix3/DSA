#include<bits/stdc++.h>
using namespace std;

struct hashTable
{
    int BUCKET;
    int hash_size;
    int *table;
    
    hashTable(int size){
        BUCKET = size;
        hash_size = 0;
        table = new int[size];

        for(int i=0; i<BUCKET; i++)
            table[i] = -1;
    }

    int hash(int key){
        return key % BUCKET;
    }

    int double_hash(int key, int iter){
        int first_hash = hash(key);
        int second_hash = (BUCKET-1) - (key % (BUCKET-1));
        int double_hash = (first_hash + iter*(second_hash)) % BUCKET;
        return double_hash;
    }

    void table_insert(int key){
        if(hash_size == BUCKET){
            printf("No empty slot in the hash table, aborting insert");
            return;
        }
        int __hash__ = hash(key); // First hash
        int prob_hash = __hash__;
        int clash = 1;

        while((table[prob_hash] != -1) && (table[prob_hash] != -2)){
            prob_hash = double_hash(key, clash);
            clash++;
        }
        table[prob_hash] = key;
        hash_size += 1;
    }

    void table_delete(int key){
        int __hash__ = hash(key);
        int prob_hash = __hash__;
        int clash = 1;

        while((table[prob_hash] != key)){
            prob_hash = double_hash(key, clash);
            clash++;
        }

        table[prob_hash] = -2;
        hash_size--;
    }

    bool search(int key){
        int __hash__ = hash(key);
        int prob_hash = __hash__;
        int clash = 1;

        while(table[prob_hash] != -1){
            if(table[prob_hash] == key)
                return true;

            prob_hash = double_hash(key, clash);
            clash++;

            if(prob_hash == __hash__)
                return false;
        }
        return false;
    }

    void printHashTableInfo(){
        printf("\n\n======== HASH TABLE ========");
        printf("\n======== Hash\t Key ========");
        for(int hash=0; hash < BUCKET; hash++){
            if(table[hash] != -1 && table[hash] != -2){
                printf("\n          %d\t  ", hash);
                printf("%d", table[hash]);
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