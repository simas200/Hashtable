#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

struct record{
    void* key;
    void* value;
    unsigned char occupied;
};

struct sim_hash* sim_hash_initialize(int key_size, int val_size){
    struct sim_hash* hash = (struct sim_hash*)malloc(sizeof(struct sim_hash));
    hash->size = 8;
    hash->full = 0;
    hash->key_size = key_size;
    hash->val_size = val_size;
    hash->records = (struct record**)malloc(sizeof(struct record) * hash->size);
    int i;
    for(i = 0; i < 8; i++){
        struct record* rec = (struct record*)malloc(key_size + val_size + sizeof(int));
        rec->key = NULL;
        rec->value = NULL;
        rec->occupied = 0;
        hash->records[i] = rec;
    }
    return hash;
}

int sim_hash_dispoze(struct sim_hash* hash){
    int i;
    for(i = 0; i < hash->size; i++){
        free(hash->records[i]);
    }
    free(hash);
    return 0;
}

int sim_hash_hash(int size, void* key){
    char local_key[size];
    memcpy(local_key, key, size);
    int sum = 0;
    int i;
    for(i = 0; i < size; i++){
        sum += local_key[i];
    }
    return sum/size;
}

int sim_hash_findSlot(struct sim_hash* hash, void* key){
    char local_key[hash->key_size];
    memcpy(local_key, key, hash->key_size); 
    int i = sim_hash_hash(hash->key_size, key);
    while ((hash->records[i]->occupied == 0) && ((char*)hash->records[i]->key == local_key)){
        i = (i + 1) % hash->size;
    }
    return i;
}

int sim_hash_rebuild(struct sim_hash* hash, int new_size){
    //TODO: implement
}

void* sim_hash_lookup(struct sim_hash* hash, void* key){
    int i = sim_hash_findSlot(hash, key);
    if(hash->records[i]->occupied){
        return hash->records[i]->value;
    }
    return NULL;
}

int sim_hash_set(struct sim_hash* hash, void* key, void* value){
    int i = sim_hash_findSlot(hash, key);
    if(hash->records[i]->occupied){
        hash->records[i]->value = value;
        return 1;
    }
    hash->records[i]->occupied = 1;
    hash->records[i]->key = key;
    hash->records[i]->value = value;
    hash->full++;
    return 1;
}

int sim_hash_remove(struct sim_hash* hash, void* key){
    //TODO: implement
    return 0;
}